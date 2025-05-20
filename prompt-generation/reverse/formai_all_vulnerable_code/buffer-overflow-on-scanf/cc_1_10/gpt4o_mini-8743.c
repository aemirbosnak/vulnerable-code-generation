//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    int id;
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem();
void viewInventory();
void updateItem();
void removeItem();
void searchItem();
void displayMenu();

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
                viewInventory();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                removeItem();
                break;
            case 5:
                searchItem();
                break;
            case 6:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n--- Warehouse Management System ---\n");
    printf("1. Add Item\n");
    printf("2. View Inventory\n");
    printf("3. Update Item\n");
    printf("4. Remove Item\n");
    printf("5. Search Item\n");
    printf("6. Exit\n");
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }
    
    Item newItem;
    newItem.id = itemCount + 1; // Assigning a new ID
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter price: ");
    scanf("%f", &newItem.price);
    
    inventory[itemCount++] = newItem;
    printf("Item added: %s (ID: %d, Quantity: %d, Price: %.2f)\n", newItem.name, newItem.id, newItem.quantity, newItem.price);
}

void viewInventory() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    
    printf("\n--- Inventory List ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateItem() {
    int id, found = 0;
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Updating Item: %s\n", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Item updated successfully.\n");
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
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item with ID %d removed successfully.\n", id);
            break;
        }
    }
    
    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void searchItem() {
    char name[ITEM_NAME_LENGTH];
    printf("Enter item name to search: ");
    scanf("%s", name);
    int found = 0;

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Found Item: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item with name '%s' not found.\n", name);
    }
}