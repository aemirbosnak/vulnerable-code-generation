//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int item_count;
} Warehouse;

void initialize_warehouse(Warehouse* warehouse) {
    warehouse->item_count = 0;
}

void add_item(Warehouse* warehouse) {
    if (warehouse->item_count >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    Item new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);
    printf("Enter item price: ");
    scanf("%f", &new_item.price);

    warehouse->items[warehouse->item_count++] = new_item;
    printf("Item '%s' added! Total items in warehouse: %d\n", new_item.name, warehouse->item_count);
}

void view_items(Warehouse* warehouse) {
    printf("\nCurrent items in warehouse:\n");
    for (int i = 0; i < warehouse->item_count; i++) {
        printf("Item %d: %s, Quantity: %d, Price: %.2f\n",
               i + 1, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
    printf("\n");
}

void restock_item(Warehouse* warehouse) {
    char item_name[ITEM_NAME_LENGTH];
    int quantity;

    printf("Enter the name of the item to restock: ");
    scanf("%s", item_name);
    
    for (int i = 0; i < warehouse->item_count; i++) {
        if (strcmp(warehouse->items[i].name, item_name) == 0) {
            printf("Enter the quantity to add: ");
            scanf("%d", &quantity);
            warehouse->items[i].quantity += quantity;
            printf("Item '%s' restocked! New quantity: %d\n", item_name, warehouse->items[i].quantity);
            return;
        }
    }
    printf("Item '%s' not found in the warehouse.\n", item_name);
}

void delete_item(Warehouse* warehouse) {
    char item_name[ITEM_NAME_LENGTH];

    printf("Enter the name of the item to delete: ");
    scanf("%s", item_name);

    for (int i = 0; i < warehouse->item_count; i++) {
        if (strcmp(warehouse->items[i].name, item_name) == 0) {
            warehouse->items[i] = warehouse->items[--warehouse->item_count];
            printf("Item '%s' deleted!\n", item_name);
            return;
        }
    }
    printf("Item '%s' not found in the warehouse.\n", item_name);
}

void menu() {
    printf("Warehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Restock Item\n");
    printf("4. Delete Item\n");
    printf("5. Exit\n");
}

int main() {
    Warehouse warehouse;
    initialize_warehouse(&warehouse);

    int choice;
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(&warehouse);
                break;
            case 2:
                view_items(&warehouse);
                break;
            case 3:
                restock_item(&warehouse);
                break;
            case 4:
                delete_item(&warehouse);
                break;
            case 5:
                printf("Exiting the system... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}