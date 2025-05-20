//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    int id;
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price_per_unit;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initialize_warehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void add_item(Warehouse *warehouse, int id, const char *name, int quantity, float price_per_unit) {
    if (warehouse->count < MAX_ITEMS) {
        warehouse->items[warehouse->count].id = id;
        strncpy(warehouse->items[warehouse->count].name, name, ITEM_NAME_LENGTH);
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->items[warehouse->count].price_per_unit = price_per_unit;
        warehouse->count++;
        printf("Item added: %s (ID: %d)\n", name, id);
    } else {
        printf("Cannot add more items, warehouse capacity reached!\n");
    }
}

void display_items(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in warehouse.\n");
        return;
    }
    printf("\nItems in warehouse:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d\t%-15s\t%d\t\t%.2f\n",
               warehouse->items[i].id,
               warehouse->items[i].name,
               warehouse->items[i].quantity,
               warehouse->items[i].price_per_unit);
    }
    printf("------------------------------------------------\n");
}

void remove_item(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            // Shift remaining items to fill the gap
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item with ID %d removed successfully.\n", id);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

float calculate_inventory_value(const Warehouse *warehouse) {
    float total_value = 0.0;
    for (int i = 0; i < warehouse->count; i++) {
        total_value += warehouse->items[i].quantity * warehouse->items[i].price_per_unit;
    }
    return total_value;
}

int main() {
    Warehouse warehouse;
    initialize_warehouse(&warehouse);

    int choice, id, quantity;
    float price_per_unit;
    char name[ITEM_NAME_LENGTH];

    do {
        printf("\nWarehouse Management System Menu\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Remove Item\n");
        printf("4. Calculate Total Inventory Value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Item ID: ");
                scanf("%d", &id);
                printf("Enter Item Name: ");
                scanf(" %[^\n]s", name); // Read string with spaces
                printf("Enter Item Quantity: ");
                scanf("%d", &quantity);
                printf("Enter Item Price per Unit: ");
                scanf("%f", &price_per_unit);
                add_item(&warehouse, id, name, quantity, price_per_unit);
                break;
            case 2:
                display_items(&warehouse);
                break;
            case 3:
                printf("Enter Item ID to remove: ");
                scanf("%d", &id);
                remove_item(&warehouse, id);
                break;
            case 4:
                printf("Total Inventory Value: %.2f\n", calculate_inventory_value(&warehouse));
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}