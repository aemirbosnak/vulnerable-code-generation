//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME 50
#define MAX_DESCRIPTION 100
#define MAX_PRICE 10
#define MAX_AMOUNT 10

typedef struct {
    char name[MAX_NAME];
    char description[MAX_DESCRIPTION];
    char price[MAX_PRICE];
    int amount;
} Item;

void addItem(Item* items, int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);

    printf("Enter item description: ");
    scanf("%s", items[numItems].description);

    printf("Enter item price: ");
    scanf("%s", items[numItems].price);

    printf("Enter item amount: ");
    scanf("%d", &items[numItems].amount);
}

void displayItems(Item* items, int numItems) {
    printf("\nItem Name\tItem Description\tItem Price\tItem Amount\n");

    for (int i = 0; i < numItems; i++) {
        printf("%-20s%-40s%-10s%d\n", items[i].name, items[i].description, items[i].price, items[i].amount);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    while (numItems < MAX_ITEMS) {
        printf("\nDo you want to add an item? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            addItem(items, numItems);
            numItems++;
        } else {
            printf("\nExiting program...\n");
            break;
        }
    }

    printf("\nInventory:\n");
    displayItems(items, numItems);

    return 0;
}