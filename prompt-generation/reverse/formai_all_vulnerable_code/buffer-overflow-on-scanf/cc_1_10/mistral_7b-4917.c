//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int stock;
    int reorder_level;
} InventoryItem;

InventoryItem inventory[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, int stock, int reorder_level) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }
    strcpy(inventory[num_items].name, name);
    inventory[num_items].stock = stock;
    inventory[num_items].reorder_level = reorder_level;
    num_items++;
}

void update_item(char *name, int new_stock, int new_reorder_level) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].stock = new_stock;
            inventory[i].reorder_level = new_reorder_level;
            printf("Item %s updated successfully.\n", name);
            return;
        }
    }
    printf("Error: Item not found.\n");
}

void view_inventory() {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: Stock %d, Reorder Level %d\n", inventory[i].name, inventory[i].stock, inventory[i].reorder_level);
    }
}

int main() {
    char command[10], name[50], temp_name[50];
    int stock, reorder_level, index;

    while (1) {
        printf("\nWarehouse Management System\n1. Add Item\n2. Update Item\n3. View Inventory\n4. Exit\nEnter command: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter stock level: ");
                scanf("%d", &stock);
                printf("Enter reorder level: ");
                scanf("%d", &reorder_level);
                add_item(name, stock, reorder_level);
                break;

            case '2':
                printf("Enter item name to update: ");
                scanf("%s", temp_name);
                printf("Enter new stock level: ");
                scanf("%d", &stock);
                printf("Enter new reorder level: ");
                scanf("%d", &reorder_level);
                update_item(temp_name, stock, reorder_level);
                break;

            case '3':
                view_inventory();
                break;

            case '4':
                printf("Exiting the system...\n");
                exit(0);

            default:
                printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}