//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Update Item\n");
    printf("3. Remove Item\n");
    printf("4. Display Items\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addItem() {
    if (itemCount < MAX_ITEMS) {
        Item newItem;
        printf("Enter item ID: ");
        scanf("%d", &newItem.id);
        printf("Enter item name: ");
        scanf(" %[^\n]", newItem.name);
        printf("Enter item quantity: ");
        scanf("%d", &newItem.quantity);

        warehouse[itemCount] = newItem;
        itemCount++;
        printf("Item added successfully!\n");
    } else {
        printf("Warehouse is full! Cannot add new items.\n");
    }
}

void updateItem() {
    int id, found = 0;
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (warehouse[i].id == id) {
            printf("Updating Item: %s\n", warehouse[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse[i].quantity);
            printf("Item updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void removeItem() {
    int id, found = 0;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
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
        printf("Item with ID %d not found.\n", id);
    }
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    printf("\nItems in the warehouse:\n");
    printf("ID\tName\t\tQuantity\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t%d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                displayItems();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}