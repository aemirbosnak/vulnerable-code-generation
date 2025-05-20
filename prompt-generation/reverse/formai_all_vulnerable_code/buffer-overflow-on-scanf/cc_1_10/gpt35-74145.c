//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000 // Maximum number of items that can be stored in the warehouse

struct item {
    char name[20];
    int quantity;
    float price;
};

struct warehouse {
    struct item inventory[MAX_ITEMS]; // Array of items in the warehouse
    int num_items; // Number of items currently stored in the warehouse
};

void add_item(struct warehouse *w, char *name, int quantity, float price) {
    if (w->num_items == MAX_ITEMS) {
        printf("Error: warehouse is full\n");
        return;
    }

    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->inventory[i].name, name) == 0) {
            printf("Error: item already exists in warehouse\n");
            return;
        }
    }

    struct item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    new_item.price = price;

    w->inventory[w->num_items] = new_item;
    w->num_items++;

    printf("Item successfully added to warehouse:\n");
    printf("Name: %s\n", name);
    printf("Quantity: %d\n", quantity);
    printf("Price: $%.2f\n", price);
}

void remove_item(struct warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->inventory[i].name, name) == 0) {
            int j;
            for (j = i; j < w->num_items - 1; j++) {
                w->inventory[j] = w->inventory[j+1];
            }
            w->num_items--;
            printf("Item successfully removed from warehouse:\n");
            printf("Name: %s\n", name);
            return;
        }
    }

    printf("Error: item not found in warehouse\n");
}

void update_quantity(struct warehouse *w, char *name, int new_quantity) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->inventory[i].name, name) == 0) {
            w->inventory[i].quantity = new_quantity;
            printf("Quantity for item %s successfully updated to %d\n", name, new_quantity);
            return;
        }
    }

    printf("Error: item not found in warehouse\n");
}

void print_inventory(struct warehouse *w) {
    printf("Warehouse Inventory:\n");
    int i;
    for (i = 0; i < w->num_items; i++) {
        printf("%d. Name: %s, Quantity: %d, Price: $%.2f\n", i+1, w->inventory[i].name, w->inventory[i].quantity, w->inventory[i].price);
    }
}

int main() {
    struct warehouse my_warehouse;
    my_warehouse.num_items = 0;

    int selection;
    char name[20];
    int quantity;
    float price;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Update quantity\n");
        printf("4. Print inventory\n");
        printf("5. Quit\n");
        printf("Enter selection: ");
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                add_item(&my_warehouse, name, quantity, price);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", name);
                remove_item(&my_warehouse, name);
                break;
            case 3:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                update_quantity(&my_warehouse, name, quantity);
                break;
            case 4:
                print_inventory(&my_warehouse);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid selection\n");
                break;
        }
    }
}