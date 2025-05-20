//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CATEGORY_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int stock;
} Product;

int main() {
    Product inventory[MAX_PRODUCTS];
    int num_products = 0;
    char option;

    do {
        printf("Welcome to the Product Inventory System!\n");
        printf("Please select an option:\n");
        printf("a) Add a new product\n");
        printf("b) Update an existing product\n");
        printf("c) Remove a product\n");
        printf("d) View all products\n");
        printf("e) Search for a product\n");
        printf("f) Quit\n");
        fflush(stdin);
        scanf("%c", &option);

        switch (option) {
            case 'a':
                printf("Adding a new product...\n");

                if (num_products == MAX_PRODUCTS) {
                    printf("Error: Maximum number of products has been reached.\n");
                } else {
                    Product new_product;

                    printf("Enter the name of the product: ");
                    scanf("%s", new_product.name);

                    printf("Enter the price of the product: ");
                    scanf("%lf", &new_product.price);

                    printf("Enter the description of the product: ");
                    scanf("%s", new_product.description);

                    printf("Enter the category of the product: ");
                    scanf("%s", new_product.category);

                    printf("Enter the stock of the product: ");
                    scanf("%d", &new_product.stock);

                    inventory[num_products] = new_product;
                    num_products++;

                    printf("Product added successfully!\n");
                }

                break;

            case 'b':
                printf("Updating an existing product...\n");

                if (num_products == 0) {
                    printf("Error: No products in inventory.\n");
                } else {
                    char update_option;
                    int i, found = 0;
                    char name[MAX_NAME_LENGTH];

                    printf("Enter the name of the product to update: ");
                    scanf("%s", name);

                    for (i = 0; i < num_products; i++) {
                        if (strcmp(inventory[i].name, name) == 0) {
                            found = 1;

                            printf("Please select an option:\n");
                            printf("a) Update name\n");
                            printf("b) Update price\n");
                            printf("c) Update description\n");
                            printf("d) Update category\n");
                            printf("e) Update stock\n");
                            fflush(stdin);
                            scanf("%c", &update_option);

                            switch (update_option) {
                                case 'a':
                                    printf("Enter the new name of the product: ");
                                    scanf("%s", inventory[i].name);
                                    break;

                                case 'b':
                                    printf("Enter the new price of the product: ");
                                    scanf("%lf", &inventory[i].price);
                                    break;

                                case 'c':
                                    printf("Enter the new description of the product: ");
                                    scanf("%s", inventory[i].description);
                                    break;

                                case 'd':
                                    printf("Enter the new category of the product: ");
                                    scanf("%s", inventory[i].category);
                                    break;

                                case 'e':
                                    printf("Enter the new stock of the product: ");
                                    scanf("%d", &inventory[i].stock);
                                    break;

                                default:
                                    printf("Error: Invalid option.\n");
                                    break;
                            }

                            printf("Product updated successfully!\n");
                        }
                    }

                    if (!found) {
                        printf("Error: Product not found.\n");
                    }
                }

                break;

            case 'c':
                printf("Removing a product...\n");

                if (num_products == 0) {
                    printf("Error: No products in inventory.\n");
                } else {
                    int i, found = 0;
                    char name[MAX_NAME_LENGTH];

                    printf("Enter the name of the product to remove: ");
                    scanf("%s", name);

                    for (i = 0; i < num_products; i++) {
                        if (strcmp(inventory[i].name, name) == 0) {
                            found = 1;
                            inventory[i] = inventory[num_products - 1];
                            num_products--;
                            printf("Product removed successfully!\n");
                        }
                    }

                    if (!found) {
                        printf("Error: Product not found.\n");
                    }
                }

                break;

            case 'd':
                printf("Viewing all products...\n");

                if (num_products == 0) {
                    printf("Error: No products in inventory.\n");
                } else {
                    int i;

                    for (i = 0; i < num_products; i++) {
                        printf("Name: %s\n", inventory[i].name);
                        printf("Price: %0.2f\n", inventory[i].price);
                        printf("Description: %s\n", inventory[i].description);
                        printf("Category: %s\n", inventory[i].category);
                        printf("Stock: %d\n", inventory[i].stock);
                        printf("\n");
                    }
                }

                break;

            case 'e':
                printf("Searching for a product...\n");

                if (num_products == 0) {
                    printf("Error: No products in inventory.\n");
                } else {
                    char name[MAX_NAME_LENGTH];
                    int i, found = 0;

                    printf("Enter the name of the product to search for: ");
                    scanf("%s", name);

                    for (i = 0; i < num_products; i++) {
                        if (strcmp(inventory[i].name, name) == 0) {
                            found = 1;
                            printf("Name: %s\n", inventory[i].name);
                            printf("Price: %0.2f\n", inventory[i].price);
                            printf("Description: %s\n", inventory[i].description);
                            printf("Category: %s\n", inventory[i].category);
                            printf("Stock: %d\n", inventory[i].stock);
                            printf("\n");
                        }
                    }

                    if (!found) {
                        printf("Error: Product not found.\n");
                    }
                }

                break;

            case 'f':
                printf("Thank you for using the Product Inventory System!\n");
                break;

            default:
                printf("Error: Invalid option.\n");
                break;
        }
    } while (option != 'f');

    return 0;
}