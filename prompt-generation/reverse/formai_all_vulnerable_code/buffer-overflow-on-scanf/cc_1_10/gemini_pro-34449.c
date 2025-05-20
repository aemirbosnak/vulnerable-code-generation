//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items in an order
#define MAX_ITEMS 100

// Define the menu items
struct MenuItem {
    char name[50];
    float price;
};

// Define the order struct
struct Order {
    struct MenuItem items[MAX_ITEMS];
    int numItems;
    float total;
};

// Function to print the menu
void printMenu(struct MenuItem menu[], int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to get the user's order
struct Order getOrder(struct MenuItem menu[], int numItems) {
    struct Order order;
    order.numItems = 0;
    order.total = 0.0;

    // Get the user's input
    int itemNum;
    int quantity;
    do {
        printf("Enter the item number (0 to finish): ");
        scanf("%d", &itemNum);

        if (itemNum > 0 && itemNum <= numItems) {
            printf("Enter the quantity: ");
            scanf("%d", &quantity);

            // Add the item to the order
            order.items[order.numItems] = menu[itemNum - 1];
            order.numItems++;
            order.total += quantity * menu[itemNum - 1].price;
        }
    } while (itemNum != 0);

    return order;
}

// Function to print the order
void printOrder(struct Order order) {
    printf("Order:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("%s x %d - $%.2f\n", order.items[i].name, order.items[i].price, order.items[i].price);
    }
    printf("Total: $%.2f\n", order.total);
}

// Main function
int main() {
    // Define the menu
    struct MenuItem menu[] = {
        {"Coffee", 2.50},
        {"Tea", 2.00},
        {"Soda", 1.50},
        {"Water", 1.00},
        {"Muffin", 3.00},
        {"Cookie", 1.50},
        {"Chips", 2.00},
        {"Candy", 1.00},
    };
    int numItems = sizeof(menu) / sizeof(menu[0]);

    // Print the menu
    printMenu(menu, numItems);

    // Get the user's order
    struct Order order = getOrder(menu, numItems);

    // Print the order
    printOrder(order);

    return 0;
}