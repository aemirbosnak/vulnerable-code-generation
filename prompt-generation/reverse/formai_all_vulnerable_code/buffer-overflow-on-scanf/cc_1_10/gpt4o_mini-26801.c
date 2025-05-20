//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

// Function prototypes
void addItem();
void removeItem();
void viewItems();
void searchItem();

int main() {
    int choice;
    while (1) {
        printf("\n*** Warehouse Management System ***\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Items\n");
        printf("4. Search Item\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                viewItems();
                break;
            case 4:
                searchItem();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    warehouse[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void removeItem() {
    int id, i, found = 0;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    for (i = 0; i < itemCount; i++) {
        if (warehouse[i].id == id) {
            for (int j = i; j < itemCount - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            itemCount--;
            printf("Item removed successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found!\n", id);
    }
}

void viewItems() {
    if (itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    printf("\nCurrent items in warehouse:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }
}

void searchItem() {
    int id, found = 0;
    printf("Enter item ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < itemCount; i++) {
        if (warehouse[i].id == id) {
            printf("Item found - ID: %d, Name: %s, Quantity: %d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found!\n", id);
    }
}