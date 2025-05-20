//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    char name[50];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Inventory;

void display_inventory(Inventory *inv) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < inv->num_items; i++) {
        printf("Name: %s, Quantity: %d\n", inv->items[i].name, inv->items[i].quantity);
    }
}

void add_item(Inventory *inv, char *name, int quantity) {
    if (inv->num_items == MAX_ITEMS) {
        fprintf(stderr, "Inventory is full, cannot add item.\n");
        return;
    }

    strncpy(inv->items[inv->num_items].name, name, sizeof(inv->items[inv->num_items].name));
    inv->items[inv->num_items].quantity = quantity;
    inv->num_items++;
}

void remove_item(Inventory *inv, char *name) {
    int i;
    for (i = 0; i < inv->num_items; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            for (int j = i; j < inv->num_items - 1; j++) {
                inv->items[j] = inv->items[j + 1];
            }
            inv->num_items--;
            return;
        }
    }

    fprintf(stderr, "Item '%s' not found in inventory.\n", name);
}

int main() {
    Inventory inv;
    char name[50];
    int quantity;

    printf("Welcome to the Product Inventory System!\n");
    printf("1. Add an item\n2. Remove an item\n3. Display inventory\n4. Exit\n");
    int choice;
    scanf("%d", &choice);

    while (choice!= 4) {
        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                add_item(&inv, name, quantity);
                break;
            case 2:
                printf("Enter name of item to remove: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                remove_item(&inv, name);
                break;
            case 3:
                display_inventory(&inv);
                break;
            default:
                fprintf(stderr, "Invalid choice.\n");
        }

        printf("1. Add an item\n2. Remove an item\n3. Display inventory\n4. Exit\n");
        scanf("%d", &choice);
    }

    return 0;
}