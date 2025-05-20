//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_LENGTH 50

typedef struct {
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(const char *name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = quantity;
    num_products++;
}

void remove_product(const char *name) {
    int i;

    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_products--;
            break;
        }
    }

    if (i == num_products) {
        printf("Error: Product not found.\n");
    }
}

void print_inventory() {
    printf("\nProduct Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d\n", i + 1, inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char command[20];
    char name[PRODUCT_NAME_LENGTH];
    int quantity, index;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("Please enter a command (add, remove, print, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter product quantity: ");
            scanf("%d", &quantity);
            add_product(name, quantity);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter product name to remove: ");
            scanf("%s", name);
            remove_product(name);
        } else if (strcmp(command, "print") == 0) {
            print_inventory();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}