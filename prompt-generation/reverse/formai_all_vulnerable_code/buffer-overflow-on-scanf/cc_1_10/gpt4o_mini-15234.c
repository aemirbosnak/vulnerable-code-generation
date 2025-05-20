//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    int id;
    char name[ITEM_NAME_LENGTH];
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
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }
    Item newItem;
    newItem.id = warehouse->count + 1;

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

void display_items(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    
    printf("\nWarehouse Items:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-----------------------------------------\n");
    
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
    printf("-----------------------------------------\n");
}

void update_item(Warehouse *warehouse) {
    int id, found = 0;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);

    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            found = 1;
            printf("Updating item: %s\n", warehouse->items[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse->items[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &warehouse->items[i].price);
            printf("Item updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void delete_item(Warehouse *warehouse) {
    int id, found = 0;
    printf("Enter the ID of the item to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            found = 1;
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void search_item(Warehouse *warehouse) {
    char name[ITEM_NAME_LENGTH];
    int found = 0;
    printf("Enter the name of the item to search: ");
    scanf("%s", name);

    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            found = 1;
            printf("Item found: ID %d, Quantity: %d, Price: %.2f\n", warehouse->items[i].id, warehouse->items[i].quantity, warehouse->items[i].price);
            break;
        }
    }
    if (!found) {
        printf("Item with name '%s' not found.\n", name);
    }
}

int main() {
    Warehouse warehouse;
    initialize_warehouse(&warehouse);

    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Search Item\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(&warehouse);
                break;
            case 2:
                display_items(&warehouse);
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
            case 0:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}