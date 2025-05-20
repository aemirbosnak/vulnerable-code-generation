//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_DESCRIPTION_SIZE 50

typedef struct Item {
    int id;
    char description[MAX_DESCRIPTION_SIZE];
    int quantity;
} Item;

Item items[MAX_ITEMS];
int numItems = 0;

void addItem() {
    if (numItems < MAX_ITEMS) {
        Item newItem;
        printf("Enter item ID: ");
        scanf("%d", &newItem.id);
        printf("Enter item description: ");
        scanf("%s", &newItem.description);
        printf("Enter item quantity: ");
        scanf("%d", &newItem.quantity);

        items[numItems++] = newItem;
        printf("Item successfully added.\n");
    } else {
        printf("Maximum number of items reached. Cannot add more items.\n");
    }
}

void removeItem() {
    int idToRemove;
    printf("Enter item ID to remove: ");
    scanf("%d", &idToRemove);

    int foundIndex = -1;
    for (int i = 0; i < numItems; i++) {
        if (items[i].id == idToRemove) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < numItems - 1; i++) {
            items[i] = items[i + 1];
        }

        numItems--;
        printf("Item successfully removed.\n");
    } else {
        printf("Item with ID %d not found.\n", idToRemove);
    }
}

void viewInventory() {
    printf("Inventory:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d - %s - %d\n", items[i].id, items[i].description, items[i].quantity);
    }
}

int main() {
    int choice;
    do {
        printf("What do you want to do?\n");
        printf("1 - Add item\n");
        printf("2 - Remove item\n");
        printf("3 - View inventory\n");
        printf("4 - Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                viewInventory();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}