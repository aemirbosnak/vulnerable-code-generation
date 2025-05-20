//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
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

void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;

    printf("Item added successfully!\n");
}

void viewItems(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("\nWarehouse Items:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", 
               warehouse->items[i].id, warehouse->items[i].name, 
               warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

void updateItem(Warehouse *warehouse) {
    int id, found = 0;
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            printf("Updating Item - ID: %d\n", id);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse->items[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &warehouse->items[i].price);
            found = 1;
            printf("Item updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void deleteItem(Warehouse *warehouse) {
    int id, found = 0;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            found = 1;
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item with ID %d deleted successfully!\n", id);
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void saveWarehouseToFile(const Warehouse *warehouse) {
    FILE *file = fopen("warehouse_data.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(warehouse, sizeof(Warehouse), 1, file);
    fclose(file);
    printf("Warehouse data saved successfully!\n");
}

void loadWarehouseFromFile(Warehouse *warehouse) {
    FILE *file = fopen("warehouse_data.txt", "r");
    if (!file) {
        printf("No previous data found. Starting with an empty warehouse.\n");
        return;
    }
    fread(warehouse, sizeof(Warehouse), 1, file);
    fclose(file);
    printf("Warehouse data loaded successfully!\n");
}

int main() {
    Warehouse warehouse;
    warehouse.count = 0;

    loadWarehouseFromFile(&warehouse);

    int choice;
    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Save and Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                viewItems(&warehouse);
                break;
            case 3:
                updateItem(&warehouse);
                break;
            case 4:
                deleteItem(&warehouse);
                break;
            case 5:
                saveWarehouseToFile(&warehouse);
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}