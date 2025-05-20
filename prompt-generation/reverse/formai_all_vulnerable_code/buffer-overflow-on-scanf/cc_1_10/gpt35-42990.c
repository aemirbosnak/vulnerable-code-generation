//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100 // maximum number of items that can be stored in the warehouse

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items; // number of items currently in the warehouse
    float total_revenue;
} Warehouse;

void add_item(Warehouse *warehouse, Item item) {
    if (warehouse->num_items >= MAX_ITEMS) {
        printf("Warehouse is full, cannot add item\n");
        return;
    }
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
    printf("Item added to warehouse successfully\n");
}

void remove_item(Warehouse *warehouse, int id) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            // found the item to remove
            warehouse->total_revenue += warehouse->items[i].price * warehouse->items[i].quantity;
            int j;
            for (j = i; j < warehouse->num_items - 1; j++) {
                // shift all remaining items to fill the gap left by the removed item
                warehouse->items[j] = warehouse->items[j+1];
            }
            warehouse->num_items--;
            printf("Item removed from warehouse successfully\n");
            return;
        }
    }
    printf("Item not found in warehouse\n");
}

void display_inventory(Warehouse *warehouse) {
    int i;
    printf("====================\n");
    printf("Inventory of Warehouse\n");
    printf("====================\n");
    for (i = 0; i < warehouse->num_items; i++) {
        printf("ID: %d\n", warehouse->items[i].id);
        printf("Name: %s\n", warehouse->items[i].name);
        printf("Quantity: %d\n", warehouse->items[i].quantity);
        printf("Price: $%.2f\n", warehouse->items[i].price);
        printf("====================\n");
    }
}

int main() {
    Warehouse warehouse = { .num_items = 0, .total_revenue = 0 };
    int choice;
    do {
        printf("\n====================\n");
        printf("Warehouse Management System\n");
        printf("====================\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                {
                    Item item;
                    printf("Enter ID: ");
                    scanf("%d", &item.id);
                    printf("Enter Name: ");
                    scanf("%s", item.name);
                    printf("Enter Quantity: ");
                    scanf("%d", &item.quantity);
                    printf("Enter Price: ");
                    scanf("%f", &item.price);
                    add_item(&warehouse, item);
                    break;
                }
            case 2:
                {
                    int id;
                    printf("Enter ID: ");
                    scanf("%d", &id);
                    remove_item(&warehouse, id);
                    break;
                }
            case 3:
                display_inventory(&warehouse);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (choice != 4);
    return 0;
}