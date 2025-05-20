//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LEN 50

// Struct to hold item details
typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} Item;

// Struct to hold order details
typedef struct {
    int numItems;
    Item items[MAX_ITEMS];
} Order;

// Function to add an item to the order
void addItem(Order* order) {
    if (order->numItems >= MAX_ITEMS) {
        printf("Cannot add more items to the order.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", order->items[order->numItems].name);

    printf("Enter item price: ");
    scanf("%f", &order->items[order->numItems].price);

    order->numItems++;
}

// Function to calculate the total price of the order
float calculateTotal(Order order) {
    float total = 0.0;

    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }

    return total;
}

// Function to print the order details
void printOrder(Order order) {
    printf("Order details:\n");

    for (int i = 0; i < order.numItems; i++) {
        printf("Item %d: %s - $%.2f\n", i + 1, order.items[i].name, order.items[i].price);
    }

    printf("Total price: $%.2f\n", calculateTotal(order));
}

int main() {
    Order order = {0};

    while (1) {
        printf("1. Add item\n2. Print order\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addItem(&order);
            break;
        case 2:
            printOrder(order);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}