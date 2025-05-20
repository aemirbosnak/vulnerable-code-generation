//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITEMS 1000

typedef struct {
    char name[50];
    int quantity;
    double price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Inventory;

void add_item(Inventory *inv, Item item) {
    if (inv->num_items < MAX_ITEMS) {
        inv->items[inv->num_items++] = item;
        printf("%s added to inventory.\n", item.name);
    } else {
        printf("Error: inventory is full.\n");
    }
}

bool remove_item(Inventory *inv, char *name) {
    for (int i = 0; i < inv->num_items; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            for (int j = i; j < inv->num_items - 1; j++) {
                inv->items[j] = inv->items[j+1];
            }
            inv->num_items--;
            printf("%s removed from inventory.\n", name);
            return true;
        }
    }
    printf("%s not found in inventory.\n", name);
    return false;
}

void print_inventory(Inventory *inv) {
    printf("Inventory:\n");
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < inv->num_items; i++) {
        printf("%s\t%d\t%.2f\n", inv->items[i].name, inv->items[i].quantity, inv->items[i].price);
    }
}

int main() {
    Inventory inv;
    inv.num_items = 0;

    char selection;
    do {
        printf("\n1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. Print inventory\n");
        printf("4. Exit\n");
        printf("Enter selection: ");
        scanf(" %c", &selection);

        switch (selection) {
            case '1': {
                Item item;
                printf("Enter name: ");
                scanf("%s", item.name);
                printf("Enter quantity: ");
                scanf("%d", &item.quantity);
                printf("Enter price: ");
                scanf("%lf", &item.price);
                add_item(&inv, item);
                break;
            }
            case '2': {
                char name[50];
                printf("Enter name to remove: ");
                scanf("%s", name);
                remove_item(&inv, name);
                break;
            }
            case '3':
                print_inventory(&inv);
                break;
            case '4':
                printf("Exiting warehouse management system...\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    } while (selection != '4');

    return 0;
}