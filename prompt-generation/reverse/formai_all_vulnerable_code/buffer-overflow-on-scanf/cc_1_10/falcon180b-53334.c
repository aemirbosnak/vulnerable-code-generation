//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

void addItem(Item* items, int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);
    printf("\n");
}

void displayItems(Item* items, int numItems) {
    printf("Item\tPrice\tQuantity\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculateTotal(Item* items, int numItems) {
    float total = 0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("\nTotal cost: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    do {
        printf("\nEnter 1 to add an item, 2 to display items, 3 to calculate total, or 0 to quit:\n");
        scanf("%d", &numItems);

        switch (numItems) {
        case 1:
            if (numItems >= MAX_ITEMS) {
                printf("Maximum number of items reached.\n");
            } else {
                addItem(items, numItems);
                numItems++;
            }
            break;

        case 2:
            displayItems(items, numItems);
            break;

        case 3:
            calculateTotal(items, numItems);
            break;

        case 0:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid option selected.\n");
        }

    } while (numItems > 0);

    return 0;
}