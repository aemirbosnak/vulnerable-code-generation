//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct item {
    char name[20];
    int quantity;
    float price;
};

struct warehouse {
    char name[50];
    int id;
    struct item items[MAX_SIZE];
    int item_count;
};

struct warehouse warehouses[MAX_SIZE];
int warehouse_count = 0;

void add_item(struct warehouse *w) {
    if (w->item_count >= MAX_SIZE) {
        printf("Warehouse is full! Cannot add any more items.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", w->items[w->item_count].name);

    printf("Enter item quantity: ");
    scanf("%d", &w->items[w->item_count].quantity);

    printf("Enter item price: ");
    scanf("%f", &w->items[w->item_count].price);

    w->item_count++;
}

void add_warehouse() {
    printf("Enter warehouse name: ");
    scanf("%s", warehouses[warehouse_count].name);

    printf("Enter warehouse id: ");
    scanf("%d", &warehouses[warehouse_count].id);

    warehouses[warehouse_count].item_count = 0;
    warehouse_count++;
}

void print_warehouse(struct warehouse *w) {
    printf("Warehouse name: %s\n", w->name);
    printf("Warehouse id: %d\n", w->id);

    for (int i = 0; i < w->item_count; i++) {
        printf("Item name: %s\n", w->items[i].name);
        printf("Item quantity: %d\n", w->items[i].quantity);
        printf("Item price: %.2f\n", w->items[i].price);
    }
}

void print_all_warehouses() {
    for (int i = 0; i < warehouse_count; i++) {
        print_warehouse(&warehouses[i]);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add warehouse\n");
        printf("2. Add item to warehouse\n");
        printf("3. Print all warehouses\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_warehouse();
                break;
            case 2:
                printf("Enter warehouse id: ");
                int id;
                scanf("%d", &id);

                for (int i = 0; i < warehouse_count; i++) {
                    if (warehouses[i].id == id) {
                        add_item(&warehouses[i]);
                        break;
                    }
                }
                break;
            case 3:
                print_all_warehouses();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}