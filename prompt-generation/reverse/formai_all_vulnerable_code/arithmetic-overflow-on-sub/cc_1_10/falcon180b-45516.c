//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int quantity;
    float price;
} item;

typedef struct {
    item items[MAX_SIZE];
    int num_items;
} inventory;

void add_item(inventory *inv) {
    printf("Enter item name: ");
    scanf("%s", inv->items[inv->num_items].name);
    printf("Enter item quantity: ");
    scanf("%d", &inv->items[inv->num_items].quantity);
    printf("Enter item price: ");
    scanf("%f", &inv->items[inv->num_items].price);
    inv->num_items++;
}

void remove_item(inventory *inv) {
    printf("Enter item name to remove: ");
    scanf("%s", inv->items[inv->num_items - 1].name);
    inv->num_items--;
}

void print_inventory(inventory *inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_items; i++) {
        printf("%s: %d items, $%.2f each\n", inv->items[i].name, inv->items[i].quantity, inv->items[i].price);
    }
}

int main() {
    inventory inv;
    inv.num_items = 0;

    while (1) {
        printf("1. Add item\n2. Remove item\n3. Print inventory\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(&inv);
                break;
            case 2:
                remove_item(&inv);
                break;
            case 3:
                print_inventory(&inv);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}