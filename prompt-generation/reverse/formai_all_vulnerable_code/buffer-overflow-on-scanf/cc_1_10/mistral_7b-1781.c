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
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }
    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = quantity;
    num_products++;
}

void delete_product(char *name) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_products--;
            printf("Product %s deleted.\n", name);
            return;
        }
    }
    printf("Product %s not found.\n", name);
}

void search_product(char *name) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product %s found with quantity %d.\n", name, inventory[i].quantity);
            return;
        }
    }
    printf("Product %s not found.\n", name);
}

int main() {
    char command[10], name[PRODUCT_NAME_SIZE];
    int quantity, index;

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            scanf("%s%d", name, &quantity);
            add_product(name, quantity);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete_product(name);
        } else if (strcmp(command, "search") == 0) {
            scanf("%s", name);
            search_product(name);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}