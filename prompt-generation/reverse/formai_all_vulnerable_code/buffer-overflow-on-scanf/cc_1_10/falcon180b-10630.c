//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float cost;
} Item;

void addItem(Item items[], int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter item cost: ");
    scanf("%f", &items[numItems].cost);
    numItems++;
}

void displayItems(Item items[], int numItems) {
    printf("Item\t\tCost\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%.2f\n", items[i].name, items[i].cost);
    }
}

void calculateTotalCost(Item items[], int numItems) {
    float totalCost = 0.0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].cost;
    }
    printf("Total cost: %.2f\n", totalCost);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter your items and their costs.\n");

    while (numItems < MAX_ITEMS) {
        addItem(items, numItems);
    }

    displayItems(items, numItems);
    calculateTotalCost(items, numItems);

    return 0;
}