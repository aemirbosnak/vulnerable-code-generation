//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    int numItems;
    Item items[MAX_ITEMS];
} Order;

void addItem(Order *order) {
    int i;
    for (i = 0; i < order->numItems; i++) {
        if (strcmp(order->items[i].name, "") == 0) {
            printf("Enter item name: ");
            scanf("%s", order->items[i].name);
            printf("Enter item quantity: ");
            scanf("%d", &order->items[i].quantity);
            printf("Enter item price: ");
            scanf("%f", &order->items[i].price);
            break;
        }
    }
}

void displayOrder(Order order) {
    int i;
    printf("Order:\n");
    for (i = 0; i < order.numItems; i++) {
        printf("Item name: %s\n", order.items[i].name);
        printf("Item quantity: %d\n", order.items[i].quantity);
        printf("Item price: $%.2f\n", order.items[i].price);
        printf("\n");
    }
}

void calculateTotal(Order order) {
    int i;
    float total = 0.0;
    for (i = 0; i < order.numItems; i++) {
        total += order.items[i].price * order.items[i].quantity;
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    Order order;
    order.numItems = 0;

    while (1) {
        printf("1. Add item\n");
        printf("2. Display order\n");
        printf("3. Calculate total\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addItem(&order);
            break;
        case 2:
            displayOrder(order);
            break;
        case 3:
            calculateTotal(order);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}