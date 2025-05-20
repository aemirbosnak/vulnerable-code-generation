//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50
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

void addItem(Item items[], int *numItems) {
    printf("Enter item name: ");
    scanf("%s", &items[*numItems].name);
    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
    (*numItems)++;
}

void displayItems(Item items[], int numItems) {
    printf("\nItems:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }
}

void addOrder(Order orders[], int *numOrders) {
    printf("\nEnter order name: ");
    scanf("%s", &orders[*numOrders].name);
    orders[*numOrders].quantity = 0;
    orders[*numOrders].total = 0.0;
    (*numOrders)++;
}

void displayOrders(Order orders[], int numOrders) {
    printf("\nOrders:\n");
    for (int i = 0; i < numOrders; i++) {
        printf("%s - %d items - $%.2f\n", orders[i].name, orders[i].quantity, orders[i].total);
    }
}

void processOrder(Item items[], Order orders[], int numItems, int numOrders) {
    printf("\nEnter order number: ");
    int orderNum;
    scanf("%d", &orderNum);

    if (orderNum >= numOrders || orderNum < 1) {
        printf("Invalid order number.\n");
        return;
    }

    printf("Enter quantity for %s:\n", orders[orderNum-1].name);
    scanf("%d", &orders[orderNum-1].quantity);

    int i;
    for (i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, orders[orderNum-1].name) == 0) {
            orders[orderNum-1].total += items[i].price * orders[orderNum-1].quantity;
            break;
        }
    }

    if (i == numItems) {
        printf("Invalid item.\n");
        orders[orderNum-1].quantity = 0;
        orders[orderNum-1].total = 0.0;
    }
}

void main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    addItem(items, &numItems);
    displayItems(items, numItems);

    Order orders[MAX_ITEMS];
    int numOrders = 0;

    addOrder(orders, &numOrders);
    displayOrders(orders, numOrders);

    int choice;
    do {
        printf("\n1. Add item\n2. Add order\n3. Process order\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &numItems);
                displayItems(items, numItems);
                break;
            case 2:
                addOrder(orders, &numOrders);
                displayOrders(orders, numOrders);
                break;
            case 3:
                processOrder(items, orders, numItems, numOrders);
                displayOrders(orders, numOrders);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
}