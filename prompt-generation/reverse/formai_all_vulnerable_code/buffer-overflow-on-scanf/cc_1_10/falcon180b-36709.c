//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: genious
/* C Expense Tracker */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} item;

void addItem(item *items, int *numItems) {
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);
    printf("Enter item price: ");
    scanf("%s", items[*numItems].price);
    (*numItems)++;
}

void removeItem(item *items, int *numItems) {
    printf("Enter item name to remove: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    int i;
    for (i = 0; i < *numItems; i++) {
        if (strcmp(items[i].name, name) == 0) {
            memmove(&items[i], &items[i + 1], (*numItems - i - 1) * sizeof(item));
            (*numItems)--;
            break;
        }
    }
}

void printItems(item *items, int numItems) {
    printf("Items:\n");
    int i;
    for (i = 0; i < numItems; i++) {
        printf("%s - $%s\n", items[i].name, items[i].price);
    }
}

void main() {
    item items[MAX_ITEMS];
    int numItems = 0;
    int choice;
    do {
        printf("C Expense Tracker\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Print items\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem(items, &numItems);
                break;
            case 2:
                removeItem(items, &numItems);
                break;
            case 3:
                printItems(items, numItems);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
}