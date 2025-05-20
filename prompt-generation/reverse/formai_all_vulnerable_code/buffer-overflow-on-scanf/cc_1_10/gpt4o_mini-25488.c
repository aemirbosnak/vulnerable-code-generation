//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: all-encompassing
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

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse, int id, const char* name, int quantity, float price) {
    if (warehouse->count < MAX_ITEMS) {
        Item newItem;
        newItem.id = id;
        strcpy(newItem.name, name);
        newItem.quantity = quantity;
        newItem.price = price;

        warehouse->items[warehouse->count] = newItem;
        warehouse->count++;
    } else {
        printf("Error: Warehouse is full, cannot add more items.\n");
    }
}

void removeItem(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item with ID %d has been removed.\n", id);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void updateItem(Warehouse *warehouse, int id, int quantity, float price) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i].quantity = quantity;
            warehouse->items[i].price = price;
            printf("Item with ID %d has been updated.\n", id);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void displayItems(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < warehouse->count; i++) {
        Item item = warehouse->items[i];
        printf("%-5d %-20s %-10d $%-9.2f\n", item.id, item.name, item.quantity, item.price);
    }
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice, id, quantity;
    float price;
    char name[50];

    do {
        printf("\n--- Warehouse Management System ---\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Item\n");
        printf("4. Display All Items\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Item ID: ");
                scanf("%d", &id);
                printf("Enter Item Name: ");
                scanf(" %[^\n]", name);  // Read string with spaces
                printf("Enter Item Quantity: ");
                scanf("%d", &quantity);
                printf("Enter Item Price: ");
                scanf("%f", &price);
                addItem(&warehouse, id, name, quantity, price);
                break;
            case 2:
                printf("Enter Item ID to remove: ");
                scanf("%d", &id);
                removeItem(&warehouse, id);
                break;
            case 3:
                printf("Enter Item ID to update: ");
                scanf("%d", &id);
                printf("Enter new Item Quantity: ");
                scanf("%d", &quantity);
                printf("Enter new Item Price: ");
                scanf("%f", &price);
                updateItem(&warehouse, id, quantity, price);
                break;
            case 4:
                displayItems(&warehouse);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}