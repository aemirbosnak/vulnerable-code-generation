//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a product
typedef struct product {
    char name[50];
    float price;
    int quantity;
} product;

// Define the function to add a product to the cart
void add_product(product *cart, product *new_product) {
    cart->quantity++;
    strcpy(cart->name, new_product->name);
    cart->price += new_product->price;
}

// Define the function to calculate the total cost of the cart
float calculate_total(product *cart) {
    float total = 0.0;
    for (int i = 0; i < cart->quantity; i++) {
        total += cart[i].price;
    }
    return total;
}

int main() {
    // Create a list of products
    product products[] = {
        {"Coffee", 5.0, 0},
        {"Tea", 3.0, 0},
        {"Juice", 2.0, 0},
        {"Water", 1.0, 0}
    };

    // Create a shopping cart
    product cart[10];
    int cart_size = 0;

    // Add products to the cart
    add_product(cart, &products[0]);
    add_product(cart, &products[2]);

    // Calculate the total cost of the cart
    float total_cost = calculate_total(cart);

    // Print the total cost of the cart
    printf("Total cost: $%.2f", total_cost);

    return 0;
}