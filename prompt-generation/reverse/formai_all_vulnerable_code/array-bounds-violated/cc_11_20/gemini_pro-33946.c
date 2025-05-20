//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Array of products
product products[] = {
    {"Banana", 100, 0.50},
    {"Apple", 50, 1.00},
    {"Orange", 25, 1.50},
    {"Grape", 15, 2.00},
    {"Strawberry", 10, 2.50}
};

// Number of products
int num_products = sizeof(products) / sizeof(product);

// Main function
int main() {
    // Welcome message
    printf("Welcome to the world's most wacky product inventory system!\n");

    // Menu options
    printf("1. List all products\n");
    printf("2. Add a new product\n");
    printf("3. Remove a product\n");
    printf("4. Update a product\n");
    printf("5. Quit\n");

    // Get user choice
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Process user choice
    switch (choice) {
        case 1:
            // List all products
            printf("Here is a list of all products:\n");
            for (int i = 0; i < num_products; i++) {
                printf("%s (%d) - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
            }
            break;
        case 2:
            // Add a new product
            printf("What is the name of the new product? ");
            char name[50];
            scanf("%s", name);

            printf("What is the quantity of the new product? ");
            int quantity;
            scanf("%d", &quantity);

            printf("What is the price of the new product? ");
            float price;
            scanf("%f", &price);

            // Add the new product to the array
            product new_product = {name, quantity, price};
            products[num_products++] = new_product;

            printf("The new product has been added to the inventory.\n");
            break;
        case 3:
            // Remove a product
            printf("What is the name of the product you want to remove? ");
            char name_to_remove[50];
            scanf("%s", name_to_remove);

            // Find the product to remove
            int index_to_remove = -1;
            for (int i = 0; i < num_products; i++) {
                if (strcmp(products[i].name, name_to_remove) == 0) {
                    index_to_remove = i;
                    break;
                }
            }

            // Remove the product from the array
            if (index_to_remove != -1) {
                for (int i = index_to_remove; i < num_products - 1; i++) {
                    products[i] = products[i + 1];
                }
                num_products--;

                printf("The product has been removed from the inventory.\n");
            } else {
                printf("The product was not found in the inventory.\n");
            }
            break;
        case 4:
            // Update a product
            printf("What is the name of the product you want to update? ");
            char name_to_update[50];
            scanf("%s", name_to_update);

            // Find the product to update
            int index_to_update = -1;
            for (int i = 0; i < num_products; i++) {
                if (strcmp(products[i].name, name_to_update) == 0) {
                    index_to_update = i;
                    break;
                }
            }

            // Update the product
            if (index_to_update != -1) {
                printf("What is the new quantity of the product? ");
                scanf("%d", &products[index_to_update].quantity);

                printf("What is the new price of the product? ");
                scanf("%f", &products[index_to_update].price);

                printf("The product has been updated.\n");
            } else {
                printf("The product was not found in the inventory.\n");
            }
            break;
        case 5:
            // Quit
            printf("Thank you for using the world's most wacky product inventory system!\n");
            break;
        default:
            // Invalid choice
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
    }

    return 0;
}