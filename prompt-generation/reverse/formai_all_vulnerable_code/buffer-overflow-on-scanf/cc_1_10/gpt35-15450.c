//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define global variables
int numItems = 0;
float totalCost = 0;

//define struct for items in menu
typedef struct
{
    char name[50];
    float price;
} MenuItem;

//define menu items
MenuItem menu[] = {{"Cappuccino", 4.50},
                   {"Latte", 3.75},
                   {"Espresso", 2.50},
                   {"Iced Coffee", 3.25},
                   {"Hot Chocolate", 4.00}};

//function to display menu
void displayMenu()
{
    printf("---------------------------------\n");
    printf("             MENU\n");
    printf("---------------------------------\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d. %-20s $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("---------------------------------\n");
}

//function to add item to bill
void addItem(int itemNum)
{
    if (itemNum < 1 || itemNum > 5)
    {
        printf("Invalid menu item number.\n");
        return;
    }

    printf("Adding %s to the bill.\n", menu[itemNum - 1].name);
    totalCost += menu[itemNum - 1].price;
    numItems++;
}

//function to generate bill
void generateBill()
{
    printf("Total items: %d\n", numItems);
    printf("Total cost: $%.2f\n", totalCost);
}

//main function
int main()
{
    int choice;

    printf("Welcome to the C Cafe!\n");

    while (1)
    {
        printf("Please choose an option:\n");
        printf("1. Display menu\n2. Add item to bill\n3. Generate bill\n4. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayMenu();
            break;

        case 2:
            printf("Enter the menu item number you want to add: ");
            scanf("%d", &choice);
            addItem(choice);
            break;

        case 3:
            generateBill();
            break;

        case 4:
            printf("Thank you for choosing the C Cafe!\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}