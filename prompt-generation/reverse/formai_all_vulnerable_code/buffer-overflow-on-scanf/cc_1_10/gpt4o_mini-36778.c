//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

// Function to initialize the warehouse
void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

// Function to add an item to the warehouse
void addItem(Warehouse *warehouse, const char *name, int quantity, float price) {
    if (warehouse->itemCount < MAX_ITEMS) {
        strcpy(warehouse->items[warehouse->itemCount].name, name);
        warehouse->items[warehouse->itemCount].quantity = quantity;
        warehouse->items[warehouse->itemCount].price = price;
        warehouse->itemCount++;
        printf("Added item: %s, Quantity: %d, Price: %.2f\n", name, quantity, price);
    } else {
        printf("Warehouse is full. Cannot add more items.\n");
    }
}

// Function to remove an item from the warehouse
void removeItem(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Removing item: %s\n", warehouse->items[i].name);
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

// Function to list all items in the warehouse
void listItems(const Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("Warehouse is empty.\n");
        return;
    }
    printf("Items in warehouse:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%d. %s - Quantity: %d, Price: %.2f\n", i + 1, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Function to update the quantity of an item
void updateQuantity(Warehouse *warehouse, const char *name, int quantity) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity = quantity;
            printf("Updated %s quantity to %d.\n", name, quantity);
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

// Function to search for an item
void searchItem(const Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Found item: %s - Quantity: %d, Price: %.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

// Main function to demonstrate the Warehouse Management System
int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;
    char name[NAME_LEN];
    int quantity;
    float price;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. List Items\n");
        printf("4. Update Quantity\n");
        printf("5. Search Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                addItem(&warehouse, name, quantity, price);
                break;
            case 2:
                printf("Enter item name to remove: ");
                scanf("%s", name);
                removeItem(&warehouse, name);
                break;
            case 3:
                listItems(&warehouse);
                break;
            case 4:
                printf("Enter item name to update: ");
                scanf("%s", name);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateQuantity(&warehouse, name, quantity);
                break;
            case 5:
                printf("Enter item name to search: ");
                scanf("%s", name);
                searchItem(&warehouse, name);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}