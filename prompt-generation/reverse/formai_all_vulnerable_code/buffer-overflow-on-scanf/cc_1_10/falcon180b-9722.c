//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QTY_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_NAME_LEN];
    int qty;
    float price;
} Item;

void addItem(Item* items, int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter item description: ");
    scanf("%s", items[numItems].description);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].qty);
    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);
}

void displayItems(Item* items, int numItems) {
    printf("\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d:\n", i+1);
        printf("Name: %s\n", items[i].name);
        printf("Description: %s\n", items[i].description);
        printf("Quantity: %d\n", items[i].qty);
        printf("Price: $%.2f\n", items[i].price);
        printf("\n");
    }
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    printf("Enter number of items: ");
    scanf("%d", &numItems);

    if (numItems > MAX_ITEMS) {
        printf("Error: Maximum number of items is %d.\n", MAX_ITEMS);
        return 1;
    }

    for (int i = 0; i < numItems; i++) {
        addItem(items, i);
    }

    displayItems(items, numItems);

    return 0;
}