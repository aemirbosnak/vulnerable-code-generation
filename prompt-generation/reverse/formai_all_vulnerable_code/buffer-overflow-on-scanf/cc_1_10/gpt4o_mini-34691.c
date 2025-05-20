//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
    time_t added_time;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int item_count;
} Warehouse;

// Function to initialize the warehouse
void initialize_warehouse(Warehouse *warehouse) {
    warehouse->item_count = 0;
}

// Function to add an item to the warehouse
void add_item(Warehouse *warehouse, const char *name, int quantity) {
    if (warehouse->item_count < MAX_ITEMS) {
        strncpy(warehouse->items[warehouse->item_count].name, name, ITEM_NAME_LENGTH);
        warehouse->items[warehouse->item_count].quantity = quantity;
        warehouse->items[warehouse->item_count].added_time = time(NULL);
        warehouse->item_count++;
        printf("Item '%s' added. Quantity: %d\n", name, quantity);
    } else {
        printf("Warehouse is full. Cannot add more items.\n");
    }
}

// Function to list all items in the warehouse
void list_items(const Warehouse *warehouse) {
    printf("=== Warehouse Inventory ===\n");
    for (int i = 0; i < warehouse->item_count; i++) {
        printf("Item: %s | Quantity: %d | Added on: %s",
               warehouse->items[i].name, warehouse->items[i].quantity,
               ctime(&warehouse->items[i].added_time));
    }
    if (warehouse->item_count == 0) {
        printf("No items in the warehouse.\n");
    }
}

// Function to remove an item from the warehouse
void remove_item(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->item_count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Removing item '%s'. Quantity: %d\n", name, warehouse->items[i].quantity);
            warehouse->items[i] = warehouse->items[warehouse->item_count - 1];
            warehouse->item_count--;
            return;
        }
    }
    printf("Item '%s' not found in the warehouse.\n", name);
}

// Function to update an item's quantity
void update_item_quantity(Warehouse *warehouse, const char *name, int new_quantity) {
    for (int i = 0; i < warehouse->item_count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity = new_quantity;
            printf("Updated item '%s' to new quantity: %d\n", name, new_quantity);
            return;
        }
    }
    printf("Item '%s' not found to update quantity.\n", name);
}

// Main function
int main() {
    Warehouse warehouse;
    initialize_warehouse(&warehouse);

    int choice;
    char item_name[ITEM_NAME_LENGTH];
    int item_quantity;

    while (1) {
        printf("\n--- Cyberpunk Warehouse Management System ---\n");
        printf("1. Add Item\n");
        printf("2. List Items\n");
        printf("3. Remove Item\n");
        printf("4. Update Item Quantity\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                fgets(item_name, ITEM_NAME_LENGTH, stdin);
                item_name[strcspn(item_name, "\n")] = 0; // Remove newline
                printf("Enter item quantity: ");
                scanf("%d", &item_quantity);
                add_item(&warehouse, item_name, item_quantity);
                break;
            case 2:
                list_items(&warehouse);
                break;
            case 3:
                printf("Enter item name to remove: ");
                fgets(item_name, ITEM_NAME_LENGTH, stdin);
                item_name[strcspn(item_name, "\n")] = 0; // Remove newline
                remove_item(&warehouse, item_name);
                break;
            case 4:
                printf("Enter item name to update: ");
                fgets(item_name, ITEM_NAME_LENGTH, stdin);
                item_name[strcspn(item_name, "\n")] = 0; // Remove newline
                printf("Enter new quantity: ");
                scanf("%d", &item_quantity);
                update_item_quantity(&warehouse, item_name, item_quantity);
                break;
            case 5:
                printf("Exiting the Cyberpunk Warehouse Management System. Stay safe in the neon-lit streets!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}