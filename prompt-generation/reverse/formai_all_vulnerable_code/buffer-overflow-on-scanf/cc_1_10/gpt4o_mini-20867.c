//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

// Function declarations
void addItem();
void updateItem();
void deleteItem();
void displayItems();
void calculateValue();

int main() {
    int choice;
    do {
        printf("\n=== Warehouse Management System ===\n");
        printf("1. Add Item\n");
        printf("2. Update Item\n");
        printf("3. Delete Item\n");
        printf("4. Display All Items\n");
        printf("5. Calculate Total Inventory Value\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                deleteItem();
                break;
            case 4:
                displayItems();
                break;
            case 5:
                calculateValue();
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Error: Warehouse is full! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    newItem.id = itemCount + 1; // Simple ID generation
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter price: ");
    scanf("%f", &newItem.price);
    
    warehouse[itemCount] = newItem;
    itemCount++;
    printf("Item %s added successfully with ID %d.\n", newItem.name, newItem.id);
}

void updateItem() {
    int id, found = 0;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < itemCount; i++) {
        if (warehouse[i].id == id) {
            found = 1;
            printf("Updating item %s (Current quantity: %d, Current price: %.2f)\n", warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &warehouse[i].price);
            printf("Item updated successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Error: Item with ID %d not found.\n", id);
    }
}

void deleteItem() {
    int id, found = 0;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < itemCount; i++) {
        if (warehouse[i].id == id) {
            found = 1;
            for (int j = i; j < itemCount - 1; j++) {
                warehouse[j] = warehouse[j + 1]; // Shift items left
            }
            itemCount--;
            printf("Item with ID %d deleted successfully.\n", id);
            break;
        }
    }
    
    if (!found) {
        printf("Error: Item with ID %d not found.\n", id);
    }
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    
    printf("\n=== Warehouse Inventory ===\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

void calculateValue() {
    float totalValue = 0.0;
    for (int i = 0; i < itemCount; i++) {
        totalValue += warehouse[i].quantity * warehouse[i].price;
    }
    printf("Total Inventory Value: %.2f\n", totalValue);
}