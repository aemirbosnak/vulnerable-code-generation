//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} Item;

void addItem(Item *items, int *numItems) {
    printf("Enter the name of the item: ");
    scanf("%s", items[*numItems].name);

    printf("Enter the price of the item: ");
    scanf("%s", items[*numItems].price);

    (*numItems)++;
}

void printItems(Item *items, int numItems) {
    printf("Items:\n");

    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - %s\n", i+1, items[i].name, items[i].price);
    }
}

void main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    addItem(items, &numItems);

    while (1) {
        printItems(items, numItems);

        printf("1. Add item\n");
        printf("2. Print items\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &numItems);
                break;
            case 2:
                printItems(items, numItems);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}