//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LEN 50

typedef struct {
    int id;
    char name[ITEM_NAME_LEN];
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

void add_item(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }

    Item new_item;
    new_item.id = warehouse->count + 1; // Simple incremental ID
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter quantity: ");
    scanf("%d", &new_item.quantity);
    printf("Enter price: ");
    scanf("%f", &new_item.price);

    warehouse->items[warehouse->count] = new_item;
    warehouse->count++;
    printf("Item added successfully!\n");
}

void view_items(Warehouse *warehouse) {
    printf("All items in warehouse:\n");
    if (warehouse->count == 0) {
        printf("No items found in the warehouse.\n");
        return;
    }

    for (int i = 0; i < warehouse->count; i++) {
        Item item = warehouse->items[i];
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               item.id, item.name, item.quantity, item.price);
    }
}

void update_item(Warehouse *warehouse) {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > warehouse->count) {
        printf("Invalid item ID.\n");
        return;
    }

    Item *item = &warehouse->items[id - 1];
    printf("Updating item %s (Current quantity: %d, Price: %.2f)\n",
           item->name, item->quantity, item->price);
    printf("Enter new quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter new price: ");
    scanf("%f", &item->price);
    printf("Item updated successfully!\n");
}

void delete_item(Warehouse *warehouse) {
    int id;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > warehouse->count) {
        printf("Invalid item ID.\n");
        return;
    }

    for (int i = id - 1; i < warehouse->count - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->count--;
    printf("Item deleted successfully!\n");
}

void search_item(Warehouse *warehouse) {
    char name[ITEM_NAME_LEN];
    printf("Enter item name to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            Item item = warehouse->items[i];
            printf("Found item - ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   item.id, item.name, item.quantity, item.price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found.\n");
    }
}

void display_menu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. Search Item\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Warehouse warehouse;
    initialize_warehouse(&warehouse);

    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item(&warehouse);
                break;
            case 2:
                view_items(&warehouse);
                break;
            case 3:
                update_item(&warehouse);
                break;
            case 4:
                delete_item(&warehouse);
                break;
            case 5:
                search_item(&warehouse);
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}