//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants for maximum menu items and maximum string length
#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 20

// Structures for menu items and customer orders
struct MenuItem {
    char name[MAX_NAME_LENGTH];
    int price;
};

struct OrderItem {
    char name[MAX_NAME_LENGTH];
    int quantity;
    int price;
};

// Global arrays to store the menu items and customer orders
struct MenuItem menu[MAX_ITEMS];
struct OrderItem orders[MAX_ITEMS];

// Variables to keep track of the current number of menu items and customer orders
int numMenuItems;
int numOrders;

// Function to add a new menu item to the array
void addMenuItem(char name[], int price) {
    struct MenuItem item;
    strcpy(item.name, name);
    item.price = price;
    menu[numMenuItems] = item;
    numMenuItems++;
}

// Function to display the menu
void displayMenu() {
    printf("MENU\n");
    printf("-------------------\n");
    for (int i = 0; i < numMenuItems; i++) {
        printf("%d. %s - $%d\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to add a new order to the array
void addOrder(char name[], int quantity) {
    // Find the menu item with the given name
    int itemIndex = -1;
    for (int i = 0; i < numMenuItems; i++) {
        if (strcmp(name, menu[i].name) == 0) {
            itemIndex = i;
            break;
        }
    }

    // If the menu item was found, add the order
    if (itemIndex != -1) {
        struct OrderItem item;
        strcpy(item.name, name);
        item.quantity = quantity;
        item.price = menu[itemIndex].price * quantity;
        orders[numOrders] = item;
        numOrders++;
        printf("Added %d %s to order\n", quantity, name);
    } else {
        printf("Menu item not found\n");
    }
}

// Function to display the current order
void displayOrder() {
    printf("ORDER\n");
    printf("-------------------\n");
    int total = 0;
    for (int i = 0; i < numOrders; i++) {
        printf("%d. %s x%d - $%d\n", i+1, orders[i].name, orders[i].quantity, orders[i].price);
        total += orders[i].price;
    }
    printf("\nTOTAL: $%d\n", total);
}

// Function to calculate the bill and clear the order
void calculateBill() {
    int total = 0;
    for (int i = 0; i < numOrders; i++) {
        total += orders[i].price;
    }
    printf("TOTAL BILL AMOUNT: $%d\n", total);
    numOrders = 0;
}

// main function
int main() {
    // Add some menu items
    addMenuItem("Coffee", 2);
    addMenuItem("Tea", 1);
    addMenuItem("Donuts", 3);

    // Display the menu
    displayMenu();

    // Take customer orders
    bool done = false;
    while (!done) {
        printf("Enter item to order (or 'done' to finish): ");
        char itemName[MAX_NAME_LENGTH];
        scanf("%s", itemName);
        if (strcmp(itemName, "done") == 0) {
            done = true;
        } else {
            printf("Enter quantity: ");
            int quantity;
            scanf("%d", &quantity);
            addOrder(itemName, quantity);
        }
    }

    // Display the current order
    displayOrder();

    // Calculate and print the bill
    calculateBill();

    return 0;
}