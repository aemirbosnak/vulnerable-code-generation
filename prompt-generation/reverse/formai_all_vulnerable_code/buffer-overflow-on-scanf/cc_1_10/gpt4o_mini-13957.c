//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: careful
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

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initWarehouse(Warehouse* warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse* warehouse, int id, const char* name, int quantity) {
    if (warehouse->count < MAX_ITEMS) {
        warehouse->items[warehouse->count].id = id;
        strncpy(warehouse->items[warehouse->count].name, name, NAME_LENGTH);
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->count++;
        printf("Item added: ID = %d, Name = %s, Quantity = %d\n", id, name, quantity);
    } else {
        printf("Warehouse is full! Cannot add more items.\n");
    }
}

void viewItems(const Warehouse* warehouse) {
    if (warehouse->count == 0) {
        printf("No items in warehouse.\n");
        return;
    }
    
    printf("Items in warehouse:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", 
                warehouse->items[i].id, 
                warehouse->items[i].name, 
                warehouse->items[i].quantity);
    }
}

void updateItem(Warehouse* warehouse, int id, int quantity) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i].quantity = quantity;
            printf("Updated Item ID: %d, New Quantity: %d\n", id, quantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void removeItem(Warehouse* warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            // Shift items down to fill the gap
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Removed item with ID %d\n", id);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Update Item\n");
    printf("4. Remove Item\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    Warehouse warehouse;
    initWarehouse(&warehouse);
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        if (choice == 5) {
            break;
        }
        
        int id, quantity;
        char name[NAME_LENGTH];

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                addItem(&warehouse, id, name, quantity);
                break;
            case 2:
                viewItems(&warehouse);
                break;
            case 3:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                printf("Enter new Quantity: ");
                scanf("%d", &quantity);
                updateItem(&warehouse, id, quantity);
                break;
            case 4:
                printf("Enter ID to remove: ");
                scanf("%d", &id);
                removeItem(&warehouse, id);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    printf("Exiting the Warehouse Management System. Goodbye!\n");
    return 0;
}