//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 1000
#define MAX_NAME_LENGTH 20
#define MAX_LOCATION_LENGTH 10

typedef struct item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    char location[MAX_LOCATION_LENGTH];
} Item;

typedef struct warehouse {
    Item stock[MAX_STOCK];
    int count;
} Warehouse;

void display_menu() {
    printf("================================\n");
    printf("= Warehouse Management System =\n");
    printf("================================\n");
    printf("1. Add item to stock\n");
    printf("2. Remove item from stock\n");
    printf("3. Display stock\n");
    printf("4. Exit\n");
    printf("================================\n");
    printf("Enter your choice: ");
}

void add_item(Warehouse *warehouse) {
    if (warehouse->count == MAX_STOCK) {
        printf("Stock is full!\n");
        return;
    }

    Item item;

    printf("Enter item name: ");
    scanf("%s", item.name);

    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter item location: ");
    scanf("%s", item.location);

    warehouse->stock[warehouse->count++] = item;

    printf("%s successfully added to stock!\n", item.name);
}

void remove_item(Warehouse *warehouse) {
    char name[MAX_NAME_LENGTH];

    printf("Enter item name: ");
    scanf("%s", name);

    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->stock[i].name, name) == 0) {
            printf("%s removed from stock!\n", warehouse->stock[i].name);

            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->stock[j] = warehouse->stock[j + 1];
            }

            warehouse->count--;

            return;
        }
    }

    printf("%s is not in stock!\n", name);
}

void display_stock(Warehouse *warehouse) {
    printf("=============\n");
    printf("= Stock (%d) =\n", warehouse->count);
    printf("=============\n");

    for (int i = 0; i < warehouse->count; i++) {
        printf("%s | %d | %s\n", warehouse->stock[i].name, warehouse->stock[i].quantity, warehouse->stock[i].location);
    }

    printf("=============\n");
}

int main() {
    Warehouse warehouse = { .count = 0 };

    int choice;

    do {
        display_menu();

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(&warehouse);
                break;
            case 2:
                remove_item(&warehouse);
                break;
            case 3:
                display_stock(&warehouse);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (1);

    return 0;
}