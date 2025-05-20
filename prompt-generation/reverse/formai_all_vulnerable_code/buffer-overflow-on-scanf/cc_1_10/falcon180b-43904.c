//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

typedef struct {
    char name[30];
    float price;
} Item;

typedef struct {
    char name[30];
    int quantity;
} Order;

void addItem(Item items[], int *numItems) {
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);
    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
    (*numItems)++;
}

void displayItems(Item items[], int numItems) {
    printf("\nMenu\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void placeOrder(Order order, Item items[], int numItems) {
    printf("\nOrder:\n");
    int total = 0;
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
    printf("Enter item number: ");
    scanf("%d", &order.quantity);
    printf("Enter quantity: ");
    scanf("%d", &order.quantity);
    total += order.quantity * items[order.quantity-1].price;
    printf("Total: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    addItem(items, &numItems);
    addItem(items, &numItems);
    addItem(items, &numItems);

    Order order;
    placeOrder(order, items, numItems);

    return 0;
}