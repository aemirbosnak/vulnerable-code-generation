//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

int main() {
    // Create an array of products
    product products[] = {
        {"Apple", 100, 0.5},
        {"Orange", 50, 0.75},
        {"Banana", 200, 1.0},
        {"Grape", 150, 1.25},
        {"Strawberry", 100, 1.5}
    };

    // Get the number of products
    int num_products = sizeof(products) / sizeof(product);

    // Get the user's input
    char input[50];
    printf("Enter the name of the product you want to buy: ");
    scanf("%s", input);

    // Find the product in the array
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, input) == 0) {
            break;
        }
    }

    // Check if the product was found
    if (i == num_products) {
        printf("Sorry, we don't have that product in stock.\n");
    } else {
        // Get the quantity of the product
        int quantity;
        printf("Enter the quantity you want to buy: ");
        scanf("%d", &quantity);

        // Check if the quantity is available
        if (quantity > products[i].quantity) {
            printf("Sorry, we don't have that much of that product in stock.\n");
        } else {
            // Calculate the total price
            float total_price = quantity * products[i].price;

            // Print the receipt
            printf("Your total is: $%.2f\n", total_price);
        }
    }

    return 0;
}