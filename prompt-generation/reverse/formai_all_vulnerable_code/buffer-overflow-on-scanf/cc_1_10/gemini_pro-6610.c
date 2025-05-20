//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
struct MenuItem {
    char name[50];
    float price;
};

struct MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Soda", 2.50},
    {"Water", 1.50},
    {"Sandwich", 6.00},
    {"Salad", 5.00},
    {"Soup", 4.00},
    {"Pastry", 3.00}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure for the order
struct Order {
    struct MenuItem items[MAX_ITEMS];
    int numItems;
    float total;
};

// Function to print the menu
void printMenu() {
    for (int i = 0; i < sizeof(menuItems) / sizeof(struct MenuItem); i++) {
        printf("%d. %s - $%.2f\n", i + 1, menuItems[i].name, menuItems[i].price);
    }
}

// Function to get the user's order
struct Order getOrder() {
    struct Order order;
    order.numItems = 0;
    order.total = 0.0;

    int itemNum;
    while (1) {
        printf("Enter the number of the item you want to order (0 to finish): ");
        scanf("%d", &itemNum);

        if (itemNum == 0) {
            break;
        } else if (itemNum < 1 || itemNum > sizeof(menuItems) / sizeof(struct MenuItem)) {
            printf("Invalid item number. Please enter a number between 1 and %d.\n", sizeof(menuItems) / sizeof(struct MenuItem));
        } else {
            order.items[order.numItems] = menuItems[itemNum - 1];
            order.numItems++;
            order.total += menuItems[itemNum - 1].price;
        }
    }

    return order;
}

// Function to print the order
void printOrder(struct Order order) {
    printf("Order:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("%d. %s - $%.2f\n", i + 1, order.items[i].name, order.items[i].price);
    }
    printf("Total: $%.2f\n", order.total);
}

// Main function
int main() {
    // Print the menu
    printMenu();

    // Get the user's order
    struct Order order = getOrder();

    // Print the order
    printOrder(order);

    return 0;
}