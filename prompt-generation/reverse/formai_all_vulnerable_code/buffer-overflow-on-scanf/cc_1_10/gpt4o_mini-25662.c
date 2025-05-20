//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    double price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

// Function declarations
void initializeWarehouse(Warehouse *warehouse);
void addItem(Warehouse *warehouse);
void removeItem(Warehouse *warehouse);
void displayItems(const Warehouse *warehouse);
void searchItem(const Warehouse *warehouse);
void updateItem(Warehouse *warehouse);
void saveWarehouseToFile(const Warehouse *warehouse, const char *filename);
void loadWarehouseFromFile(Warehouse *warehouse, const char *filename);
void showMenu();

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    loadWarehouseFromFile(&warehouse, "warehouse.dat");

    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                removeItem(&warehouse);
                break;
            case 3:
                displayItems(&warehouse);
                break;
            case 4:
                searchItem(&warehouse);
                break;
            case 5:
                updateItem(&warehouse);
                break;
            case 6:
                saveWarehouseToFile(&warehouse, "warehouse.dat");
                printf("Warehouse data saved.\n");
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full, cannot add more items.\n");
        return;
    }

    Item item;
    printf("Enter item ID: ");
    scanf("%d", &item.id);
    printf("Enter item name: ");
    scanf(" %[^\n]", item.name);
    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter item price: ");
    scanf("%lf", &item.price);

    warehouse->items[warehouse->count++] = item;
    printf("Item added successfully!\n");
}

void removeItem(Warehouse *warehouse) {
    int id, i, found = 0;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);

    for (i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            found = 1;
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void displayItems(const Warehouse *warehouse) {
    printf("\nWarehouse Items:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", warehouse->items[i].id,
               warehouse->items[i].name,
               warehouse->items[i].quantity,
               warehouse->items[i].price);
    }
    printf("---------------------------------------------\n");
}

void searchItem(const Warehouse *warehouse) {
    int id, found = 0;
    printf("Enter item ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            printf("Item found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   warehouse->items[i].id,
                   warehouse->items[i].name,
                   warehouse->items[i].quantity,
                   warehouse->items[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void updateItem(Warehouse *warehouse) {
    int id, found = 0;
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            found = 1;
            printf("Updating item with ID: %d\n", id);
            printf("Enter new name: ");
            scanf(" %[^\n]", warehouse->items[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse->items[i].quantity);
            printf("Enter new price: ");
            scanf("%lf", &warehouse->items[i].price);
            printf("Item updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void saveWarehouseToFile(const Warehouse *warehouse, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    fwrite(warehouse, sizeof(Warehouse), 1, file);
    fclose(file);
}

void loadWarehouseFromFile(Warehouse *warehouse, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }
    fread(warehouse, sizeof(Warehouse), 1, file);
    fclose(file);
}

void showMenu() {
    printf("\nWarehouse Management System Menu:\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Items\n");
    printf("4. Search Item\n");
    printf("5. Update Item\n");
    printf("6. Save Data\n");
    printf("7. Exit\n");
}