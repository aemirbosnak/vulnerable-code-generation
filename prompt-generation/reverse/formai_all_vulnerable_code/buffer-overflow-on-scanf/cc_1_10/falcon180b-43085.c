//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    char name[50];
    float price;
} Item;

void addItem(Item items[], int *numItems) {
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);
    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
}

void displayMenu(Item items[], int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }
}

void placeOrder(Item items[], int numItems, int *order, int *numOrders) {
    printf("Enter order:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s\n", i + 1, items[i].name);
    }
    scanf("%d", order + *numOrders);
    (*numOrders)++;
}

void calculateTotal(Item items[], int numItems, int order[], int numOrders) {
    float total = 0;
    for (int i = 0; i < numOrders; i++) {
        total += items[order[i] - 1].price;
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;
    addItem(items, &numItems);
    addItem(items, &numItems);
    addItem(items, &numItems);

    int order[MAX_ITEMS];
    int numOrders = 0;

    int choice;
    while (1) {
        printf("1. Place order\n2. Display menu\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            placeOrder(items, numItems, order, &numOrders);
            break;
        case 2:
            displayMenu(items, numItems);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}