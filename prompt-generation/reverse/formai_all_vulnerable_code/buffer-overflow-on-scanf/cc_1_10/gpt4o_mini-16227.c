//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full, can't add more items!\n");
        return;
    }
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    
    warehouse[itemCount++] = newItem;
    printf("Item added successfully: %s (Qty: %d)\n", newItem.name, newItem.quantity);
}

void removeItem() {
    char name[ITEM_NAME_LENGTH];
    printf("Enter item name to remove: ");
    scanf("%s", name);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            itemCount--;
            printf("Item removed successfully: %s\n", name);
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

void viewItems() {
    if (itemCount == 0) {
        printf("The warehouse is empty!\n");
        return;
    }
    printf("Current items in warehouse:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%s - Quantity: %d\n", warehouse[i].name, warehouse[i].quantity);
    }
}

void warehouseMenu() {
    int choice;

    while (1) {
        printf("\nWelcome to the Warehouse Management System!\n");
        printf("1. Add new item\n");
        printf("2. Remove an item\n");
        printf("3. View items\n");
        printf("4. Exit\n");
        printf("Please enter your choice (1-4): ");
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
                printf("Exiting the Warehouse Management System. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!\n");
        }
    }
}

int main() {
    warehouseMenu();
    return 0;
}