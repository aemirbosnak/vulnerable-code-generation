//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: thriller
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

struct Item {
    char name[50];
    int quantity;
    float price;
};

struct Warehouse {
    struct Item items[MAX_ITEMS];
    int num_items;
};

void add_item(struct Warehouse* warehouse) {
    if (warehouse->num_items == MAX_ITEMS) {
        printf("Error: maximum number of items reached\n");
        return;
    }

    struct Item item;
    printf("Enter the name of the item: ");
    scanf("%s", item.name);
    printf("Enter the quantity of the item: ");
    scanf("%d", &item.quantity);
    printf("Enter the price of the item: ");
    scanf("%f", &item.price);

    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
    printf("Item added successfully\n");
}

void remove_item(struct Warehouse* warehouse) {
    char name[50];
    printf("Enter the name of the item to remove: ");
    scanf("%s", name);

    int found_index = -1;
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Error: item not found\n");
        return;
    }

    for (int i = found_index; i < warehouse->num_items - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }

    warehouse->num_items--;
    printf("Item removed successfully\n");
}

void display_inventory(struct Warehouse* warehouse) {
    printf("Inventory:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s (Quantity: %d, Price: $%.2f)\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

int main() {
    int choice;
    struct Warehouse warehouse = {0};

    while (1) {
        printf("Menu:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(&warehouse);
                break;
            case 2:
                remove_item(&warehouse);
                break;
            case 3:
                display_inventory(&warehouse);
                break;
            case 4:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Error: invalid choice\n");
                break;
        }
    }

    return 0;
}