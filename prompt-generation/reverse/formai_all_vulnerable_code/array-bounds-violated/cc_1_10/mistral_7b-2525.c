//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define PRODUCT_NAME_LENGTH 50

typedef struct {
    char name[PRODUCT_NAME_LENGTH];
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

void display_inventory() {
    int i;
    for (i = 0; i < num_products; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char command[50];
    int arg1, arg2;

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';

        if (sscanf(command, "%s %d", command, &arg1) == 2) {
            if (strcmp(command, "add") == 0) {
                add_product(command + 4, arg1);
            } else if (strcmp(command, "display") == 0) {
                display_inventory();
            }
        }
    }

    return 0;
}