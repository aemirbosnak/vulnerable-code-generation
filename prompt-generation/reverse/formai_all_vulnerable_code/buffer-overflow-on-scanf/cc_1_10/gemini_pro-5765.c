//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    float price;
    int quantity;
};

int main() {
    // Initialize the product inventory
    struct product inventory[100];
    int num_products = 0;

    // Add some products to the inventory
    strcpy(inventory[0].name, "Apple");
    inventory[0].id = 1;
    inventory[0].price = 1.99;
    inventory[0].quantity = 100;

    strcpy(inventory[1].name, "Orange");
    inventory[1].id = 2;
    inventory[1].price = 2.99;
    inventory[1].quantity = 50;

    strcpy(inventory[2].name, "Banana");
    inventory[2].id = 3;
    inventory[2].price = 1.49;
    inventory[2].quantity = 75;

    // Get the number of products from the user
    printf("How many products do you want to add to the inventory? ");
    scanf("%d", &num_products);

    // Add the products to the inventory
    for (int i = 0; i < num_products; i++) {
        printf("Enter the name of product %d: ", i + 4);
        scanf(" %s", inventory[i + 3].name);

        printf("Enter the ID of product %d: ", i + 4);
        scanf(" %d", &inventory[i + 3].id);

        printf("Enter the price of product %d: ", i + 4);
        scanf(" %f", &inventory[i + 3].price);

        printf("Enter the quantity of product %d: ", i + 4);
        scanf(" %d", &inventory[i + 3].quantity);
    }

    // Print the product inventory
    printf("\nProduct Inventory:\n");
    for (int i = 0; i < num_products + 3; i++) {
        printf("Product %d:\n", inventory[i].id);
        printf(" - Name: %s\n", inventory[i].name);
        printf(" - Price: $%.2f\n", inventory[i].price);
        printf(" - Quantity: %d\n", inventory[i].quantity);
        printf("\n");
    }

    return 0;
}