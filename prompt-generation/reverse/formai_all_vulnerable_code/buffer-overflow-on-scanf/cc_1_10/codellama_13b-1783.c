//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
/*
 * Medical Store Management System
 *
 * This program is a simple example of a medical store management system.
 * It allows the user to add, view, and remove products from a store, as well as track inventory.
 *
 * This program is written in C and uses the Linux system calls to interact with the user.
 *
 * Author: Linus Torvalds
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 25
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product(Product product) {
    products[num_products] = product;
    num_products++;
}

void view_products() {
    for (int i = 0; i < num_products; i++) {
        printf("Product %d: %s\n", i, products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: %.2f\n", products[i].price);
        printf("\n");
    }
}

void remove_product(int index) {
    if (index >= num_products) {
        printf("Invalid index\n");
        return;
    }

    for (int i = index; i < num_products - 1; i++) {
        products[i] = products[i + 1];
    }

    num_products--;
}

void update_quantity(int index, int quantity) {
    if (index >= num_products) {
        printf("Invalid index\n");
        return;
    }

    products[index].quantity = quantity;
}

int main() {
    char command[100];

    while (1) {
        printf("Enter a command: ");
        fgets(command, 100, stdin);

        if (strcmp(command, "add\n") == 0) {
            Product product;
            printf("Enter product name: ");
            fgets(product.name, MAX_NAME_LENGTH, stdin);
            printf("Enter product description: ");
            fgets(product.description, MAX_DESCRIPTION_LENGTH, stdin);
            printf("Enter product quantity: ");
            scanf("%d", &product.quantity);
            printf("Enter product price: ");
            scanf("%f", &product.price);
            add_product(product);
        } else if (strcmp(command, "view\n") == 0) {
            view_products();
        } else if (strcmp(command, "remove\n") == 0) {
            int index;
            printf("Enter product index to remove: ");
            scanf("%d", &index);
            remove_product(index);
        } else if (strcmp(command, "update\n") == 0) {
            int index;
            printf("Enter product index to update: ");
            scanf("%d", &index);
            int quantity;
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            update_quantity(index, quantity);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}