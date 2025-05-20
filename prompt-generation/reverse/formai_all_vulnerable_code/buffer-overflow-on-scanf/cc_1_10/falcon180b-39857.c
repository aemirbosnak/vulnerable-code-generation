//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

void init_product(Product* product) {
    strcpy(product->name, "");
    product->quantity = 0;
    product->price = 0.0;
}

void add_product(Product* products, int num_products, Product new_product) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, new_product.name) == 0) {
            products[i].quantity += new_product.quantity;
            products[i].price += new_product.price;
            return;
        }
    }
    strcpy(products[num_products].name, new_product.name);
    products[num_products].quantity = new_product.quantity;
    products[num_products].price = new_product.price;
    num_products++;
}

void remove_product(Product* products, int num_products, char* name) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity = 0;
            products[i].price = 0.0;
            return;
        }
    }
}

void display_product(Product product) {
    printf("Name: %s\n", product.name);
    printf("Quantity: %d\n", product.quantity);
    printf("Price: $%.2f\n", product.price);
}

void display_products(Product* products, int num_products) {
    int i;
    for (i = 0; i < num_products; i++) {
        display_product(products[i]);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char input[MAX_NAME_LENGTH];
    char action[MAX_NAME_LENGTH];

    init_product(&products[num_products]);
    num_products++;

    while (1) {
        printf("Enter action (add/remove/display/exit): ");
        scanf("%s", action);

        if (strcmp(action, "add") == 0) {
            printf("Enter product name: ");
            scanf("%s", input);
            printf("Enter quantity: ");
            scanf("%d", &products[num_products].quantity);
            printf("Enter price: ");
            scanf("%f", &products[num_products].price);
            add_product(products, num_products, products[num_products]);
            num_products++;
        } else if (strcmp(action, "remove") == 0) {
            printf("Enter product name: ");
            scanf("%s", input);
            remove_product(products, num_products, input);
        } else if (strcmp(action, "display") == 0) {
            display_products(products, num_products);
        } else if (strcmp(action, "exit") == 0) {
            break;
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}