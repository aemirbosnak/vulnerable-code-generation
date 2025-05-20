//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }
    Item newItem;
    newItem.id = itemCount + 1; // Simple ID generation
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    inventory[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully! ID: %d\n", newItem.id);
}

void removeItem() {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    if (id <= 0 || id > itemCount) {
        printf("Invalid ID. Item not found!\n");
        return;
    }
    
    for (int i = id - 1; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    itemCount--;
    printf("Item removed successfully!\n");
}

void updateItem() {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    if (id <= 0 || id > itemCount) {
        printf("Invalid ID. Item not found!\n");
        return;
    }
    Item *item = &inventory[id - 1];
    printf("Updating item: %s\n", item->name);
    printf("Enter new quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter new price: ");
    scanf("%f", &item->price);
    printf("Item updated successfully!\n");
}

void listItems() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("Inventory List:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchItem() {
    char name[50];
    printf("Enter item name to search: ");
    scanf("%s", name);
    printf("Searching for item: %s\n", name);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Item found! ID: %d, Quantity: %d, Price: %.2f\n", inventory[i].id, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item not found.\n");
}

void displayMenu() {
    printf("Warehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Update Item\n");
    printf("4. List Items\n");
    printf("5. Search Item\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                listItems();
                break;
            case 5:
                searchItem();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 6);
    
    return 0;
}