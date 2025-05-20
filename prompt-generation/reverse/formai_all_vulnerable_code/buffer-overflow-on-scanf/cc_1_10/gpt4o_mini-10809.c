//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_SIZE 50

typedef struct {
    int id;
    char name[NAME_SIZE];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full, cannot add more items.\n");
        return;
    }
    
    Item newItem;
    
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    getchar(); // clear newline character from input buffer
    
    printf("Enter item name: ");
    fgets(newItem.name, NAME_SIZE, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // remove newline
    
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    
    printf("Item added successfully!\n");
}

void displayItems(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    
    printf("\nItems in Warehouse:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

void updateItem(Warehouse *warehouse) {
    int itemId, newQuantity;
    
    printf("Enter the item ID to update: ");
    scanf("%d", &itemId);
    
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == itemId) {
            printf("Current quantity of %s: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            warehouse->items[i].quantity = newQuantity;
            printf("Item updated successfully!\n");
            return;
        }
    }
    
    printf("Item with ID %d not found.\n", itemId);
}

void deleteItem(Warehouse *warehouse) {
    int itemId;
    
    printf("Enter the item ID to delete: ");
    scanf("%d", &itemId);
    
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == itemId) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item deleted successfully!\n");
            return;
        }
    }
    
    printf("Item with ID %d not found.\n", itemId);
}

int main() {
    Warehouse warehouse;
    warehouse.count = 0;
    
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                displayItems(&warehouse);
                break;
            case 3:
                updateItem(&warehouse);
                break;
            case 4:
                deleteItem(&warehouse);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}