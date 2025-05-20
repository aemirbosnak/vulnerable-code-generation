//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

void addItem(Item *items, int *numItems) {
    printf("Enter item name: ");
    scanf("%s", (*numItems == 0)? items[0].name : items[*numItems - 1].name);
    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[*numItems].quantity);
    (*numItems)++;
}

void displayItems(Item *items, int numItems) {
    printf("\nItem\t\tPrice\t\tQuantity\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t\t%.2f\t\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculateTotalCost(Item *items, int numItems) {
    float totalCost = 0.0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].price * items[i].quantity;
    }
    printf("\nTotal cost: $%.2f\n", totalCost);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    while (1) {
        printf("\nOptions:\n1. Add item\n2. Display items\n3. Calculate total cost\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numItems >= MAX_ITEMS) {
                printf("Maximum number of items reached.\n");
            } else {
                addItem(items, &numItems);
            }
            break;
        case 2:
            if (numItems == 0) {
                printf("No items added yet.\n");
            } else {
                displayItems(items, numItems);
            }
            break;
        case 3:
            if (numItems == 0) {
                printf("No items added yet.\n");
            } else {
                calculateTotalCost(items, numItems);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}