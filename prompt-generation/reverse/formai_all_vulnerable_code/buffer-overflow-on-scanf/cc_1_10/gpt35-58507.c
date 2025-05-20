//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Global Variables
int bill_amount = 0;
int table_number = 0;
char customer_name[50];

// Functions
void display_menu(); // Displays menu
int billing(); // Calculates and returns bill amount

int main() {
    printf("Welcome to the C Cafe Billing System!\n");

    // Getting Customer Information
    printf("Please enter your name: ");
    fgets(customer_name, 50, stdin);
    printf("Please enter your table number: ");
    scanf("%d", &table_number);

    // Displaying Menu
    display_menu();

    // Billing
    bill_amount = billing();
    printf("Your total bill amount is: %d\n", bill_amount);

    printf("Thank you for visiting C Cafe! Have a nice day!\n");

    return 0;
}

void display_menu() {
    printf("------------------------------\n");
    printf("|  Item           |   Price  |\n");
    printf("------------------------------\n");
    printf("|  Coffee         |    50    |\n");
    printf("|  Tea            |    30    |\n");
    printf("|  Sandwich       |   120    |\n");
    printf("|  Burger         |   150    |\n");
    printf("|  French Fries   |    80    |\n");
    printf("|  Milkshake      |   100    |\n");
    printf("------------------------------\n");
}

int billing() {
    int total = 0;
    int item_price = 0;
    int item_quantity = 0;
    char choice;

    do {
        printf("Please enter the item name: ");
        char item_name[20];
        scanf("%s", item_name);

        printf("Please enter the item price: ");
        scanf("%d", &item_price);

        printf("Please enter the item quantity: ");
        scanf("%d", &item_quantity);

        total += item_price * item_quantity;

        printf("Would you like to order another item? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return total;
}