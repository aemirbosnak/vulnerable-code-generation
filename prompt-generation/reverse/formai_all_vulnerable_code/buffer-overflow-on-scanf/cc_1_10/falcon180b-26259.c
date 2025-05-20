//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure for a menu item
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Define the structure for an order
typedef struct {
    int itemCount;
    MenuItem items[MAX_ITEMS];
} Order;

// Function to display the menu
void displayMenu(MenuItem menuItems[], int numItems) {
    printf("Welcome to the Cafe!\n");
    printf("Here's our menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

// Function to take an order
Order takeOrder(MenuItem menuItems[], int numItems) {
    Order order = {0};
    int choice;
    printf("What would you like to order?\n");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= numItems) {
        order.items[order.itemCount] = menuItems[choice-1];
        order.itemCount++;
    } else {
        printf("Invalid choice. Please try again.\n");
    }
    return order;
}

// Function to calculate the total cost of an order
float calculateTotal(Order order) {
    float total = 0.0;
    for (int i = 0; i < order.itemCount; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to print the order details and total cost
void printOrder(Order order) {
    printf("Your order:\n");
    for (int i = 0; i < order.itemCount; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total cost: $%.2f\n", calculateTotal(order));
}

int main() {
    // Define the menu items
    MenuItem menuItems[] = {{"Coffee", 2.50}, {"Tea", 1.75}, {"Cake", 3.99}, {"Sandwich", 4.25}, {"Salad", 5.50}};
    int numItems = sizeof(menuItems) / sizeof(MenuItem);

    // Take the order
    Order order = takeOrder(menuItems, numItems);

    // Print the order details and total cost
    printOrder(order);

    return 0;
}