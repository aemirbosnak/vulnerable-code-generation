//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 // maximum number of items that can be stored
#define MAX_NAME 50 // maximum length of item name
#define MAX_QUANTITY 100 // maximum quantity of an item that can be stored

struct Item {
    char name[MAX_NAME]; // name of the item
    int quantity; // quantity of the item
};

void addItem(struct Item* items, int numItems, char* name, int quantity) {
    if (numItems == MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }
    strcpy(items[numItems].name, name);
    items[numItems].quantity = quantity;
    numItems++;
}

void updateItemQuantity(struct Item* items, int numItems, char* name, int quantity) {
    int i;
    for (i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity += quantity;
            return;
        }
    }
    printf("Error: Item not found.\n");
}

void displayItems(struct Item* items, int numItems) {
    int i;
    for (i = 0; i < numItems; i++) {
        printf("%s: %d\n", items[i].name, items[i].quantity);
    }
}

int main() {
    struct Item items[MAX_ITEMS];
    int numItems = 0;
    char choice;
    do {
        printf("1. Add item\n");
        printf("2. Update item quantity\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter item name: ");
                char name[MAX_NAME];
                scanf("%s", name);
                printf("Enter item quantity: ");
                int quantity;
                scanf("%d", &quantity);
                addItem(items, numItems, name, quantity);
                break;
            case '2':
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                updateItemQuantity(items, numItems, name, quantity);
                break;
            case '3':
                displayItems(items, numItems);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    } while (choice!= '4');
    return 0;
}