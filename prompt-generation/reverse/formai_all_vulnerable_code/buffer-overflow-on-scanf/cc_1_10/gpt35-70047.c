//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
} product;

typedef struct {
    product *items;
    int capacity;
    int size;
} inventory;

void add_product(inventory *inv, int id, char *name, int quantity) {
    if (inv->size == inv->capacity) {
        printf("Error: Inventory is full!\n");
        return;
    }

    product prod = {id, "", quantity};
    strncpy(prod.name, name, sizeof(prod.name) - 1);

    inv->items[inv->size] = prod;
    inv->size++;

    printf("Product added successfully!\n");
}

void remove_product(inventory *inv, int id) {
    int index = -1;

    for (int i = 0; i < inv->size; i++) {
        if (inv->items[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Product not found!\n");
        return;
    }

    for (int i = index; i < inv->size - 1; i++) {
        inv->items[i] = inv->items[i + 1];
    }

    inv->size--;

    printf("Product removed successfully!\n");
}

void list_inventory(inventory *inv) {
    printf("Product Inventory\n");
    printf("-----------------\n");
    printf("ID\tName\tQuantity\n");

    for (int i = 0; i < inv->size; i++) {
        printf("%d\t%s\t%d\n",
                inv->items[i].id,
                inv->items[i].name,
                inv->items[i].quantity);
    }
}

int main() {
    inventory inv = {NULL, 10, 0};
    inv.items = malloc(sizeof(product) * inv.capacity);

    while (1) {
        printf("Enter 1 to add product, 2 to remove product, 3 to list inventory, and 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Goodbye!\n");
                exit(0);
            case 1:
                printf("Enter product ID: ");
                int id;
                scanf("%d", &id);

                printf("Enter product name: ");
                char name[50];
                scanf("%s", name);

                printf("Enter product quantity: ");
                int quantity;
                scanf("%d", &quantity);

                add_product(&inv, id, name, quantity);
                break;
            case 2:
                printf("Enter product ID to remove: ");
                int remove_id;
                scanf("%d", &remove_id);

                remove_product(&inv, remove_id);
                break;
            case 3:
                list_inventory(&inv);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}