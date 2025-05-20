//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure for a menu item
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Define the structure for an order
typedef struct {
    int numItems;
    MenuItem items[MAX_ITEMS];
} Order;

// Function to add an item to an order
void addItem(Order* order) {
    printf("Enter the name of the item: ");
    scanf("%s", order->items[order->numItems].name);
    printf("Enter the price of the item: ");
    scanf("%f", &order->items[order->numItems].price);
    order->numItems++;
}

// Function to display the details of an order
void displayOrder(Order order) {
    printf("Order details:\n");
    printf("Number of items: %d\n", order.numItems);
    for (int i = 0; i < order.numItems; i++) {
        printf("Item %d:\n");
        printf("Name: %s\n", order.items[i].name);
        printf("Price: $%.2f\n\n", order.items[i].price);
    }
}

// Function to calculate the total price of an order
float calculateTotal(Order order) {
    float total = 0.0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }
    return total;
}

int main() {
    // Initialize the order
    Order order = {0};

    // Add items to the order
    int choice;
    do {
        printf("\n1. Add item\n2. Display order\n3. Calculate total\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addItem(&order);
            break;
        case 2:
            displayOrder(order);
            break;
        case 3:
            printf("Total price of the order: $%.2f\n", calculateTotal(order));
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}