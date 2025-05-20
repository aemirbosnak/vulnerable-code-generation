//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MENU_ITEMS 20
#define MAX_NAME_LENGTH 30

typedef struct MenuItem {
    char name[MAX_NAME_LENGTH];
    float price;
} MenuItem;

typedef struct Order {
    int quantity;
    MenuItem item;
} Order;

float calculateTotal(Order orders[], int numOrders) {
    float total = 0;

    for (int i = 0; i < numOrders; i++) {
        total += orders[i].quantity * orders[i].item.price;
    }

    return total;
}

void printOrder(Order order) {
    printf("%s (Quantity: %d): $%.2f\n", order.item.name, order.quantity, order.quantity * order.item.price);
}

void printBill(Order orders[], int numOrders) {
    printf("\n\n-----BILL-----\n");

    for (int i = 0; i < numOrders; i++) {
        printOrder(orders[i]);
    }

    printf("Total: $%.2f\n", calculateTotal(orders, numOrders));
    printf("Thank you for choosing us!\n\n");
}

int main() {
    MenuItem menu[MAX_MENU_ITEMS];
    int numMenuItems = 0;
    Order currentOrder[MAX_MENU_ITEMS];
    int numOrders = 0;

    // initialize menu
    MenuItem burger = {"Burger", 5.99};
    MenuItem fries = {"Fries", 2.99};
    MenuItem soda = {"Soda", 1.99};

    menu[numMenuItems++] = burger;
    menu[numMenuItems++] = fries;
    menu[numMenuItems++] = soda;

    // Print out the menu for the user to choose from
    printf("Welcome to our cafe! Here is our menu:\n");
    for (int i = 0; i < numMenuItems; i++) {
        printf("%d) %s ($%.2f)\n", i + 1, menu[i].name, menu[i].price);
    }

    int choice = 0;
    do {
        // Take user menu item Choice
        printf("Enter menu item number (0 to finish order):");
        scanf("%d", &choice);

        if (choice > 0 && choice <= numMenuItems) {
            // Add item to current order
            printf("Enter quantity:");
            int quantity = 0;
            scanf("%d", &quantity);

            currentOrder[numOrders].item = menu[choice - 1];
            currentOrder[numOrders].quantity = quantity;
            numOrders++;
        }
    } while (choice != 0);

    // Print the bill for the user
    printBill(currentOrder, numOrders);

    return 0;
}