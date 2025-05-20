//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

struct Item {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
};

struct Warehouse {
    int total_items;
    struct Item items[MAX_ITEMS];
};

void add_item(struct Warehouse* warehouse, struct Item item) {
    if (warehouse->total_items >= MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }
    
    warehouse->items[warehouse->total_items] = item;
    warehouse->total_items++;
    printf("Item added to the warehouse.\n");
}

void remove_item(struct Warehouse* warehouse, int id) {
    int index = -1;
    for (int i = 0; i < warehouse->total_items; i++) {
        if (warehouse->items[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Item not found in the warehouse!\n");
        return;
    }
    
    for (int i = index; i < warehouse->total_items - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    
    warehouse->total_items--;
    printf("Item removed from the warehouse.\n");
}

void display_items(struct Warehouse warehouse) {
    if (warehouse.total_items == 0) {
        printf("Warehouse is empty!\n");
        return;
    }
    
    printf("Warehouse items:\n");
    for (int i = 0; i < warehouse.total_items; i++) {
        printf("%d. %s - %d\n", warehouse.items[i].id, warehouse.items[i].name, warehouse.items[i].quantity);
    }
}

int main() {
    struct Warehouse warehouse;
    warehouse.total_items = 0;
    int choice;
    
    do {
        printf("1. Add item to the warehouse\n");
        printf("2. Remove item from the warehouse\n");
        printf("3. Display warehouse items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                struct Item item;
                printf("Enter item id: ");
                scanf("%d", &item.id);
                fflush(stdin);
                printf("Enter item name: ");
                gets(item.name);
                printf("Enter item quantity: ");
                scanf("%d", &item.quantity);
                add_item(&warehouse, item);
                break;
            }
            case 2: {
                int id;
                printf("Enter item id to remove: ");
                scanf("%d", &id);
                remove_item(&warehouse, id);
                break;
            }
            case 3: {
                display_items(warehouse);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    } while (choice != 4);
    
    return 0;
}