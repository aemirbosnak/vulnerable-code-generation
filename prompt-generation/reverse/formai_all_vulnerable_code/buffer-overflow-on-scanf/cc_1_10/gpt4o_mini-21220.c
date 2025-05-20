//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    int id;
    char name[50];
    int quantity;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItemRecursively(int id, char *name, int quantity);
void searchItemRecursively(int id, int index);
void deleteItemRecursively(int id, int index);
void displayItemsRecursively(int index);
void displayMenu();

int main() {
    int choice, id, quantity;
    char name[50];

    while (1) {
        displayMenu();
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
                addItemRecursively(id, name, quantity);
                break;
            case 2:
                printf("Enter item ID to search: ");
                scanf("%d", &id);
                searchItemRecursively(id, 0);
                break;
            case 3:
                printf("Enter item ID to delete: ");
                scanf("%d", &id);
                deleteItemRecursively(id, 0);
                break;
            case 4:
                printf("Current Inventory:\n");
                displayItemsRecursively(0);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addItemRecursively(int id, char *name, int quantity) {
    if (itemCount < MAX_ITEMS) {
        inventory[itemCount].id = id;
        strcpy(inventory[itemCount].name, name);
        inventory[itemCount].quantity = quantity;
        itemCount++;
        printf("Item added successfully.\n");
    } else {
        printf("Inventory is full. Cannot add more items.\n");
    }
}

void searchItemRecursively(int id, int index) {
    if (index >= itemCount) {
        printf("Item not found.\n");
        return;
    }
    
    if (inventory[index].id == id) {
        printf("Item found: ID: %d, Name: %s, Quantity: %d\n", inventory[index].id, inventory[index].name, inventory[index].quantity);
        return;
    }
    
    searchItemRecursively(id, index + 1);
}

void deleteItemRecursively(int id, int index) {
    if (index >= itemCount) {
        printf("Item not found.\n");
        return;
    }
    
    if (inventory[index].id == id) {
        printf("Deleting item: ID: %d, Name: %s, Quantity: %d\n", inventory[index].id, inventory[index].name, inventory[index].quantity);
        for (int i = index; i < itemCount - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        itemCount--;
        printf("Item deleted successfully.\n");
        return;
    }
    
    deleteItemRecursively(id, index + 1);
}

void displayItemsRecursively(int index) {
    if (index >= itemCount) {
        return;
    }
    
    printf("ID: %d, Name: %s, Quantity: %d\n", inventory[index].id, inventory[index].name, inventory[index].quantity);
    displayItemsRecursively(index + 1);
}

void displayMenu() {
    printf("Warehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Search Item\n");
    printf("3. Delete Item\n");
    printf("4. Display Items\n");
    printf("5. Exit\n");
}