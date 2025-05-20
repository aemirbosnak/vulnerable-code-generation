//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

product products[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int quantity, float price) {
    if (num_products == MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    strcpy(products[num_products].name, name);
    products[num_products].quantity = quantity;
    products[num_products].price = price;

    num_products++;
}

void remove_product(char *name) {
    int i;

    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_products) {
        printf("Error: Product not found.\n");
        return;
    }

    for (; i < num_products - 1; i++) {
        products[i] = products[i + 1];
    }

    num_products--;
}

void print_products() {
    int i;

    printf("Products:\n");

    for (i = 0; i < num_products; i++) {
        printf("%s %d %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    char command[50];
    char name[50];
    int quantity;
    float price;

    while (1) {
        printf("Enter command (add, remove, print, quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter product name: ");
            scanf("%s", name);

            printf("Enter quantity: ");
            scanf("%d", &quantity);

            printf("Enter price: ");
            scanf("%f", &price);

            add_product(name, quantity, price);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter product name: ");
            scanf("%s", name);

            remove_product(name);
        } else if (strcmp(command, "print") == 0) {
            print_products();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}