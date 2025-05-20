//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

// Define a structure for an inventory item
typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

// Global inventory
Item inventory[MAX_ITEMS];
int itemCount = 0;

// Function declarations
void addItem();
void viewInventory();
void removeItem();
void updateItem();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. View Inventory\n");
        printf("3. Remove Item\n");
        printf("4. Update Item\n");
        printf("5. Exit\n");
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
                removeItem();
                break;
            case 4:
                updateItem();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }
    Item newItem;
    newItem.id = itemCount + 1; // simple id assignment
    printf("Enter item name: ");
    getchar(); // Clear newline character from the buffer
    fgets(newItem.name, NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove newline
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    inventory[itemCount++] = newItem; // Add item to inventory
    printf("Item added successfully!\n");
}

void viewInventory() {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }
    printf("\nInventory:\n");
    printf("%-5s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < itemCount; i++) {
        printf("%-5d %-30s %-10d %-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void removeItem() {
    int id;
    printf("Enter the ID of the item to remove: ");
    scanf("%d", &id);
    if (id < 1 || id > itemCount) {
        printf("Invalid item ID.\n");
        return;
    }
    for (int i = id - 1; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1]; // Shift items
    }
    itemCount--; // Reduce item count
    printf("Item removed successfully!\n");
}

void updateItem() {
    int id;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);
    if (id < 1 || id > itemCount) {
        printf("Invalid item ID.\n");
        return;
    }
    Item *item = &inventory[id - 1];
    printf("Updating item: %s (Quantity: %d, Price: %.2f)\n", item->name, item->quantity, item->price);
    
    printf("Enter new quantity (current: %d): ", item->quantity);
    scanf("%d", &item->quantity);
    printf("Enter new price (current: %.2f): ", item->price);
    scanf("%f", &item->price);
    
    printf("Item updated successfully!\n");
}