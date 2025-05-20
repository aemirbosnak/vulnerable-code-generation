//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LEN 50

typedef struct {
    int id;
    char name[ITEM_NAME_LEN];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

void addItem(int id, const char *name, int quantity) {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    
    warehouse[itemCount].id = id;
    strncpy(warehouse[itemCount].name, name, ITEM_NAME_LEN);
    warehouse[itemCount].quantity = quantity;
    itemCount++;
    
    printf("Item added: [ID: %d, Name: %s, Quantity: %d]\n", id, name, quantity);
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items in warehouse.\n");
        return;
    }

    printf("Current items in the warehouse:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }
}

void removeItem(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (warehouse[i].id == id) {
            printf("Removing item: [ID: %d, Name: %s, Quantity: %d]\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
            warehouse[i] = warehouse[itemCount - 1];
            itemCount--;
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void updateItemQuantity(int id, int quantity) {
    for (int i = 0; i < itemCount; i++) {
        if (warehouse[i].id == id) {
            warehouse[i].quantity += quantity;
            printf("Updated item: [ID: %d, Name: %s, Quantity: %d]\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void searchItem(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (warehouse[i].id == id) {
            printf("Item found: [ID: %d, Name: %s, Quantity: %d]\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void menu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Remove Item\n");
    printf("4. Update Item Quantity\n");
    printf("5. Search Item\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    int id, quantity;
    char name[ITEM_NAME_LEN];
    
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                addItem(id, name, quantity);
                break;
            case 2:
                displayItems();
                break;
            case 3:
                printf("Enter item ID to remove: ");
                scanf("%d", &id);
                removeItem(id);
                break;
            case 4:
                printf("Enter item ID to update quantity: ");
                scanf("%d", &id);
                printf("Enter quantity change (can be negative): ");
                scanf("%d", &quantity);
                updateItemQuantity(id, quantity);
                break;
            case 5:
                printf("Enter item ID to search: ");
                scanf("%d", &id);
                searchItem(id);
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}