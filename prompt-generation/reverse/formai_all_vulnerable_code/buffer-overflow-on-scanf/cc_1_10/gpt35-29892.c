//FormAI DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function declarations
void login();
void menu();
void chargetest();
void checkout();

//Global variables
int roomno, days;
char choice, ch;
double room_charge, total;

int main()
{
    printf("\n\t********** Welcome to C Hotel Management System **********\n\n");
    printf("Please enter your choice:\n");
    printf("1. Login\n");
    printf("2. Exit\n");

    scanf("%c", &choice);

    switch(choice)
    {
        case '1':
            login();
            break;
        case '2':
            printf("Thank you for using C Hotel Management System.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
            main();
    }

    return 0;
}

void login()
{
    char username[50];
    char password[50];

    printf("\nEnter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    if(strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
    {
        printf("\nLogin successful!\n");
        system("pause");
        system("cls");
        menu();
    }
    else
    {
        printf("\nLogin failed! Please try again.\n");
        login();
    }
}

void menu()
{
    printf("\n\t********** C Hotel Management System Menu **********\n\n");
    printf("Please enter your choice:\n");
    printf("1. Check room charge\n");
    printf("2. Check out\n");
    printf("3. Back to main menu\n");

    scanf(" %c", &choice);

    switch(choice)
    {
        case '1':
            chargetest();
            break;
        case '2':
            checkout();
            break;
        case '3':
            system("cls");
            main();
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            menu();
    }
}

void chargetest()
{
    printf("\nEnter the room number: ");
    scanf("%d", &roomno);
    printf("\nEnter the number of days stayed: ");
    scanf("%d", &days);

    switch(roomno)
    {
        case 101:
            room_charge = 50.0;
            break;
        case 102:
            room_charge = 60.0;
            break;
        case 103:
            room_charge = 70.0;
            break;
        default:
            printf("Invalid room number! Please try again.\n");
            chargetest();         
    }

    total = room_charge * days;
    printf("\nTotal room charge for room %d for %d days is $%.2lf\n", roomno, days, total);
    printf("Press any key to go back to menu.\n");

    ch = getchar();
    ch = getchar();
    system("cls");
    menu();
}

void checkout()
{
    printf("\nEnter the room number: ");
    scanf("%d", &roomno);
    printf("\nEnter the number of days stayed: ");
    scanf("%d", &days);

    switch(roomno)
    {
        case 101:
            room_charge = 50.0;
            break;
        case 102:
            room_charge = 60.0;
            break;
        case 103:
            room_charge = 70.0;
            break;
        default:
            printf("Invalid room number! Please try again.\n");
            checkout();         
    }

    total = room_charge * days;
    printf("\nThe total bill for room %d for %d days is $%.2lf\n", roomno, days, total);
    printf("\nThank you for using C Hotel Management System.\n");

    exit(0);
}