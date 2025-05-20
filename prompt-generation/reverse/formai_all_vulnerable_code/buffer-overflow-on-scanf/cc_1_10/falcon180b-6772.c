//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
} Item;

typedef struct {
    char name[50];
    int quantity;
    float price;
} Order;

void addItem(Item items[], int *numItems) {
    char name[50];
    float price;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item price: ");
    scanf("%f", &price);

    strcpy(items[*numItems].name, name);
    items[*numItems].price = price;

    (*numItems)++;
}

void displayMenu(Item items[], int numItems) {
    int choice;

    printf("\nCafe Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= numItems) {
        printf("\nYou ordered %s\n", items[choice-1].name);
    } else {
        printf("\nInvalid choice!\n");
    }
}

void placeOrder(Order orders[], int *numOrders) {
    char name[50];

    printf("\nEnter your name: ");
    scanf("%s", name);

    strcpy(orders[*numOrders].name, name);
    orders[*numOrders].quantity = 1;
    orders[*numOrders].price = 0;

    (*numOrders)++;
}

void displayOrder(Order orders[], int numOrders) {
    int i;

    printf("\nYour order:\n");
    for (i = 0; i < numOrders; i++) {
        printf("%s - $%.2f\n", orders[i].name, orders[i].price);
    }
}

void calculateTotal(Item items[], Order orders[], int numOrders) {
    int i;
    float total = 0;

    for (i = 0; i < numOrders; i++) {
        int index;

        for (index = 0; index < MAX_ITEMS; index++) {
            if (strcmp(items[index].name, orders[i].name) == 0) {
                orders[i].price = items[index].price;
                break;
            }
        }

        if (index == MAX_ITEMS) {
            printf("\nItem not found in menu!\n");
            exit(0);
        }

        total += orders[i].price * orders[i].quantity;
    }

    printf("\nTotal amount: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;
    Order orders[MAX_ITEMS];
    int numOrders = 0;

    addItem(items, &numItems);

    while (numOrders == 0) {
        displayMenu(items, numItems);
        placeOrder(orders, &numOrders);
    }

    displayOrder(orders, numOrders);
    calculateTotal(items, orders, numOrders);

    return 0;
}