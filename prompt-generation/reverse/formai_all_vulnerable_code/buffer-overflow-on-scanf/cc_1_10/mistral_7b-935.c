//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int stock;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void list_inventory() {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < num_products; ++i) {
        printf("%s: %d\n", inventory[i].name, inventory[i].stock);
    }
}

void add_product(char *name, int stock) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }
    strcpy(inventory[num_products].name, name);
    inventory[num_products].stock = stock;
    ++num_products;
}

void remove_product(char *name) {
    for (int i = 0; i < num_products; ++i) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; ++j) {
                strcpy(inventory[j].name, inventory[j + 1].name);
                inventory[j].stock = inventory[j + 1].stock;
            }
            --num_products;
            printf("%s removed successfully.\n", name);
            return;
        }
    }
    printf("%s not found in inventory.\n", name);
}

int main() {
    char command[50], name[50], temp_name[50];
    int stock, choice;

    while (1) {
        printf("\nSherlock's Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. List Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter stock: ");
                scanf("%d", &stock);
                add_product(name, stock);
                break;

            case 2:
                printf("Enter product name to remove: ");
                scanf("%s", name);
                remove_product(name);
                break;

            case 3:
                list_inventory();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    }

    return 0;
}