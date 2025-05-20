//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    float price;
} product;

int main() {
    // Holy moly, I can't believe you want me to write a product inventory system!
    // Well, brace yourself, because I'm about to blow your mind!

    // First, let's create an array of products. I'm going to make this big enough for 100 products, just in case you get carried away.
    product products[100];

    // Now, let's get some user input. I want to know how many products you have and what they are.
    int numProducts;
    printf("Holy moly, how many products do you have? ");
    scanf("%d", &numProducts);

    for (int i = 0; i < numProducts; i++) {
        // Get the product name.
        char productName[100];
        printf("What's the name of product %d? ", i + 1);
        scanf("%s", productName);

        // Get the product quantity.
        int productQuantity;
        printf("How many do you have? ");
        scanf("%d", &productQuantity);

        // Get the product price.
        float productPrice;
        printf("How much does it cost? ");
        scanf("%f", &productPrice);

        // Store the product information in the array.
        products[i].name = strdup(productName);
        products[i].quantity = productQuantity;
        products[i].price = productPrice;
    }

    // Now, let's print out a summary of your inventory.
    printf("Holy moly, here's a summary of your inventory:\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("| Name | Quantity | Price |\n");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < numProducts; i++) {
        printf("| %-20s | %7d | %6.2f |\n", products[i].name, products[i].quantity, products[i].price);
    }
    printf("--------------------------------------------------------------------------------\n");

    // Finally, let's free up the memory that we allocated for the product names.
    for (int i = 0; i < numProducts; i++) {
        free(products[i].name);
    }

    // And we're done! I told you I'd blow your mind.
    return 0;
}