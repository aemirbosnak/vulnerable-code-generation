//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_SIZE 50
#define PRODUCT_QUANTITY_SIZE 10

typedef struct {
    char name[PRODUCT_NAME_SIZE];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int quantity) {
    if (num_products < MAX_PRODUCTS) {
        strcpy(inventory[num_products].name, name);
        inventory[num_products].quantity = quantity;
        num_products++;
    } else {
        printf("Inventory is full.\n");
    }
}

void display_inventory() {
    printf("\nProduct Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

void search_product(char *name) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("%s: %d\n", name, inventory[i].quantity);
            return;
        }
    }
    printf("%s not found.\n", name);
}

void main() {
    char command[10], product_name[PRODUCT_NAME_SIZE];
    int product_quantity, index;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("Enter command (add/display/search/quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter product name: ");
            scanf("%s", product_name);
            printf("Enter product quantity: ");
            scanf("%d", &product_quantity);
            add_product(product_name, product_quantity);
        } else if (strcmp(command, "display") == 0) {
            display_inventory();
        } else if (strcmp(command, "search") == 0) {
            printf("Enter product name to search: ");
            scanf("%s", product_name);
            search_product(product_name);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
}