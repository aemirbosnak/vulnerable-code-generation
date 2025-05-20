//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: ultraprecise
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

void initialize_warehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void add_item(Warehouse *warehouse, int id, const char *name, int quantity, float price) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }
    warehouse->items[warehouse->count].id = id;
    strncpy(warehouse->items[warehouse->count].name, name, sizeof(warehouse->items[warehouse->count].name) - 1);
    warehouse->items[warehouse->count].quantity = quantity;
    warehouse->items[warehouse->count].price = price;
    warehouse->count++;
    printf("Added item: %s (ID: %d)\n", name, id);
}

void remove_item(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            printf("Removing item: %s (ID: %d)\n", warehouse->items[i].name, id);
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void update_item_quantity(Warehouse *warehouse, int id, int new_quantity) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i].quantity = new_quantity;
            printf("Updated quantity for item: %s (ID: %d) to %d\n", warehouse->items[i].name, id, new_quantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void display_items(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    printf("\n------------- Warehouse Inventory -------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: $%.2f\n", 
               warehouse->items[i].id, 
               warehouse->items[i].name, 
               warehouse->items[i].quantity, 
               warehouse->items[i].price);
    }
    printf("-----------------------------------------------\n");
}

int main() {
    Warehouse warehouse;
    initialize_warehouse(&warehouse);
    
    int choice, id, quantity;
    char name[50];
    float price;

    do {
        printf("\n--- Warehouse Management System ---\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Item Quantity\n");
        printf("4. Display All Items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                printf("Enter item price: ");
                scanf("%f", &price);
                add_item(&warehouse, id, name, quantity, price);
                break;
            case 2:
                printf("Enter item ID to remove: ");
                scanf("%d", &id);
                remove_item(&warehouse, id);
                break;
            case 3:
                printf("Enter item ID to update: ");
                scanf("%d", &id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                update_item_quantity(&warehouse, id, quantity);
                break;
            case 4:
                display_items(&warehouse);
                break;
            case 5:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}