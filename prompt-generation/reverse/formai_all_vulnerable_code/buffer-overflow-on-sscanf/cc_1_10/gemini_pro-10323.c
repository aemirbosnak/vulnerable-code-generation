//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
typedef struct {
    char *name;
    float price;
} MenuItem;

MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Soda", 1.50},
    {"Water", 1.00},
    {"Muffin", 3.00},
    {"Scone", 3.50},
    {"Cookie", 2.00},
};

// Define the maximum number of menu items that can be ordered
#define MAX_MENU_ITEMS 10

// Define the maximum length of a menu item name
#define MAX_MENU_ITEM_NAME_LENGTH 30

// Define the maximum number of characters in a line of input
#define MAX_INPUT_LINE_LENGTH 100

// Function to print the menu
void printMenu() {
    printf("Menu:\n");
    for (int i = 0; i < sizeof(menu) / sizeof(MenuItem); i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to get the user's order
int getOrder(char *items[], float prices[], int *numItems) {
    char input[MAX_INPUT_LINE_LENGTH];
    int itemNumber, quantity;
    float totalPrice = 0.0;

    // Get the number of items ordered
    printf("How many items would you like to order? ");
    fgets(input, MAX_INPUT_LINE_LENGTH, stdin);
    sscanf(input, "%d", numItems);

    // Get the items ordered and their quantities
    for (int i = 0; i < *numItems; i++) {
        printf("Enter the item number and quantity (e.g., 1 2): ");
        fgets(input, MAX_INPUT_LINE_LENGTH, stdin);
        sscanf(input, "%d %d", &itemNumber, &quantity);

        // Check if the item number is valid
        if (itemNumber < 1 || itemNumber > sizeof(menu) / sizeof(MenuItem)) {
            printf("Invalid item number. Please enter a number between 1 and %d.\n", sizeof(menu) / sizeof(MenuItem));
            i--;
            continue;
        }

        // Add the item to the order
        items[i] = menu[itemNumber - 1].name;
        prices[i] = menu[itemNumber - 1].price * quantity;
        totalPrice += prices[i];
    }

    // Return the total price
    return totalPrice;
}

// Function to print the receipt
void printReceipt(char *items[], float prices[], int numItems, float totalPrice) {
    printf("\nReceipt:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f\n", items[i], prices[i]);
    }
    printf("Total: $%.2f\n", totalPrice);
}

// Main function
int main() {
    char *items[MAX_MENU_ITEMS];
    float prices[MAX_MENU_ITEMS];
    int numItems;
    float totalPrice;

    // Print the menu
    printMenu();

    // Get the user's order
    totalPrice = getOrder(items, prices, &numItems);

    // Print the receipt
    printReceipt(items, prices, numItems, totalPrice);

    return 0;
}