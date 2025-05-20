//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} InventoryItem;

typedef struct {
    InventoryItem items[MAX_ITEMS];
    int totalItems;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->totalItems = 0;
}

void addItem(Warehouse *warehouse, int id, const char *name, int quantity) {
    if (warehouse->totalItems < MAX_ITEMS) {
        warehouse->items[warehouse->totalItems].id = id;
        strncpy(warehouse->items[warehouse->totalItems].name, name, NAME_LENGTH);
        warehouse->items[warehouse->totalItems].quantity = quantity;
        warehouse->totalItems++;
    } else {
        printf("Warehouse is full! Cannot add more items.\n");
    }
}

void displayItems(const Warehouse *warehouse) {
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\tQuantity\n");
    for (int i = 0; i < warehouse->totalItems; i++) {
        printf("%d\t%s\t%d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void updateItemQuantity(Warehouse *warehouse, int id, int quantity) {
    for (int i = 0; i < warehouse->totalItems; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i].quantity += quantity;
            printf("Updated %s quantity to %d.\n", warehouse->items[i].name, warehouse->items[i].quantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void removeItem(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->totalItems; i++) {
        if (warehouse->items[i].id == id) {
            for (int j = i; j < warehouse->totalItems - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->totalItems--;
            printf("Removed item with ID %d from inventory.\n", id);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void searchItem(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->totalItems; i++) {
        if (warehouse->items[i].id == id) {
            printf("Found item: ID=%d, Name=%s, Quantity=%d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void saveToFile(const Warehouse *warehouse) {
    FILE *file = fopen("warehouse_inventory.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    for (int i = 0; i < warehouse->totalItems; i++) {
        fprintf(file, "%d,%s,%d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
    fclose(file);
    printf("Inventory saved to warehouse_inventory.txt\n");
}

void loadFromFile(Warehouse *warehouse) {
    FILE *file = fopen("warehouse_inventory.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    warehouse->totalItems = 0;
    while (fscanf(file, "%d,%[^,],%d\n", &warehouse->items[warehouse->totalItems].id, warehouse->items[warehouse->totalItems].name, &warehouse->items[warehouse->totalItems].quantity) == 3) {
        warehouse->totalItems++;
        if (warehouse->totalItems >= MAX_ITEMS) {
            break;
        }
    }
    fclose(file);
    printf("Inventory loaded from warehouse_inventory.txt\n");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    loadFromFile(&warehouse);
    int choice, id, quantity;
    char name[NAME_LENGTH];

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Update Item Quantity\n");
        printf("4. Remove Item\n");
        printf("5. Search for Item\n");
        printf("6. Save to File\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                addItem(&warehouse, id, name, quantity);
                break;
            case 2:
                displayItems(&warehouse);
                break;
            case 3:
                printf("Enter item ID to update: ");
                scanf("%d", &id);
                printf("Enter quantity change (negative to decrease): ");
                scanf("%d", &quantity);
                updateItemQuantity(&warehouse, id, quantity);
                break;
            case 4:
                printf("Enter item ID to remove: ");
                scanf("%d", &id);
                removeItem(&warehouse, id);
                break;
            case 5:
                printf("Enter item ID to search: ");
                scanf("%d", &id);
                searchItem(&warehouse, id);
                break;
            case 6:
                saveToFile(&warehouse);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    return 0;
}