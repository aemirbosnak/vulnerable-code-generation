//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSES 10
#define MAX_ITEMS 100
#define MAX_NAME_LEN 20

struct item {
    char name[MAX_NAME_LEN];
    int quantity;
};

struct warehouse {
    char name[MAX_NAME_LEN];
    struct item items[MAX_ITEMS];
    int num_items;
};

struct warehouse warehouses[MAX_WAREHOUSES];
int num_warehouses = 0;

void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void add_warehouse() {
    if (num_warehouses == MAX_WAREHOUSES) {
        printf("Maximum number of warehouses reached!\n");
        return;
    }

    struct warehouse new_warehouse;
    printf("Enter name for new warehouse: ");
    scanf("%s", new_warehouse.name);
    clear_input_buffer();

    new_warehouse.num_items = 0;
    warehouses[num_warehouses] = new_warehouse;
    num_warehouses++;

    printf("Warehouse added successfully!\n");
}

void add_item_to_warehouse() {
    if (num_warehouses == 0) {
        printf("No warehouses exist - please add a warehouse first.\n");
        return;
    }

    printf("Enter warehouse name: ");
    char warehouse_name[MAX_NAME_LEN];
    scanf("%s", warehouse_name);
    clear_input_buffer();

    int warehouse_index = -1;
    for (int i = 0; i < num_warehouses; i++) {
        if (strcmp(warehouses[i].name, warehouse_name) == 0) {
            warehouse_index = i;
            break;
        }
    }

    if (warehouse_index == -1) {
        printf("Warehouse not found!\n");
        return;
    }

    if (warehouses[warehouse_index].num_items == MAX_ITEMS) {
        printf("Maximum number of items reached for this warehouse!\n");
        return;
    }

    struct item new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    clear_input_buffer();

    printf("Enter quantity: ");
    scanf("%d", &new_item.quantity);
    clear_input_buffer();

    warehouses[warehouse_index].items[warehouses[warehouse_index].num_items] = new_item;
    warehouses[warehouse_index].num_items++;

    printf("Item added to warehouse successfully!\n");
}

void remove_item_from_warehouse() {
    if (num_warehouses == 0) {
        printf("No warehouses exist - please add a warehouse first.\n");
        return;
    }

    printf("Enter warehouse name: ");
    char warehouse_name[MAX_NAME_LEN];
    scanf("%s", warehouse_name);
    clear_input_buffer();

    int warehouse_index = -1;
    for (int i = 0; i < num_warehouses; i++) {
        if (strcmp(warehouses[i].name, warehouse_name) == 0) {
            warehouse_index = i;
            break;
        }
    }

    if (warehouse_index == -1) {
        printf("Warehouse not found!\n");
        return;
    }

    if (warehouses[warehouse_index].num_items == 0) {
        printf("No items exist in this warehouse!\n");
        return;
    }

    printf("Enter item name: ");
    char item_name[MAX_NAME_LEN];
    scanf("%s", item_name);
    clear_input_buffer();

    int item_index = -1;
    for (int i = 0; i < warehouses[warehouse_index].num_items; i++) {
        if (strcmp(warehouses[warehouse_index].items[i].name, item_name) == 0) {
            item_index = i;
            break;
        }
    }

    if (item_index == -1) {
        printf("Item not found in warehouse!\n");
        return;
    }

    for (int i = item_index; i < warehouses[warehouse_index].num_items - 1; i++) {
        warehouses[warehouse_index].items[i] = warehouses[warehouse_index].items[i+1];
    }
    warehouses[warehouse_index].num_items--;

    printf("Item removed from warehouse successfully!\n");
}

void print_warehouse_inventory() {
    if (num_warehouses == 0) {
        printf("No warehouses exist - please add a warehouse first.\n");
        return;
    }

    printf("Enter warehouse name: ");
    char warehouse_name[MAX_NAME_LEN];
    scanf("%s", warehouse_name);
    clear_input_buffer();

    int warehouse_index = -1;
    for (int i = 0; i < num_warehouses; i++) {
        if (strcmp(warehouses[i].name, warehouse_name) == 0) {
            warehouse_index = i;
            break;
        }
    }

    if (warehouse_index == -1) {
        printf("Warehouse not found!\n");
        return;
    }

    if (warehouses[warehouse_index].num_items == 0) {
        printf("No items exist in this warehouse!\n");
        return;
    }

    printf("Warehouse Inventory:\n");
    for (int i = 0; i < warehouses[warehouse_index].num_items; i++) {
        printf("%s: %d\n", warehouses[warehouse_index].items[i].name, warehouses[warehouse_index].items[i].quantity);
    }
}

int main() {
    printf("Welcome to the Post-Apocalyptic Warehouse Management System!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a warehouse\n");
        printf("2. Add an item to a warehouse\n");
        printf("3. Remove an item from a warehouse\n");
        printf("4. Print a warehouse's inventory\n");
        printf("5. Quit\n");

        int choice;
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                add_warehouse();
                break;
            case 2:
                add_item_to_warehouse();
                break;
            case 3:
                remove_item_from_warehouse();
                break;
            case 4:
                print_warehouse_inventory();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option - please choose again.\n");
                break;
        }
    }

    return 0;
}