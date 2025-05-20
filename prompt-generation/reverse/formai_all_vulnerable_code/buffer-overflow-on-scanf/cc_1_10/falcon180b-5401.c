//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 100

// Define the structure for the menu item
typedef struct {
    char name[50];
    double price;
} MenuItem;

// Define the structure for the order
typedef struct {
    int numItems;
    MenuItem items[MAX_ITEMS];
} Order;

// Function to print the menu
void printMenu(MenuItem menuItems[], int numMenuItems) {
    printf("MENU:\n");
    for (int i = 0; i < numMenuItems; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menuItems[i].name, menuItems[i].price);
    }
}

// Function to add an item to the order
void addItem(Order* order, MenuItem menuItems[], int numMenuItems) {
    if (order->numItems >= MAX_ITEMS) {
        printf("Cannot add more than %d items.\n", MAX_ITEMS);
        return;
    }

    int choice;
    printf("Enter the number of the item you want to order: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > numMenuItems) {
        printf("Invalid choice.\n");
        return;
    }

    order->items[order->numItems] = menuItems[choice - 1];
    order->numItems++;
}

// Function to calculate the total cost of the order
double calculateTotal(Order order) {
    double total = 0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to print the order
void printOrder(Order order) {
    printf("ORDER:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total cost: $%.2f\n", calculateTotal(order));
}

int main() {
    // Define the menu items
    MenuItem menuItems[] = {
        {"Coffee", 2.99},
        {"Tea", 1.99},
        {"Cake", 3.99},
        {"Sandwich", 4.99}
    };

    // Initialize the order
    Order order = {0};

    // Print the menu
    printMenu(menuItems, sizeof(menuItems) / sizeof(MenuItem));

    // Add items to the order
    int choice;
    while (1) {
        printf("Do you want to order more items? (y/n): ");
        scanf("%s", &choice);
        if (choice == 'n') {
            break;
        }
        addItem(&order, menuItems, sizeof(menuItems) / sizeof(MenuItem));
    }

    // Print the order
    printOrder(order);

    return 0;
}