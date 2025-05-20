//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 999

typedef struct {
    char name[MAX_NAME_LENGTH];
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

void display_inventory() {
    printf("Product Inventory\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].quantity > 0) {
            printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
        }
    }
}

int main() {
    char command[10], name[MAX_NAME_LENGTH];
    int quantity, index = 0;

    while (1) {
        printf("Enter command (add/remove/display/quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        switch (command[0]) {
            case 'a':
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                add_product(name, quantity);
                break;

            case 'r':
                printf("Enter product name to remove: ");
                scanf("%s", name);
                remove_product(name);
                break;

            case 'd':
                display_inventory();
                break;

            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}