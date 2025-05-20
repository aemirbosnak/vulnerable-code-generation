//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_ORDERS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

typedef struct Order {
    Item items[MAX_ITEMS];
    int numItems;
    float totalCost;
} Order;

Order orders[MAX_ORDERS];

void addItem(Order *order) {
    if (order->numItems >= MAX_ITEMS) {
        return;
    }

    printf("Enter item name:");
    scanf("%s", order->items[order->numItems].name);

    printf("Enter item quantity:");
    scanf("%d", &order->items[order->numItems].quantity);

    printf("Enter item price:");
    scanf("%f", &order->items[order->numItems].price);

    order->numItems++;
    order->totalCost += order->items[order->numItems - 1].quantity * order->items[order->numItems - 1].price;
}

void calculateOrderTotal(Order *order) {
    order->totalCost = 0;
    for (int i = 0; i < order->numItems; i++) {
        order->totalCost += order->items[i].quantity * order->items[i].price;
    }
}

void printOrder(Order *order) {
    printf("Order details:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%s - %d units @ %.2f each = %.2f\n", order->items[i].name, order->items[i].quantity, order->items[i].price, order->items[i].quantity * order->items[i].price);
    }

    printf("Total cost: %.2f\n", order->totalCost);
}

int main() {
    Order *order = &orders[0];
    order->numItems = 0;

    while (1) {
        printf("Enter 'add' to add items, 'print' to print order, 'calculate' to calculate total cost, or 'exit' to exit:");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            addItem(order);
        } else if (strcmp(command, "print") == 0) {
            printOrder(order);
        } else if (strcmp(command, "calculate") == 0) {
            calculateOrderTotal(order);
            printOrder(order);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}