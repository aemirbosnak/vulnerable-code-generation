//FormAI DATASET v1.0 Category: Hotel Management System ; Style: irregular
//WELCOME MESSAGE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char username[20];
    char password[20];
    int choice;

    printf("**************************************************************\n");
    printf("********************** HOTEL MANAGEMENT ***********************\n");
    printf("**************************************************************\n\n");

    printf("        Please enter your username and password to continue.\n\n");

    printf("          Username: ");
    fgets(username, 20, stdin);
    printf("          Password: ");
    fgets(password, 20, stdin);

//CHECK USERNAME AND PASSWORD
    if (strcmp(username, "admin\n") == 0 && strcmp(password, "password\n") == 0) 
    {
        printf("\nWelcome Admin!\n\n");

//MENU FOR ADMIN
        do
        {
            printf("       HOTEL MANAGEMENT MENU:\n\n");
            printf("1) Add Customer\n");
            printf("2) Remove Customer\n");
            printf("3) View Customers\n");
            printf("4) Exit\n\n");

            printf("Enter your choice: ");
            scanf("%d", &choice);

//ADD CUSTOMER        
            if (choice == 1) 
            {
                char name[20];
                int room_num;

                printf("\n Enter Name of Customer: ");
                scanf("%s", name);
                printf("Enter Room Number: ");
                scanf("%d", &room_num);

                printf("\n Customer Added Successfully!\n\n");
            }

//REMOVE CUSTOMER
            else if (choice == 2) 
            {
                int room_num;

                printf("\n Enter the room number of the customer to remove: ");
                scanf("%d", &room_num);

                printf("\n Customer Removed Successfully!\n\n");
            }

//VIEW CUSTOMERS
            else if (choice == 3) 
            {
                printf("\n List of Current Customers\n\n");
                printf("     Name         | Room Number \n");
                printf("------------------|-------------\n");
                printf("     John Smith   |      101    \n");
                printf("     Lisa Kudrow  |      102    \n\n");
            }
            
        } while (choice != 4);

        printf("\n      Thank you for using the Hotel Management System!\n\n");

    }
    else 
    {
        printf("\n Invalid Username or Password. Access Denied!\n\n");
    }

    return 0;
}