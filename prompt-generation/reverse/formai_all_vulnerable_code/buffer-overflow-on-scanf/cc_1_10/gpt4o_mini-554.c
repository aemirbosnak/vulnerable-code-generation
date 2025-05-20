//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item *items;
    int size;
    int capacity;
} Warehouse;

Warehouse* create_warehouse(int capacity) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->items = malloc(capacity * sizeof(Item));
    warehouse->size = 0;
    warehouse->capacity = capacity;
    return warehouse;
}

void add_item(Warehouse *warehouse, int id, const char *name, int quantity) {
    if(warehouse->size >= warehouse->capacity) {
        printf("Warehouse is full, cannot add more items.\n");
        return;
    }
    warehouse->items[warehouse->size].id = id;
    strcpy(warehouse->items[warehouse->size].name, name);
    warehouse->items[warehouse->size].quantity = quantity;
    warehouse->size++;
    printf("Item added: ID=%d, Name=%s, Quantity=%d\n", id, name, quantity);
}

void view_items(const Warehouse *warehouse) {
    if(warehouse->size == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    printf("Items in warehouse:\n");
    for(int i = 0; i < warehouse->size; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n",
               warehouse->items[i].id,
               warehouse->items[i].name,
               warehouse->items[i].quantity);
    }
}

void delete_item(Warehouse *warehouse, int id) {
    for(int i = 0; i < warehouse->size; i++) {
        if(warehouse->items[i].id == id) {
            for(int j = i; j < warehouse->size - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->size--;
            printf("Item with ID=%d deleted.\n", id);
            return;
        }
    }
    printf("Item with ID=%d not found.\n", id);
}

void free_warehouse(Warehouse *warehouse) {
    free(warehouse->items);
    free(warehouse);
}

int main() {
    Warehouse *warehouse = create_warehouse(MAX_ITEMS);
    int choice, id, quantity;
    char name[NAME_LENGTH];

    while(1) {
        printf("\nWarehouse Management System:\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Delete Item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf(" %[^\n]", name); // Read string with spaces
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                add_item(warehouse, id, name, quantity);
                break;
            case 2:
                view_items(warehouse);
                break;
            case 3:
                printf("Enter item ID to delete: ");
                scanf("%d", &id);
                delete_item(warehouse, id);
                break;
            case 4:
                free_warehouse(warehouse);
                printf("Exiting the system. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}