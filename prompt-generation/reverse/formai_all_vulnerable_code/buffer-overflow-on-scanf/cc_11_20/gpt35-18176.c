//FormAI DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the product name
#define MAX_NAME_LEN 30

// Define the maximum number of products that can be stored
#define MAX_PRODUCTS 100

struct Product {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
};

int main() {
    // Welcome message
    printf("Welcome to Retro Product Inventory System!\n");

    // Create an array of products
    struct Product products[MAX_PRODUCTS];

    // Initialize the number of products to 0
    int num_products = 0;

    // Keep running the program until the user chooses to exit
    while (1) {
        printf("\nEnter 'a' to add a product, 'r' to remove a product, or 'e' to exit: ");

        char input;
        scanf("%c", &input);

        // Clear the input buffer
        while (getchar() != '\n');

        switch (input) {
            case 'a': {
                // Add a new product
                if (num_products == MAX_PRODUCTS) {
                    printf("\nError: Maximum number of products reached.\n");
                } else {
                    printf("\nEnter the name of the product: ");
                    scanf("%s", products[num_products].name);

                    printf("Enter the quantity of the product: ");
                    scanf("%d", &products[num_products].quantity);

                    printf("Enter the price of the product: ");
                    scanf("%f", &products[num_products].price);

                    printf("\nProduct added successfully!\n");

                    num_products++;
                }

                break;
            }

            case 'r': {
                // Remove a product
                if (num_products == 0) {
                    printf("\nError: No products to remove.\n");
                } else {
                    printf("\nEnter the name of the product: ");

                    char name[MAX_NAME_LEN];
                    scanf("%s", name);

                    // Find the product with the matching name
                    int i;
                    for (i = 0; i < num_products; i++) {
                        if (strcmp(products[i].name, name) == 0) {
                            // Remove the product by shifting all products after it to the left
                            int j;
                            for (j = i; j < num_products - 1; j++) {
                                strcpy(products[j].name, products[j + 1].name);
                                products[j].quantity = products[j + 1].quantity;
                                products[j].price = products[j + 1].price;
                            }

                            num_products--;

                            printf("\nProduct removed successfully!\n");

                            break;
                        }
                    }

                    if (i == num_products) {
                        printf("\nError: Product not found.\n");
                    }
                }

                break;
            }

            case 'e': {
                // Exit the program
                printf("\nGoodbye!\n");
                exit(0);
            }

            default: {
                printf("\nError: Invalid input.\n");
                break;
            }
        }
    }

    return 0;
}