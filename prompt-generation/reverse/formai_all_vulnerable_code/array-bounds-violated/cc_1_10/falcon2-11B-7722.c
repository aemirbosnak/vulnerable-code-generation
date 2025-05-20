//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product_t {
    char name[100];
    int quantity;
    double price;
} Product;

int main() {
    Product products[5];

    // Initialize products
    strcpy(products[0].name, "Product A");
    products[0].quantity = 10;
    products[0].price = 50.99;

    strcpy(products[1].name, "Product B");
    products[1].quantity = 20;
    products[1].price = 30.99;

    strcpy(products[2].name, "Product C");
    products[2].quantity = 5;
    products[2].price = 40.99;

    strcpy(products[3].name, "Product D");
    products[3].quantity = 15;
    products[3].price = 35.99;

    strcpy(products[4].name, "Product E");
    products[4].quantity = 8;
    products[4].price = 45.99;

    // Display product inventory
    printf("Product A:\tQuantity: %d, Price: %.2f\n", products[0].quantity, products[0].price);
    printf("Product B:\tQuantity: %d, Price: %.2f\n", products[1].quantity, products[1].price);
    printf("Product C:\tQuantity: %d, Price: %.2f\n", products[2].quantity, products[2].price);
    printf("Product D:\tQuantity: %d, Price: %.2f\n", products[3].quantity, products[3].price);
    printf("Product E:\tQuantity: %d, Price: %.2f\n", products[4].quantity, products[4].price);

    // Update product quantity
    if (products[0].quantity > 0) {
        products[0].quantity -= 1;
        printf("Product A quantity updated to %d.\n", products[0].quantity);
    }

    // Add new product
    Product new_product;
    strcpy(new_product.name, "Product F");
    new_product.quantity = 3;
    new_product.price = 25.99;
    products[5] = new_product;
    printf("Product F added:\tQuantity: %d, Price: %.2f\n", new_product.quantity, new_product.price);

    // Display updated product inventory
    for (int i = 0; i < 5; i++) {
        if (i == 5) {
            printf("Product F:\tQuantity: %d, Price: %.2f\n", products[i].quantity, products[i].price);
        } else {
            printf("Product %d:\tQuantity: %d, Price: %.2f\n", i + 1, products[i].quantity, products[i].price);
        }
    }

    return 0;
}