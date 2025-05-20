//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function Prototypes
float computeBill(int choice, int quantity);
void displayMenu();
void displayThanks();

int main()
{
    // Variables
    int option = 0, count = 0, quantity = 0;
    float price = 0, bill = 0;
    bool valid = false;

    // Display Menu
    displayMenu();

    // Select Options
    while (!valid)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        if (option < 1 || option > 5)
        {
            printf("\nInvalid choice. Please try again.\n");
        }
        else
        {
            switch (option)
            {
            case 1:
                price = 2.5;
                break;
            case 2:
                price = 3.0;
                break;
            case 3:
                price = 2.0;
                break;
            case 4:
                price = 1.5;
                break;
            case 5:
                exit(0);
            }
            valid = true;
        }
    }

    // Select Quantity
    valid = false;
    while (!valid)
    {
        printf("\nEnter quantity: ");
        scanf("%d", &quantity);
        if (quantity < 1)
        {
            printf("\nInvalid quantity. Please try again.\n");
        }
        else
        {
            valid = true;
        }
    }

    // Calculate Bill
    bill = computeBill(option, quantity);

    // Display Bill
    printf("\nYour total bill is $%.2f\n", bill);
    displayThanks();

    return 0;
}

float computeBill(int choice, int quantity)
{
    float price = 0, bill = 0;

    switch (choice)
    {
    case 1:
        price = 2.5;
        break;
    case 2:
        price = 3.0;
        break;
    case 3:
        price = 2.0;
        break;
    case 4:
        price = 1.5;
        break;
    }

    // Recursive computation
    if (quantity == 1)
    {
        bill = price;
    }
    else
    {
        bill = price + computeBill(choice, quantity - 1);
    }

    return bill;
}

void displayMenu()
{
    printf("Welcome to C Cafe!\n\n");
    printf("Menu\n");
    printf("1. Coffee         $2.50\n");
    printf("2. Tea            $3.00\n");
    printf("3. Hot Chocolate  $2.00\n");
    printf("4. Milk           $1.50\n");
    printf("5. Quit\n");
}

void displayThanks()
{
    printf("\nThank you for dining at C Cafe. Have a nice day!\n");
}