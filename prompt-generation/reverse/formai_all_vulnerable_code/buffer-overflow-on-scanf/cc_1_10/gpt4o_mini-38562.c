//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse, int id, const char *name, int quantity) {
    if (warehouse->count < MAX_ITEMS) {
        warehouse->items[warehouse->count].id = id;
        strcpy(warehouse->items[warehouse->count].name, name);
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->count++;
        printf("Item added: %s (ID: %d, Quantity: %d)\n", name, id, quantity);
    } else {
        printf("Warehouse is full! Cannot add more items.\n");
    }
}

void viewItems(const Warehouse *warehouse) {
    printf("\nCurrent items in the warehouse:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n",
               warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void updateItemQuantity(Warehouse *warehouse, int id, int newQuantity) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i].quantity = newQuantity;
            printf("Updated item ID %d to new quantity: %d\n", id, newQuantity);
            return;
        }
    }
    printf("Item ID %d not found in the warehouse.\n", id);
}

void removeItem(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Removed item ID: %d\n", id);
            return;
        }
    }
    printf("Item ID %d not found in the warehouse.\n", id);
}

void displayMenu() {
    printf("\nWarehouse Management System Menu:\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Update Item Quantity\n");
    printf("4. Remove Item\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice, id, quantity;
    char name[50];

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Item ID: ");
                scanf("%d", &id);
                printf("Enter Item Name: ");
                scanf("%s", name);
                printf("Enter Item Quantity: ");
                scanf("%d", &quantity);
                addItem(&warehouse, id, name, quantity);
                break;
            case 2:
                viewItems(&warehouse);
                break;
            case 3:
                printf("Enter Item ID to update: ");
                scanf("%d", &id);
                printf("Enter New Quantity: ");
                scanf("%d", &quantity);
                updateItemQuantity(&warehouse, id, quantity);
                break;
            case 4:
                printf("Enter Item ID to remove: ");
                scanf("%d", &id);
                removeItem(&warehouse, id);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}