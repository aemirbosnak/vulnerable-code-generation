//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char name[20];
    int quantity;
};

struct Warehouse {
    struct Item items[MAX_ITEMS];
    int num_items;
};

void add_item(struct Warehouse* warehouse, char* name, int quantity) {
    if (warehouse->num_items == MAX_ITEMS) {
        printf("The warehouse is full.\n");
        return;
    }
    struct Item item;
    strcpy(item.name, name);
    item.quantity = quantity;
    warehouse->items[warehouse->num_items++] = item;
}

void remove_item(struct Warehouse* warehouse, char* name, int quantity) {
    int index = -1;
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("The item '%s' does not exist in the warehouse.\n", name);
        return;
    }
    if (warehouse->items[index].quantity < quantity) {
        printf("The warehouse does not have enough quantity of item '%s'.\n", name);
        return;
    }
    warehouse->items[index].quantity -= quantity;
    if (warehouse->items[index].quantity == 0) {
        for (int i = index; i < warehouse->num_items - 1; i++) {
            warehouse->items[i] = warehouse->items[i+1];
        }
        warehouse->num_items--;
    }
}

void display_items(struct Warehouse* warehouse) {
    printf("Items in the warehouse:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%d. %s -- %d\n", i+1, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    struct Warehouse warehouse;
    warehouse.num_items = 0;

    char option;
    char name[20];
    int quantity;

    while (1) {
        printf("\n1. Add item to the warehouse.\n");
        printf("2. Remove item from the warehouse.\n");
        printf("3. Display items in the warehouse.\n");
        printf("4. Exit.\n");
        printf("\nEnter your option: ");

        scanf("%c", &option);
        getchar(); // consume the \n character

        switch(option) {
            case '1':
                printf("Enter the name of the item to add: ");
                scanf("%s", name);
                printf("Enter the quantity of the item to add: ");
                scanf("%d", &quantity);
                add_item(&warehouse, name, quantity);
                break;
            case '2':
                printf("Enter the name of the item to remove: ");
                scanf("%s", name);
                printf("Enter the quantity of the item to remove: ");
                scanf("%d", &quantity);
                remove_item(&warehouse, name, quantity);
                break;
            case '3':
                display_items(&warehouse);
                break;
            case '4':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}