//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Struct to hold item details
typedef struct {
    char name[50];
    float price;
    int quantity;
} item;

// Function to compare item prices
int comparePrices(const void *a, const void *b) {
    item *ia = (item *)a;
    item *ib = (item *)b;
    if (ia->price < ib->price)
        return -1;
    else if (ia->price > ib->price)
        return 1;
    else
        return 0;
}

// Function to print item details
void printItem(item i) {
    printf("Name: %s\n", i.name);
    printf("Price: $%.2f\n", i.price);
    printf("Quantity: %d\n", i.quantity);
    printf("\n");
}

// Function to calculate total cost of items
float calculateTotalCost(item *items, int numItems) {
    float totalCost = 0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].price * items[i].quantity;
    }
    return totalCost;
}

int main() {
    int numItems;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    item *items = (item *)malloc(numItems * sizeof(item));

    for (int i = 0; i < numItems; i++) {
        printf("Enter item details for item %d:\n", i+1);
        printf("Name: ");
        scanf("%s", items[i].name);
        printf("Price: ");
        scanf("%f", &items[i].price);
        printf("Quantity: ");
        scanf("%d", &items[i].quantity);
    }

    // Sort items by price
    qsort(items, numItems, sizeof(item), comparePrices);

    // Print item details
    printf("Item details:\n");
    for (int i = 0; i < numItems; i++) {
        printItem(items[i]);
    }

    // Calculate total cost of items
    float totalCost = calculateTotalCost(items, numItems);
    printf("\nTotal cost: $%.2f\n", totalCost);

    free(items);
    return 0;
}