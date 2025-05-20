//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
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

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse, int id, const char *name, int quantity, float price) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    warehouse->items[warehouse->count].id = id;
    strncpy(warehouse->items[warehouse->count].name, name, MAX_NAME_LENGTH);
    warehouse->items[warehouse->count].quantity = quantity;
    warehouse->items[warehouse->count].price = price;
    warehouse->count++;
    printf("Item '%s' added to warehouse.\n", name);
}

void removeItem(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item with ID %d removed from warehouse.\n", id);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void displayItems(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("Warehouse is empty.\n");
        return;
    }
    printf("Items in warehouse:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
               warehouse->items[i].id, warehouse->items[i].name,
               warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

void searchItem(const Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            printf("Item found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                   warehouse->items[i].id, warehouse->items[i].name,
                   warehouse->items[i].quantity, warehouse->items[i].price);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void updateItemQuantity(Warehouse *warehouse, int id, int new_quantity) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i].quantity = new_quantity;
            printf("Quantity of item ID %d updated to %d.\n", id, new_quantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice, id, quantity;
    char name[MAX_NAME_LENGTH];
    float price;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Search Item\n");
        printf("5. Update Item Quantity\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf(" %[^\n]", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                printf("Enter item price: ");
                scanf("%f", &price);
                addItem(&warehouse, id, name, quantity, price);
                break;
            case 2:
                printf("Enter item ID to remove: ");
                scanf("%d", &id);
                removeItem(&warehouse, id);
                break;
            case 3:
                displayItems(&warehouse);
                break;
            case 4:
                printf("Enter item ID to search: ");
                scanf("%d", &id);
                searchItem(&warehouse, id);
                break;
            case 5:
                printf("Enter item ID to update: ");
                scanf("%d", &id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateItemQuantity(&warehouse, id, quantity);
                break;
            case 6:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}