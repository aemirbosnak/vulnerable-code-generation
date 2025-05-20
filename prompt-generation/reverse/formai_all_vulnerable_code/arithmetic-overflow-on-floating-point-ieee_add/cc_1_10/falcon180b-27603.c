//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the menu
#define MAX_MENU_ITEMS 50

// Define the structure of a menu item
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Define the structure of a customer order
typedef struct {
    int itemCount;
    MenuItem items[MAX_MENU_ITEMS];
} Order;

// Function to display the menu
void displayMenu(MenuItem menuItems[], int count) {
    printf("Menu:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

// Function to add an item to the customer order
void addItem(Order* order) {
    if (order->itemCount >= MAX_MENU_ITEMS) {
        printf("Sorry, you cannot add more items to your order.\n");
        return;
    }

    printf("Enter the name of the item you want to add:\n");
    scanf("%s", order->items[order->itemCount].name);

    printf("Enter the price of the item:\n");
    scanf("%f", &order->items[order->itemCount].price);

    order->itemCount++;
}

// Function to calculate the total cost of the order
float calculateTotal(Order order) {
    float total = 0.0;

    for (int i = 0; i < order.itemCount; i++) {
        total += order.items[i].price;
    }

    return total;
}

// Function to print the customer order
void printOrder(Order order) {
    printf("Order:\n");
    for (int i = 0; i < order.itemCount; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }

    printf("Total cost: $%.2f\n", calculateTotal(order));
}

// Function to run the cafe billing system
int main() {
    // Define the menu items
    MenuItem menuItems[] = {{"Coffee", 2.99}, {"Tea", 1.99}, {"Cake", 3.99}, {"Sandwich", 4.99}};
    int menuItemCount = sizeof(menuItems) / sizeof(MenuItem);

    // Initialize the customer order
    Order order = {0};

    // Display the menu
    displayMenu(menuItems, menuItemCount);

    // Allow the customer to add items to their order
    while (1) {
        int choice;
        printf("Enter 1 to add an item, 0 to finish:\n");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        addItem(&order);
    }

    // Print the customer order
    printOrder(order);

    return 0;
}