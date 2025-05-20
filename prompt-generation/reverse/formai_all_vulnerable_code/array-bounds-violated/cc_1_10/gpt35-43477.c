//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define struct for menu items
struct MenuItem {
    int id;
    char name[50];
    float price;
};

// Define struct for orders
struct Order {
    int id;
    char itemName[50];
    float itemPrice;
    int quantity;
    float total;
};

// Declare global variables
int menuSize = 5;
struct MenuItem menu[5];
int orderCount = 0;
struct Order orders[100];
float subtotal = 0.0;
float tax = 0.0;
float total = 0.0;

// Function to add new menu item
void addMenuItem(int id, char name[], float price) {
    struct MenuItem item;
    item.id = id;
    strcpy(item.name, name);
    item.price = price;
    menu[menuSize] = item;
    menuSize++;
}

// Function to display menu
void displayMenu() {
    printf("============================\n");
    printf("      C CAFE MENU\n");
    printf("============================\n");
    printf(" ID | ITEM              | PRICE\n");
    printf("----|------------------|------\n");
    for (int i = 0; i < menuSize; i++) {
        printf(" %d  | %s | %.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

// Function to place an order
void placeOrder(int itemId, int quantity) {
    struct Order order;
    order.id = orderCount + 1;
    strcpy(order.itemName, menu[itemId-1].name);
    order.itemPrice = menu[itemId-1].price;
    order.quantity = quantity;
    order.total = order.quantity * order.itemPrice;
    orders[orderCount] = order;
    orderCount++;
}

// Function to display the order receipt
void displayReceipt() {
    printf("============================\n");
    printf("        C CAFE RECEIPT\n");
    printf("============================\n");
    printf(" ID | ITEM              | PRICE | QTY | TOTAL\n");
    printf("----|------------------|-------|-----|-------\n");
    for (int i = 0; i < orderCount; i++) {
        printf(" %d  | %s | %.2f    |  %d  |  %.2f\n", orders[i].id, orders[i].itemName, orders[i].itemPrice, orders[i].quantity, orders[i].total);
    }
    printf("============================\n");
    subtotal = 0.0;
    for (int i = 0; i < orderCount; i++) {
        subtotal += orders[i].total;
    }
    tax = subtotal * 0.07;
    total = subtotal + tax;
    printf("SUBTOTAL: $%.2f\n", subtotal);
    printf("TAX: $%.2f\n", tax);
    printf("TOTAL: $%.2f\n", total);
}

int main() {
    // Add menu items
    addMenuItem(1, "Coffee", 1.50);
    addMenuItem(2, "Tea", 1.25);
    addMenuItem(3, "Muffin", 2.00);
    addMenuItem(4, "Bagel", 1.75);
    addMenuItem(5, "Croissant", 2.50);
    
    // Show menu
    displayMenu();
    
    // Place orders
    placeOrder(1, 2);
    placeOrder(3, 1);
    placeOrder(2, 3);
    
    // Display receipt
    displayReceipt();
    
    return 0;
}