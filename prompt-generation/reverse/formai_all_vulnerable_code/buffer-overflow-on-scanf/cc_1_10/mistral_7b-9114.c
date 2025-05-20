//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 100

typedef struct {
    char name[MAX_NAME_LEN];
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
        printf("Inventory is full!\n");
    }
}

void display_inventory() {
    int i;
    for (i = 0; i < num_products; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char command[10];
    char product_name[MAX_NAME_LEN];
    int quantity;

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s%d", product_name, &quantity);
            add_product(product_name, quantity);
        } else if (strcmp(command, "display") == 0) {
            display_inventory();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}