//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
struct MenuItem {
    char name[30];
    float price;
};

struct MenuItem menu[] = {
    {"Coffee", 1.50},
    {"Tea", 1.25},
    {"Hot Chocolate", 2.00},
    {"Espresso", 2.50},
    {"Cappuccino", 3.00},
    {"Latte", 3.50},
    {"Mocha", 4.00},
    {"Americano", 2.75},
    {"Macchiato", 3.25},
    {"Flat White", 3.75}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Get the user's order
void getOrder(struct MenuItem menu[], int *numItems, float *total) {
    int i, quantity;
    char itemName[30];

    *numItems = 0;
    *total = 0.0;

    printf("Welcome to the Cafe!\n");
    printf("Please enter the name of the item you would like to order, or 'q' to quit:\n");

    while (1) {
        scanf("%s", itemName);

        if (strcmp(itemName, "q") == 0) {
            break;
        }

        // Find the item in the menu
        for (i = 0; i < sizeof(menu) / sizeof(struct MenuItem); i++) {
            if (strcmp(itemName, menu[i].name) == 0) {
                // Get the quantity of the item
                printf("How many %s would you like? ", menu[i].name);
                scanf("%d", &quantity);

                // Add the item to the order
                *numItems += quantity;
                *total += menu[i].price * quantity;

                break;
            }
        }

        // If the item was not found, display an error message
        if (i == sizeof(menu) / sizeof(struct MenuItem)) {
            printf("Sorry, we don't have that item on the menu.\n");
        }
    }
}

// Print the order summary
void printOrderSummary(struct MenuItem menu[], int numItems, float total) {
    int i;

    printf("\nOrder Summary:\n");
    printf("--------------------------------------\n");
    printf("Item\t\tQuantity\tPrice\n");
    printf("--------------------------------------\n");

    for (i = 0; i < numItems; i++) {
        printf("%s\t\t%d\t\t$%.2f\n", menu[i].name, numItems, menu[i].price);
    }

    printf("\nTotal:\t\t\t$%.2f\n", total);
}

// Main function
int main() {
    int numItems;
    float total;

    // Get the user's order
    getOrder(menu, &numItems, &total);

    // Print the order summary
    printOrderSummary(menu, numItems, total);

    return 0;
}