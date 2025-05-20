//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} Item;

void addItem(Item items[], int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);
    printf("Enter item price: ");
    scanf("%lf", &items[numItems].price);
    numItems++;
}

void displayItems(Item items[], int numItems) {
    printf("\nItem List:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - %d in stock - $%.2f each\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void searchItem(Item items[], int numItems) {
    printf("\nEnter item name to search: ");
    char searchName[MAX_NAME_LENGTH];
    scanf("%s", searchName);
    int found = 0;
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, searchName) == 0) {
            printf("\nItem found:\n");
            printf("%s - %d in stock - $%.2f each\n", items[i].name, items[i].quantity, items[i].price);
            found = 1;
        }
    }
    if (found == 0) {
        printf("\nItem not found.\n");
    }
}

void updateItemQuantity(Item items[], int numItems) {
    printf("\nEnter item name to update quantity: ");
    char updateName[MAX_NAME_LENGTH];
    scanf("%s", updateName);
    int found = 0;
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, updateName) == 0) {
            printf("\nEnter new quantity: ");
            scanf("%d", &items[i].quantity);
            found = 1;
        }
    }
    if (found == 0) {
        printf("\nItem not found.\n");
    }
}

void main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    while (numItems < MAX_ITEMS) {
        printf("\nChoose an option:\n");
        printf("1. Add item\n");
        printf("2. Display item list\n");
        printf("3. Search item\n");
        printf("4. Update item quantity\n");
        printf("5. Exit\n");
        scanf("%d", &numItems);

        switch (numItems) {
            case 1:
                addItem(items, numItems);
                break;
            case 2:
                displayItems(items, numItems);
                break;
            case 3:
                searchItem(items, numItems);
                break;
            case 4:
                updateItemQuantity(items, numItems);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid option.\n");
        }
    }
}