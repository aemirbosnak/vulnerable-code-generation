//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Inventory;

void add_item(Inventory *inv, char *name, int quantity, float price);
void remove_item(Inventory *inv, char *name);
void display_inventory(Inventory *inv);

int main() {
    Inventory inv = {0};
    int choice;
    char name[MAX_NAME_LEN];
    int quantity;
    float price;

    printf("Welcome to the Warehouse Management System!\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name of item to add: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                add_item(&inv, name, quantity, price);
                printf("Item added!\n");
                break;
            case 2:
                printf("Enter name of item to remove: ");
                scanf("%s", name);
                remove_item(&inv, name);
                printf("Item removed!\n");
                break;
            case 3:
                display_inventory(&inv);
                break;
            case 4:
                printf("Thank you for using the Warehouse Management System!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void add_item(Inventory *inv, char *name, int quantity, float price) {
    if (inv->num_items >= MAX_ITEMS) {
        printf("Error: inventory is full!\n");
        return;
    }

    Item item;
    strncpy(item.name, name, MAX_NAME_LEN);
    item.quantity = quantity;
    item.price = price;

    inv->items[inv->num_items] = item;
    inv->num_items++;
}

void remove_item(Inventory *inv, char *name) {
    int i, found = 0;

    for (i = 0; i < inv->num_items; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < inv->num_items - 1; i++) {
            inv->items[i] = inv->items[i + 1];
        }
        inv->num_items--;
    } else {
        printf("Error: item not found!\n");
    }
}

void display_inventory(Inventory *inv) {
    printf("\nInventory:\n");

    if (inv->num_items == 0) {
        printf("Empty!\n");
        return;
    }

    int i;
    float total_value = 0.0;

    for (i = 0; i < inv->num_items; i++) {
        Item item = inv->items[i];
        float value = item.quantity * item.price;
        total_value += value;
        printf("%s (x%d) - $%.2f each, total value: $%.2f\n", item.name, item.quantity, item.price, value);
    }

    printf("Total inventory value: $%.2f\n", total_value);
}