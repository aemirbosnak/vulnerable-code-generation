//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MIN_STOCK 0

typedef struct Product {
    char name[MAX_NAME_LENGTH];
    int stock;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int stock) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add product %s.\n", name);
        return;
    }
    strcpy(inventory[num_products].name, name);
    inventory[num_products].stock = stock;
    num_products++;
}

void display_inventory() {
    printf("\nCurrent inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].stock);
    }
}

int main() {
    char command[10];
    int stock;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("> ");
        scanf("%s", command);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (sscanf(command, "add %s %d", name, &stock) == 2) {
            add_product(name, stock);
            printf("Added product %s with %d units.\n", name, stock);
        } else if (strcmp(command, "display") == 0) {
            display_inventory();
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    printf("\nThank you for using our Product Inventory System!\n");
    return 0;
}