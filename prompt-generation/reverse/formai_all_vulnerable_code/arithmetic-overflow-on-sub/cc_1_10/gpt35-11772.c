//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for menu items
struct MenuItem {
    char name[50];
    float price;
};

// Define struct for customer orders
struct CustomerOrder {
    char name[50];
    int quantity;
};

// Define global menu array
struct MenuItem menu[10] = {
    {"Espresso", 2.5},
    {"Americano", 3},
    {"Latte", 3.5},
    {"Cappuccino", 3},
    {"Mocha", 4},
    {"Hot Chocolate", 2.5},
    {"Tea", 2},
    {"Iced Coffee", 4},
    {"Smoothie", 5},
    {"Cake", 4.5}
};

// Define function to print menu
void printMenu() {
    printf("Welcome to the C Cafe!\n");
    printf("------------------------------\n");
    printf("MENU:\n\n");
    for (int i=0; i<10; i++) {
        printf("%d. %s: $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

// Define function to get order from customer
struct CustomerOrder getOrder() {
    struct CustomerOrder order;
    printf("Please enter the number of the item you would like to order: ");
    scanf("%d", &order.quantity);
    printf("Please enter your name: ");
    scanf("%s", order.name);
    return order;
}

// Define function to compute bill for customer
float computeBill(struct CustomerOrder order) {
    return order.quantity * menu[order.quantity-1].price;
}

int main() {
    // Print menu
    printMenu();
    
    // Get order from customer
    struct CustomerOrder order = getOrder();
    
    // Compute bill
    float bill = computeBill(order);
    
    // Print bill
    printf("Thank you for your order, %s!\n", order.name);
    printf("Your bill for %d %s(s) is: $%.2f\n", order.quantity, menu[order.quantity-1].name, bill);
    
    return 0;
}