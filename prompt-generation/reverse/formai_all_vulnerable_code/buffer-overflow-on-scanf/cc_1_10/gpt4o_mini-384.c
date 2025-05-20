//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Ada Lovelace
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
    int itemCount;
} Warehouse;

// Function prototypes
void initializeWarehouse(Warehouse *warehouse);
void addItem(Warehouse *warehouse);
void removeItem(Warehouse *warehouse);
void displayItems(const Warehouse *warehouse);
void searchItem(const Warehouse *warehouse);
void updateItem(Warehouse *warehouse);

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Search Item\n");
        printf("5. Update Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(&warehouse); break;
            case 2: removeItem(&warehouse); break;
            case 3: displayItems(&warehouse); break;
            case 4: searchItem(&warehouse); break;
            case 5: updateItem(&warehouse); break;
            case 6: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice! Please choose a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    newItem.id = warehouse->itemCount + 1; // simple ID assignment
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    warehouse->items[warehouse->itemCount] = newItem;
    warehouse->itemCount++;
    printf("Item added successfully!\n");
}

void removeItem(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items to remove!\n");
        return;
    }

    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item ID not found!\n");
}

void displayItems(const Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items to display!\n");
        return;
    }

    printf("\nItems in Warehouse:\n");
    printf("ID | Name                | Quantity | Price\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%-2d | %-18s | %-8d | %.2f\n", warehouse->items[i].id,
               warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

void searchItem(const Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items to search!\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter item name to search: ");
    scanf("%s", name);

    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Item found: ID = %d, Quantity = %d, Price = %.2f\n",
                   warehouse->items[i].id, warehouse->items[i].quantity, warehouse->items[i].price);
            return;
        }
    }

    printf("Item not found!\n");
}

void updateItem(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items to update!\n");
        return;
    }

    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            printf("Updating item with ID %d...\n", id);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse->items[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &warehouse->items[i].price);
            printf("Item updated successfully!\n");
            return;
        }
    }

    printf("Item ID not found!\n");
}