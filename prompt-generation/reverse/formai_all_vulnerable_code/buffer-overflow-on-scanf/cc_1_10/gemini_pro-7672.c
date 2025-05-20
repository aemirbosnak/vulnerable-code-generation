//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: safe
// C Cafe Billing System Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
struct MenuItem {
    char *name;
    float price;
};

struct MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Soda", 1.75},
    {"Water", 1.00},
    {"Muffin", 2.00},
    {"Croissant", 2.50},
    {"Bagel", 1.50}
};

// Get the number of items in the menu
int numMenuItems = sizeof(menu) / sizeof(struct MenuItem);

// Define the customer order
struct CustomerOrder {
    char *name;
    struct MenuItem *items[10];
    int numItems;
    float total;
};

// Get the customer's name
char *getCustomerName() {
    char *name = malloc(sizeof(char) * 256);
    printf("Enter your name: ");
    scanf("%s", name);
    return name;
}

// Get the customer's order
struct CustomerOrder *getCustomerOrder(char *name) {
    struct CustomerOrder *order = malloc(sizeof(struct CustomerOrder));
    order->name = name;
    order->numItems = 0;
    order->total = 0.0;

    // Get the items ordered
    printf("What would you like to order? (Enter 'q' to quit): ");
    char item[256];
    while (strcmp(item, "q") != 0) {
        scanf("%s", item);
        if (strcmp(item, "q") == 0) {
            break;
        }

        // Find the item in the menu
        int itemIndex = -1;
        for (int i = 0; i < numMenuItems; i++) {
            if (strcmp(item, menu[i].name) == 0) {
                itemIndex = i;
                break;
            }
        }

        // If the item was found, add it to the order
        if (itemIndex != -1) {
            order->items[order->numItems] = &menu[itemIndex];
            order->numItems++;
            order->total += menu[itemIndex].price;
        } else {
            printf("Sorry, we don't have that item. Please try again: ");
        }
    }

    return order;
}

// Print the customer's order
void printCustomerOrder(struct CustomerOrder *order) {
    printf("Order for %s:\n", order->name);
    for (int i = 0; i < order->numItems; i++) {
        printf("  - %s: $%.2f\n", order->items[i]->name, order->items[i]->price);
    }
    printf("Total: $%.2f\n", order->total);
}

// Free the memory allocated for the customer's order
void freeCustomerOrder(struct CustomerOrder *order) {
    free(order->name);
    free(order);
}

// Main function
int main() {
    // Get the customer's name
    char *name = getCustomerName();

    // Get the customer's order
    struct CustomerOrder *order = getCustomerOrder(name);

    // Print the customer's order
    printCustomerOrder(order);

    // Free the memory allocated for the customer's order
    freeCustomerOrder(order);

    return 0;
}