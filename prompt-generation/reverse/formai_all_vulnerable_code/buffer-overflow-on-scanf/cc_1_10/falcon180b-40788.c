//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int amount;
} Item;

typedef struct {
    int numItems;
    Item items[10];
} Order;

void addItem(Order* order) {
    printf("Enter item name: ");
    scanf("%s", order->items[order->numItems].name);
    printf("Enter item amount: ");
    scanf("%d", &order->items[order->numItems].amount);
    order->numItems++;
}

void printOrder(Order order) {
    printf("Order: \n");
    for (int i = 0; i < order.numItems; i++) {
        printf("%s - %d\n", order.items[i].name, order.items[i].amount);
    }
}

void main() {
    Order order;
    order.numItems = 0;

    int choice;
    do {
        printf("\n1. Add item\n2. Print order\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addItem(&order);
            break;
        case 2:
            printOrder(order);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);
}