//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an item
typedef struct {
    char name[50];
    float price;
} Item;

// Define the structure of an order
typedef struct {
    int numItems;
    Item items[MAX_ITEMS];
} Order;

// Function to add an item to an order
void addItem(Order* order, char* name, float price) {
    if (order->numItems >= MAX_ITEMS) {
        printf("Error: Cannot add more than %d items to an order.\n", MAX_ITEMS);
        return;
    }
    strcpy(order->items[order->numItems].name, name);
    order->items[order->numItems].price = price;
    order->numItems++;
}

// Function to calculate the total price of an order
float calculateTotal(Order order) {
    float total = 0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to display an order
void displayOrder(Order order) {
    printf("Order:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("%s: $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total: $%.2f\n", calculateTotal(order));
}

int main() {
    Order order;
    char choice;
    do {
        printf("Cafe Billing System\n");
        printf("1. Add item\n");
        printf("2. Display order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter the name of the item: ");
                scanf("%s", order.items[order.numItems-1].name);
                printf("Enter the price of the item: ");
                scanf("%f", &order.items[order.numItems-1].price);
                printf("Item added to order.\n");
                break;
            case '2':
                displayOrder(order);
                break;
            case '3':
                printf("Thank you for using our cafe billing system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '3');
    return 0;
}