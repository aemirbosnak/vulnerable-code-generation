//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to store the menu items
typedef struct MenuItem {
    char name[50];
    float price;
} MenuItem;

// A struct to store the order items
typedef struct OrderItem {
    char name[50];
    int quantity;
    float price;
} OrderItem;

// A struct to store the order
typedef struct Order {
    char customerName[50];
    OrderItem *items;
    int numItems;
    float total;
} Order;

// A function to print the menu
void printMenu(MenuItem *menu, int numItems) {
    printf("Welcome to the Cafe! Our menu today is:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// A function to take the order
Order *takeOrder(MenuItem *menu, int numItems) {
    Order *order = malloc(sizeof(Order));
    printf("What is your name? ");
    scanf("%s", order->customerName);

    printf("How many items would you like to order? ");
    scanf("%d", &order->numItems);

    order->items = malloc(sizeof(OrderItem) * order->numItems);

    for (int i = 0; i < order->numItems; i++) {
        printf("What is the name of item %d? ", i + 1);
        scanf("%s", order->items[i].name);

        printf("How many of item %d would you like? ", i + 1);
        scanf("%d", &order->items[i].quantity);

        // Find the price of the item
        for (int j = 0; j < numItems; j++) {
            if (strcmp(order->items[i].name, menu[j].name) == 0) {
                order->items[i].price = menu[j].price;
                break;
            }
        }
    }

    // Calculate the total price of the order
    order->total = 0;
    for (int i = 0; i < order->numItems; i++) {
        order->total += order->items[i].price * order->items[i].quantity;
    }

    return order;
}

// A function to print the order
void printOrder(Order *order) {
    printf("Order for %s:\n", order->customerName);
    for (int i = 0; i < order->numItems; i++) {
        printf("%d. %s - $%.2f x %d\n", i + 1, order->items[i].name, order->items[i].price, order->items[i].quantity);
    }
    printf("Total: $%.2f\n", order->total);
}

// A function to free the memory allocated for the order
void freeOrder(Order *order) {
    free(order->items);
    free(order);
}

int main() {
    // The menu
    MenuItem menu[] = {
        {"Coffee", 2.50},
        {"Tea", 2.00},
        {"Cake", 3.00},
        {"Pie", 3.50},
        {"Sandwich", 4.00}
    };
    int numItems = sizeof(menu) / sizeof(MenuItem);

    // Take the order
    Order *order = takeOrder(menu, numItems);

    // Print the order
    printOrder(order);

    // Free the memory allocated for the order
    freeOrder(order);

    return 0;
}