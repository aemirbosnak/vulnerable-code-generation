//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_LOCATION_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
    char location[MAX_LOCATION_LENGTH];
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void addItem(Warehouse *warehouse);
void removeItem(Warehouse *warehouse);
void updateItem(Warehouse *warehouse);
void displayItems(const Warehouse *warehouse);
void findItem(const Warehouse *warehouse);

int main() {
    Warehouse warehouse;
    warehouse.itemCount = 0;

    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Item\n");
        printf("4. Display Items\n");
        printf("5. Find Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(&warehouse); break;
            case 2: removeItem(&warehouse); break;
            case 3: updateItem(&warehouse); break;
            case 4: displayItems(&warehouse); break;
            case 5: findItem(&warehouse); break;
            case 6: printf("Exiting the program...\n"); break;
            default: printf("Invalid choice, please try again!\n"); break;
        }
    } while (choice != 6);

    return 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    printf("Enter item location: ");
    scanf("%s", newItem.location);

    warehouse->items[warehouse->itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void removeItem(Warehouse *warehouse) {
    char name[MAX_NAME_LENGTH];
    printf("Enter item name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i] = warehouse->items[--warehouse->itemCount];
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void updateItem(Warehouse *warehouse) {
    char name[MAX_NAME_LENGTH];
    printf("Enter item name to update: ");
    scanf("%s", name);

    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Updating details for %s\n", warehouse->items[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse->items[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &warehouse->items[i].price);
            printf("Enter new location: ");
            scanf("%s", warehouse->items[i].location);
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void displayItems(const Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    printf("\nWarehouse Items:\n");
    printf("%-20s %-10s %-10s %-20s\n", "Item Name", "Quantity", "Price", "Location");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%-20s %-10d %-10.2f %-20s\n", 
            warehouse->items[i].name, 
            warehouse->items[i].quantity, 
            warehouse->items[i].price, 
            warehouse->items[i].location);
    }
}

void findItem(const Warehouse *warehouse) {
    char name[MAX_NAME_LENGTH];
    printf("Enter item name to find: ");
    scanf("%s", name);

    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Item found: %s | Quantity: %d | Price: %.2f | Location: %s\n",
                    warehouse->items[i].name,
                    warehouse->items[i].quantity,
                    warehouse->items[i].price,
                    warehouse->items[i].location);
            return;
        }
    }
    printf("Item not found!\n");
}