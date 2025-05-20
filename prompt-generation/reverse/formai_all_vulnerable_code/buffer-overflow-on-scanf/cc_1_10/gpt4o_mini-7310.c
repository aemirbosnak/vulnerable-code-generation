//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
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

// Function prototypes
void addItem();
void viewInventory();
void updateItem();
void deleteItem();
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
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
                deleteItem();
                break;
            case 5:
                printf("Exiting the warehouse management system.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n--- Warehouse Management System ---\n");
    printf("1. Add Item\n");
    printf("2. View Inventory\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. Exit\n");
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    newItem.id = itemCount + 1;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    inventory[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully!\n");
}

void viewInventory() {
    if (itemCount == 0) {
        printf("The inventory is empty.\n");
        return;
    }
    
    printf("\n--- Current Inventory ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
            inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateItem() {
    int id;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);

    if (id < 1 || id > itemCount) {
        printf("Invalid item ID.\n");
        return;
    }

    int index = id - 1;
    printf("Updating Item: %s\n", inventory[index].name);
    printf("Enter new quantity: ");
    scanf("%d", &inventory[index].quantity);
    printf("Enter new price: ");
    scanf("%f", &inventory[index].price);
    
    printf("Item updated successfully!\n");
}

void deleteItem() {
    int id;
    printf("Enter the ID of the item to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > itemCount) {
        printf("Invalid item ID.\n");
        return;
    }

    int index = id - 1;
    
    for (int i = index; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    itemCount--;
    printf("Item deleted successfully!\n");
}