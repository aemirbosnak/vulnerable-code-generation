//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ITEMS 100
#define MAX_ORDERS 50

typedef struct {
    char name[50];
    int price;
} Item;

typedef struct {
    int numItems;
    Item items[MAX_ITEMS];
} Order;

void addItem(Order* order) {
    printf("Enter the name of the item: ");
    scanf("%s", order->items[order->numItems].name);
    printf("Enter the price of the item: ");
    scanf("%d", &order->items[order->numItems].price);
    order->numItems++;
}

void displayItems(Order order) {
    printf("Order items:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("%s - $%d\n", order.items[i].name, order.items[i].price);
    }
}

void calculateTotal(Order order) {
    int total = 0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }
    printf("Total: $%d\n", total);
}

int main() {
    Order order;
    order.numItems = 0;

    int choice;
    do {
        printf("\nCafe Billing System\n");
        printf("1. Add item\n2. Display items\n3. Calculate total\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&order);
                break;
            case 2:
                displayItems(order);
                break;
            case 3:
                calculateTotal(order);
                break;
            case 4:
                printf("Thank you for using our cafe billing system!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}