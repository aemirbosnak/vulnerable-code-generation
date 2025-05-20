//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
/*
* C Cafe Billing System
*
* This program allows customers to order items from a cafe menu and
* generates a bill based on their selection.
*/

#include <stdio.h>
#include <stdlib.h>

// Define menu items
typedef struct {
    char name[20];
    float price;
} MenuItem;

MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Cappuccino", 3.50},
    {"Latte", 4.00},
    {"Mocha", 4.50},
    {"Espresso", 3.00}
};

// Define functions
void printMenu();
void takeOrder();
void generateBill();

int main() {
    // Print menu
    printMenu();

    // Take order
    takeOrder();

    // Generate bill
    generateBill();

    return 0;
}

// Function to print menu
void printMenu() {
    printf("Welcome to our cafe!\n");
    printf("Our menu is as follows:\n");

    for (int i = 0; i < sizeof(menu) / sizeof(MenuItem); i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to take order
void takeOrder() {
    int itemCount = 0;
    float totalPrice = 0.0;
    char choice;

    printf("Please enter your order (e.g. 1,2,3): ");
    scanf("%s", &choice);

    while (choice != '\0') {
        // Check if choice is a valid menu item
        int itemIndex = choice - '0';
        if (itemIndex > 0 && itemIndex <= sizeof(menu) / sizeof(MenuItem)) {
            // Add item to order
            totalPrice += menu[itemIndex - 1].price;
            itemCount++;
        }

        // Get next choice
        printf("Please enter your next order (e.g. 1,2,3): ");
        scanf("%s", &choice);
    }

    printf("You have ordered %d items for a total of $%.2f\n", itemCount, totalPrice);
}

// Function to generate bill
void generateBill() {
    float totalPrice = 0.0;
    char choice;

    printf("Please enter your order (e.g. 1,2,3): ");
    scanf("%s", &choice);

    while (choice != '\0') {
        // Check if choice is a valid menu item
        int itemIndex = choice - '0';
        if (itemIndex > 0 && itemIndex <= sizeof(menu) / sizeof(MenuItem)) {
            // Add item to order
            totalPrice += menu[itemIndex - 1].price;
        }

        // Get next choice
        printf("Please enter your next order (e.g. 1,2,3): ");
        scanf("%s", &choice);
    }

    printf("Your total is $%.2f\n", totalPrice);
}