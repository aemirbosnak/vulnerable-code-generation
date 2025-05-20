//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: portable
/*
 * Product Inventory System Example Program in a portable style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 100
#define MAX_PRODUCT_NAME_LENGTH 50

typedef struct {
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
    float price;
} Product;

void print_products(Product products[], int num_products) {
    for (int i = 0; i < num_products; i++) {
        printf("Product %d: %s, Quantity: %d, Price: %.2f\n", i + 1, products[i].name, products[i].quantity, products[i].price);
    }
}

void add_product(Product products[], int* num_products, char* name, int quantity, float price) {
    if (*num_products >= MAX_PRODUCTS) {
        printf("Maximum number of products reached, unable to add product.\n");
        return;
    }
    strcpy(products[*num_products].name, name);
    products[*num_products].quantity = quantity;
    products[*num_products].price = price;
    *num_products += 1;
}

void remove_product(Product products[], int* num_products, int index) {
    if (index < 0 || index >= *num_products) {
        printf("Invalid product index.\n");
        return;
    }
    for (int i = index; i < *num_products - 1; i++) {
        products[i] = products[i + 1];
    }
    *num_products -= 1;
}

void update_product(Product products[], int num_products, int index, char* name, int quantity, float price) {
    if (index < 0 || index >= num_products) {
        printf("Invalid product index.\n");
        return;
    }
    strcpy(products[index].name, name);
    products[index].quantity = quantity;
    products[index].price = price;
}

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char command[100];
    int index;
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
    float price;

    while (1) {
        printf("Enter a command (add, remove, update, print, quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter product name, quantity, and price: ");
            scanf("%s %d %f", name, &quantity, &price);
            add_product(products, &num_products, name, quantity, price);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter product index to remove: ");
            scanf("%d", &index);
            remove_product(products, &num_products, index);
        } else if (strcmp(command, "update") == 0) {
            printf("Enter product index, name, quantity, and price: ");
            scanf("%d %s %d %f", &index, name, &quantity, &price);
            update_product(products, num_products, index, name, quantity, price);
        } else if (strcmp(command, "print") == 0) {
            print_products(products, num_products);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}