//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and prices
struct MenuItem {
    char name[50];
    float price;
};

struct MenuItem menuItems[] = {
    {"Espresso", 2.50},
    {"Cappuccino", 3.00},
    {"Latte", 3.50},
    {"Americano", 2.75},
    {"Mocha", 4.00},
    {"Caramel Macchiato", 4.50},
    {"Pumpkin Spice Latte", 4.75},
    {"Hot Chocolate", 3.25},
    {"Tea", 2.25},
    {"Smoothie", 4.25},
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Get the user's order
void getOrder(struct MenuItem *items, int *numItems) {
    int i;
    char itemName[50];

    // Get the number of items the user wants to order
    printf("How many items would you like to order? ");
    scanf("%d", numItems);

    // Get the name of each item the user wants to order
    for (i = 0; i < *numItems; i++) {
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", itemName);

        // Find the item in the menu
        int found = 0;
        for (int j = 0; j < sizeof(menuItems) / sizeof(struct MenuItem); j++) {
            if (strcmp(itemName, menuItems[j].name) == 0) {
                items[i] = menuItems[j];
                found = 1;
                break;
            }
        }

        // If the item was not found, print an error message
        if (!found) {
            printf("Item %s not found.\n", itemName);
            i--;
        }
    }
}

// Calculate the total bill
float calculateBill(struct MenuItem *items, int numItems) {
    float total = 0.0;

    for (int i = 0; i < numItems; i++) {
        total += items[i].price;
    }

    return total;
}

// Print the receipt
void printReceipt(struct MenuItem *items, int numItems, float total) {
    printf("\nHere is your receipt:\n");
    printf("------------------------------\n");
    printf("Item\t\tPrice\n");
    printf("------------------------------\n");

    for (int i = 0; i < numItems; i++) {
        printf("%s\t\t$%.2f\n", items[i].name, items[i].price);
    }

    printf("------------------------------\n");
    printf("Total:\t\t$%.2f\n", total);
    printf("------------------------------\n");
}

// Main function
int main() {
    // Declare the variables
    struct MenuItem items[MAX_ITEMS];
    int numItems;
    float total;

    // Get the user's order
    getOrder(items, &numItems);

    // Calculate the total bill
    total = calculateBill(items, numItems);

    // Print the receipt
    printReceipt(items, numItems, total);

    return 0;
}