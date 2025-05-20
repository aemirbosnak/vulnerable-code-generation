//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void add_item(Warehouse *warehouse, const char *name, int quantity) {
    if (warehouse->count == MAX_ITEMS) {
        printf("Warehouse is full.\n");
        return;
    }

    strcpy(warehouse->items[warehouse->count].name, name);
    warehouse->items[warehouse->count].quantity = quantity;
    warehouse->count++;
}

void remove_item(Warehouse *warehouse, const char *name) {
    int i;

    for (i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            if (--warehouse->items[i].quantity == 0) {
                for (; i < warehouse->count - 1; i++) {
                    strcpy(warehouse->items[i].name, warehouse->items[i+1].name);
                    warehouse->items[i].quantity = warehouse->items[i+1].quantity;
                }
                warehouse->count--;
                break;
            }
            return;
        }
    }

    printf("Item not found.\n");
}

void display_warehouse(const Warehouse *warehouse) {
    int i;

    printf("Warehouse contents:\n");
    for (i = 0; i < warehouse->count; i++) {
        printf("%s: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    Warehouse my_warehouse;
    char name[MAX_NAME_LEN];
    int quantity, choice;

    printf("Welcome to the Peaceful Warehouse Management System.\n");

    while (1) {
        printf("\n1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display warehouse\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                add_item(&my_warehouse, name, quantity);
                break;

            case 2:
                printf("Enter item name to remove: ");
                scanf("%s", name);
                remove_item(&my_warehouse, name);
                break;

            case 3:
                display_warehouse(&my_warehouse);
                break;

            case 4:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}