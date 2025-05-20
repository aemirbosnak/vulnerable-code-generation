//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} Item;

void addItem(Item *items, int *numItems) {
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);
    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
    (*numItems)++;
}

void displayItems(Item *items, int numItems) {
    printf("Item Name\tPrice\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%.2f\n", items[i].name, items[i].price);
    }
}

void calculateTotal(Item *items, int numItems) {
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].price;
    }
    printf("Total Expense: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    printf("Enter number of items: ");
    scanf("%d", &numItems);

    for (int i = 0; i < numItems; i++) {
        addItem(items, &numItems);
    }

    displayItems(items, numItems);
    calculateTotal(items, numItems);

    return 0;
}