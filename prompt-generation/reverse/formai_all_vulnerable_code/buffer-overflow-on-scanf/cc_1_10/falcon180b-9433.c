//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Item;

void createItem(Item* item) {
    printf("Enter the name of the item: ");
    scanf("%s", item->name);
    printf("Enter the quantity of the item: ");
    scanf("%d", &item->quantity);
}

void displayItem(Item item) {
    printf("Name: %s\n", item.name);
    printf("Quantity: %d\n", item.quantity);
}

void main() {
    char choice;
    Item items[MAX_ITEMS];
    int numItems = 0;

    while (1) {
        printf("\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (numItems >= MAX_ITEMS) {
                printf("Cannot add more items.\n");
            } else {
                createItem(&items[numItems]);
                numItems++;
            }
            break;

        case '2':
            printf("\n");
            for (int i = 0; i < numItems; i++) {
                displayItem(items[i]);
            }
            break;

        case '3':
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
}