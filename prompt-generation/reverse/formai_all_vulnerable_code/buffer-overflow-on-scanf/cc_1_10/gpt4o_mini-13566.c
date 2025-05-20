//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initialize_warehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

int add_item(Warehouse *warehouse, const char *name, int quantity, float price) {
    if (warehouse->count < MAX_ITEMS) {
        strcpy(warehouse->items[warehouse->count].name, name);
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->items[warehouse->count].price = price;
        warehouse->count++;
        return 1; // Success
    } else {
        return 0; // Failure, warehouse full
    }
}

int remove_item(Warehouse *warehouse, const char *name, int quantity) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            if (warehouse->items[i].quantity >= quantity) {
                warehouse->items[i].quantity -= quantity;
                if (warehouse->items[i].quantity == 0) {
                    // Remove item if quantity is zero
                    for (int j = i; j < warehouse->count - 1; j++) {
                        warehouse->items[j] = warehouse->items[j + 1];
                    }
                    warehouse->count--;
                }
                return 1; // Success
            } else {
                return 0; // Insufficient quantity
            }
        }
    }
    return -1; // Item not found
}

void display_warehouse(const Warehouse *warehouse) {
    printf("Warehouse Inventory:\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("Item: %s | Quantity: %d | Price: %.2f\n", 
                warehouse->items[i].name,
                warehouse->items[i].quantity,
                warehouse->items[i].price);
    }
    printf("------------------------------------------------\n");
}

void process_commands(Warehouse *warehouse) {
    char command[20];
    while (1) {
        printf("Enter command (add, remove, display, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[NAME_LENGTH];
            int quantity;
            float price;

            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            printf("Enter item price: ");
            scanf("%f", &price);

            if (add_item(warehouse, name, quantity, price)) {
                printf("Item added successfully.\n");
            } else {
                printf("Failed to add item: Warehouse full.\n");
            }
        } else if (strcmp(command, "remove") == 0) {
            char name[NAME_LENGTH];
            int quantity;

            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter quantity to remove: ");
            scanf("%d", &quantity);

            int result = remove_item(warehouse, name, quantity);
            if (result == 1) {
                printf("Item removed successfully.\n");
            } else if (result == 0) {
                printf("Insufficient quantity for removal.\n");
            } else {
                printf("Item not found in the warehouse.\n");
            }
        } else if (strcmp(command, "display") == 0) {
            display_warehouse(warehouse);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command. Try again.\n");
        }
    }
}

int main() {
    Warehouse warehouse;
    initialize_warehouse(&warehouse);
    process_commands(&warehouse);
    return 0;
}