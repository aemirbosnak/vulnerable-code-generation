//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void add_product(char* name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    strncpy(products[num_products].name, name, MAX_NAME_LEN);
    products[num_products].quantity = quantity;

    num_products++;
}

void print_products() {
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s: %d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    num_products = 0;

    while (1) {
        printf("Enter command (add/print/exit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_NAME_LEN];
            int quantity;

            printf("Enter product name: ");
            scanf("%s", name);

            printf("Enter quantity: ");
            scanf("%d", &quantity);

            add_product(name, quantity);
        } else if (strcmp(command, "print") == 0) {
            print_products();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}