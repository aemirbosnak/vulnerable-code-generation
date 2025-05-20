//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

void addItem(Item items[], int *numItems) {
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);
    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[*numItems].quantity);
    (*numItems)++;
}

void displayItems(Item items[], int numItems) {
    printf("\nItems:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f - %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculateTotal(Item items[], int numItems) {
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("\nTotal: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    addItem(items, &numItems);
    addItem(items, &numItems);
    addItem(items, &numItems);

    displayItems(items, numItems);
    calculateTotal(items, numItems);

    return 0;
}