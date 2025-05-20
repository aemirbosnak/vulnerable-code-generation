//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 999

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];

void add_product(char *name, int quantity) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].quantity == 0) {
            strcpy(inventory[i].name, name);
            inventory[i].quantity = quantity;
            break;
        }
    }
}

void remove_product(char *name) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity = 0;
            break;
        }
    }
}

void list_inventory() {
    printf("Product Name\tQuantity\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].quantity > 0) {
            printf("%s\t%d\n", inventory[i].name, inventory[i].quantity);
        }
    }
}

int main() {
    char command[MAX_NAME_LEN];
    char product_name[MAX_NAME_LEN];
    int quantity;

    memset(inventory, 0, sizeof(inventory));

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("Enter command (add|remove|list|exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter product name: ");
            scanf("%s", product_name);
            printf("Enter product quantity: ");
            scanf("%d", &quantity);
            add_product(product_name, quantity);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter product name to remove: ");
            scanf("%s", product_name);
            remove_product(product_name);
        } else if (strcmp(command, "list") == 0) {
            list_inventory();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}