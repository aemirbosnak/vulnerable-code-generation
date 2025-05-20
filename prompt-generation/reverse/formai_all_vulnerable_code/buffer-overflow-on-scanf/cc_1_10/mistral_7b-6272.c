//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 999

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int current_product = 0;

void add_product(char *name, int quantity) {
    if (current_product >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    strcpy(inventory[current_product].name, name);
    inventory[current_product].quantity = quantity;
    current_product++;
}

void display_inventory() {
    for (int i = 0; i < current_product; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char command[10];
    int quantity;
    char name[MAX_NAME_LENGTH + 1];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            scanf("%s%d", name, &quantity);
            add_product(name, quantity);
        } else if (strcmp(command, "display") == 0) {
            display_inventory();
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}