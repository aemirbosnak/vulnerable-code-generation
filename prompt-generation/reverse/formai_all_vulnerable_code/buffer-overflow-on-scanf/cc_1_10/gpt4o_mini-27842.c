//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
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

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    Item newItem;
    newItem.id = itemCount + 1;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    warehouse[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully!\n");
}

void removeItem() {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);

    if (id < 1 || id > itemCount) {
        printf("Item not found!\n");
        return;
    }

    for (int i = id - 1; i < itemCount - 1; i++) {
        warehouse[i] = warehouse[i + 1];
    }
    
    itemCount--;
    printf("Item removed successfully!\n");
}

void listItems() {
    if (itemCount == 0) {
        printf("No items in warehouse.\n");
        return;
    }
    
    printf("ID\tName\t\tQuantity\n");
    printf("---------------------------------\n");

    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }
}

void searchItem() {
    char name[NAME_LENGTH];
    printf("Enter item name to search: ");
    scanf("%s", name);
    
    int found = 0;
    printf("Search results:\n");
    printf("---------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            printf("ID: %d, Quantity: %d\n", warehouse[i].id, warehouse[i].quantity);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Item not found.\n");
    }
}

void updateItem() {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > itemCount) {
        printf("Item not found!\n");
        return;
    }

    int newQuantity;
    printf("Enter new quantity for %s: ", warehouse[id - 1].name);
    scanf("%d", &newQuantity);
    warehouse[id - 1].quantity = newQuantity;
    printf("Item updated successfully!\n");
}

void displayMenu() {
    printf("\n--- Warehouse Management System ---\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. List Items\n");
    printf("4. Search Item\n");
    printf("5. Update Item\n");
    printf("6. Exit\n");
    printf("---------------------------------\n");
}

int main() {
    int choice;

    do {
        displayMenu();
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
                listItems();
                break;
            case 4:
                searchItem();
                break;
            case 5:
                updateItem();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}