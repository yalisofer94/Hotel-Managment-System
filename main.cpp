#include <iostream>
#include <sqlite3.h>
#include <string>
#include "Customer.h"
#include "Employee.h"
#include "Manager.h"
using namespace std;

void bookRoom(Employee *e)
{
    string n, em, p, sDate, eDate;
    cout << "Please enter the client details - " << endl;
    cout << "Name - ";
    fflush(stdin);
    getline(cin, n);
    cout << "Email - ";
    cin >> em;
    cout << "Phone - ";
    cin >> p;
    cout << " Start date in format yyyy-mm-dd ";
    cin >> sDate;
    cout << " End date in format yyyy-mm-dd ";
    cin >> eDate;
    Customer *c = new Customer(n,em,p);
    e->isCustomerExist(c); // if its not exist - creates new customer in db else does nothing
    // bool isPossible = e->bookRoom();
    // if(!isPossible) { cout << "Sorry but a room in the class that you wished for does not exist... would you like to change the dates? "; }


    // 1 - enter customer details + order details[dates, that type of room]
    // 2 - check if customer already exist ? continue : create Customer 
    // 3 - check availability of the room
    // 4 - if there is a free room ? book the room : ask for different dates/ other class of room and goto 3
}

void checkIn()
{
    int userInput;
    cout << "Please enter the room number - ";
    cin >> userInput;
    Manager *e = new Manager(1234, "ido");
    e->checkIn(userInput);
}

void checkOut()
{
    int userInput;
    cout << "Please enter the room number - ";
    cin >> userInput;
    Manager *e = new Manager(1234, "ido");
    e->checkOut(userInput);
}

void watchAvbRooms(Employee *e)
{
     e->watchAvbRooms();
}

void Updateprice(Manager *e)
{
    char cls;
    int amount;
    cout << "What is the room class you want the price to change? ";
    cin >> cls;
    cout << "What is the new amount you want to change ?";
    cin >> amount;
    e->priceUpdater(cls, amount);
}

void menu()
{
    string pass;
    int userInput;
    cout << "================ Welcome To Hotel California ================" << endl;
    cout << "if you are a manager enter password, else press *> ";
    cin >> pass;
    Manager *e = new Manager(1234, "ido");

    if (pass == "123")
    {
        cout << "1 - Book a room" << endl;
        cout << "2 - Check-in room" << endl;
        cout << "3 - Check-out room" << endl;
        cout << "4 - Watch available rooms" << endl;
        cout << "5 - Get financial report" << endl;
        cout << "6 - Update prices" << endl;
        cout << "0 - Exit" << endl;
    }
    else
    {
        cout << "Hello!\nWhat would you like to do? " << endl;
        cout << "1- Book a room" << endl;
        cout << "2 - Check-in room" << endl;
        cout << "3 - Check-out room " << endl;
        cout << "4 - Watch available rooms" << endl;
        cout << "0 - Exit" << endl;
    }
    cin >> userInput;
    switch (userInput)
    {
    case 1:
        bookRoom(e);
        break;
    case 2:
        checkIn();
        break;
    case 3:
        checkOut();
    case 4:
        watchAvbRooms(e);
        break;
    case 5:
        Updateprice(e);    
    default:
        break;
    }

};

int main(void)
{
    menu();
    return 0;
}