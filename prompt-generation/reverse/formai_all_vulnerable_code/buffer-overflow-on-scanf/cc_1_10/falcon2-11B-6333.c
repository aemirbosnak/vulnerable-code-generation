//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the menu items
struct MenuItem {
    char name[20];
    float price;
};

// Define the menu items
struct MenuItem menu[] = {
    {"Espresso", 3.50},
    {"Cappuccino", 4.50},
    {"Latte", 5.00},
    {"Mocha", 5.50},
    {"Iced Coffee", 4.00}
};

// Define the customer order
struct Order {
    char name[20];
    int numItems;
    struct MenuItem* menuItems;
};

// Function to print the menu items
void printMenu() {
    int i;
    printf("\nCafe Menu\n");
    for (i = 0; i < sizeof(menu) / sizeof(struct MenuItem); i++) {
        printf("%s - $%.2f\n", menu[i].name, menu[i].price);
    }
}

// Function to process the customer order
void processOrder(struct Order* order) {
    int i, totalPrice = 0;
    for (i = 0; i < order->numItems; i++) {
        totalPrice += order->menuItems[i].price;
    }
    printf("%s's order: ", order->name);
    for (i = 0; i < order->numItems; i++) {
        printf("%s x $%.2f\n", order->menuItems[i].name, order->menuItems[i].price);
    }
    printf("Total price: $%.2f\n", totalPrice);
}

// Main function
int main() {
    char customerName[20];
    struct Order order;

    // Get customer name
    printf("Enter customer name: ");
    scanf("%s", customerName);

    // Get customer order
    printf("Enter number of items: ");
    scanf("%d", &order.numItems);
    order.menuItems = (struct MenuItem*)malloc(order.numItems * sizeof(struct MenuItem));
    for (int i = 0; i < order.numItems; i++) {
        printf("Enter item name (%d): ", i + 1);
        scanf("%s", order.menuItems[i].name);
        printf("Enter price: $");
        scanf("%f", &order.menuItems[i].price);
    }

    // Process the order
    printf("Processing order for %s...\n", customerName);
    processOrder(&order);

    // Free allocated memory
    for (int i = 0; i < order.numItems; i++) {
        free(order.menuItems[i].name);
    }
    free(order.menuItems);

    return 0;
}