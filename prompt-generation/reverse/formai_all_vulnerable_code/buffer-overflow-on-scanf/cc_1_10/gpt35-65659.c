//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Inventory;

void add_item(Inventory *inv, Item item) {
    if (inv->num_items < MAX_ITEMS) {
        inv->items[inv->num_items++] = item;
        printf("\nItem added successfully!");
    } else {
        printf("\nInventory is full!");
    }
}

void remove_item(Inventory *inv, int id) {
    int index = -1;
    for (int i = 0; i < inv->num_items; i++) {
        if (inv->items[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nItem with ID %d does not exist in inventory.", id);
    } else {
        for (int i = index; i < inv->num_items - 1; i++) {
            inv->items[i] = inv->items[i + 1];
        }
        inv->num_items--;
        printf("\nItem with ID %d removed successfully!", id);
    }
}

void print_inventory(Inventory inv) {
    printf("\nID\tName\tDescription\tQuantity\tPrice");
    for (int i = 0; i < inv.num_items; i++) {
        printf("\n%d\t%s\t%s\t%d\t%.2f", inv.items[i].id, inv.items[i].name,
               inv.items[i].description, inv.items[i].quantity, inv.items[i].price);
    }
    printf("\n");
}

int main() {
    Inventory inv;
    inv.num_items = 0;

    while (1) {
        printf("\n1. Add item");
        printf("\n2. Remove item");
        printf("\n3. Print inventory");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Item item;
                printf("\nEnter item ID: ");
                scanf("%d", &item.id);
                printf("\nEnter item name: ");
                scanf("%s", item.name);
                printf("\nEnter item description: ");
                scanf("%s", item.description);
                printf("\nEnter item quantity: ");
                scanf("%d", &item.quantity);
                printf("\nEnter item price: ");
                scanf("%f", &item.price);
                add_item(&inv, item);
                break;
            }
            case 2: {
                int id;
                printf("\nEnter item ID to remove: ");
                scanf("%d", &id);
                remove_item(&inv, id);
                break;
            }
            case 3:
                print_inventory(inv);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid choice!");
                break;
        }
    }

    return 0;
}