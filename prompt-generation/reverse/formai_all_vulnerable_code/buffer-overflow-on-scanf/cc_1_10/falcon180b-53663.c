//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME 30
#define MAX_PRICE 10

typedef struct {
    char name[MAX_NAME];
    float price;
} Item;

typedef struct {
    char name[MAX_NAME];
    int quantity;
    float total;
} Order;

void addItem(Item* items, int* numItems) {
    char name[MAX_NAME];
    float price;

    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item price: ");
    scanf("%f", &price);

    strcpy(items[*numItems].name, name);
    items[*numItems].price = price;

    (*numItems)++;
}

void displayItems(Item* items, int numItems) {
    int i;

    printf("Item Name\tPrice\n");

    for (i = 0; i < numItems; i++) {
        printf("%s\t%f\n", items[i].name, items[i].price);
    }
}

void addOrder(Order* orders, int* numOrders) {
    char name[MAX_NAME];

    printf("Enter order name: ");
    scanf("%s", name);

    strcpy(orders[*numOrders].name, name);
    orders[*numOrders].quantity = 0;
    orders[*numOrders].total = 0;

    (*numOrders)++;
}

void displayOrders(Order* orders, int numOrders) {
    int i;

    printf("Order Name\tQuantity\tTotal\n");

    for (i = 0; i < numOrders; i++) {
        printf("%s\t%d\t%f\n", orders[i].name, orders[i].quantity, orders[i].total);
    }
}

void addToOrder(Item* items, Order* orders, int numItems, int numOrders) {
    int i, j;
    char name[MAX_NAME];

    printf("Enter item name: ");
    scanf("%s", name);

    for (i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Enter quantity: ");
            scanf("%d", &orders[numOrders - 1].quantity);

            orders[numOrders - 1].total += items[i].price * orders[numOrders - 1].quantity;
            break;
        }
    }

    if (i == numItems) {
        printf("Item not found.\n");
    }
}

void calculateTotal(Order* orders, int numOrders) {
    int i;

    for (i = 0; i < numOrders; i++) {
        orders[i].total = orders[i].quantity * orders[i].total;
    }
}

void main() {
    Item items[MAX_ITEMS];
    Order orders[MAX_ITEMS];
    int numItems = 0, numOrders = 0;

    addItem(items, &numItems);
    addOrder(orders, &numOrders);

    displayItems(items, numItems);
    displayOrders(orders, numOrders);

    addToOrder(items, orders, numItems, numOrders);

    displayItems(items, numItems);
    displayOrders(orders, numOrders);

    calculateTotal(orders, numOrders);

    displayOrders(orders, numOrders);
}