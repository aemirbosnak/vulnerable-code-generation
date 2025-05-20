//FormAI DATASET v1.0 Category: Product Inventory System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 100

struct product {
    int id;
    char name[50];
    int quantity;
};

struct inventory {
    int num_products;
    struct product products[MAX_PRODUCTS];
};

void print_inventory(struct inventory *inv) {
    printf("Current inventory:\n");
    printf("ID    | Name                 | Quantity\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("%-5d | %-20s | %-8d\n", inv->products[i].id, inv->products[i].name, inv->products[i].quantity);
    }
}

void add_product(struct inventory *inv, char *name, int quantity) {
    inv->products[inv->num_products].id = inv->num_products + 1;
    strcpy(inv->products[inv->num_products].name, name);
    inv->products[inv->num_products].quantity = quantity;
    inv->num_products++;
    printf("Successfully added product %s to the inventory with ID %d!\n\n", name, inv->num_products);
}

void remove_product(struct inventory *inv, int id) {
    int index = -1;
    for (int i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: product with ID %d not found in the inventory.\n\n", id);
    } else {
        printf("Successfully removed product %s from the inventory with ID %d!\n\n", inv->products[index].name, inv->products[index].id);
        for (int i = index; i < inv->num_products - 1; i++) {
            inv->products[i] = inv->products[i+1];
        }
        inv->num_products--;
    }
}

int main() {
    struct inventory inv;
    inv.num_products = 0;
    int choice;
    char name[50];
    int quantity, id;

    printf("Welcome to the Product Inventory System!\n\n");

    while (1) {
        printf("Choose an option:\n");
        printf("1) View inventory\n");
        printf("2) Add product\n");
        printf("3) Remove product\n");
        printf("4) Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                print_inventory(&inv);
                break;
            case 2:
                printf("Enter name of product to add: ");
                scanf("%s", name);
                printf("Enter quantity of product to add: ");
                scanf("%d", &quantity);
                add_product(&inv, name, quantity);
                break;
            case 3:
                printf("Enter ID of product to remove: ");
                scanf("%d", &id);
                remove_product(&inv, id);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n\n");
        }
    }

    return 0;
}