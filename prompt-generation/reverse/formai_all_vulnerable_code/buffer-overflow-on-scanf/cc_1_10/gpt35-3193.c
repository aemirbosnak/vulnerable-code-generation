//FormAI DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_CATEGORY_NAME_LENGTH 20
#define MAX_STOCK_COUNT 1000

// Product structure
typedef struct product {
    char name[MAX_PRODUCT_NAME_LENGTH];
    char category[MAX_CATEGORY_NAME_LENGTH];
    int stock;
} Product;

// Global variables
Product products[MAX_STOCK_COUNT];
int productCount = 0;

// Function to add a product to the inventory
void addProduct(char *name, char *category, int stock) {
    if (productCount >= MAX_STOCK_COUNT) {
        printf("Inventory is full.\n");
        return;
    }

    Product newProduct;
    strcpy(newProduct.name, name);
    strcpy(newProduct.category, category);
    newProduct.stock = stock;

    products[productCount++] = newProduct;

    printf("Product added successfully.\n");
}

// Function to remove a product from the inventory
void removeProduct(char *name) {
    int indexToRemove = -1;

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, name) == 0) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        printf("Product not found.\n");
        return;
    }

    for (int i = indexToRemove; i < productCount - 1; i++) {
        products[i] = products[i+1];
    }

    productCount--;

    printf("Product removed successfully.\n");
}

// Function to display all products in the inventory
void displayProducts() {
    printf("Product\t\tCategory\tStock\n");

    for (int i = 0; i < productCount; i++) {
        printf("%s\t\t%s\t\t%d\n", products[i].name, products[i].category, products[i].stock);
    }
}

int main() {
    int option;

    do {
        printf("\nChoose an option:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Quit\n");
        printf("> ");

        scanf("%d", &option);

        switch (option) {
            case 1:
                {
                    char name[MAX_PRODUCT_NAME_LENGTH];
                    char category[MAX_CATEGORY_NAME_LENGTH];
                    int stock;

                    printf("\nEnter product name: ");
                    scanf("%s", name);

                    printf("Enter product category: ");
                    scanf("%s", category);

                    printf("Enter product stock count: ");
                    scanf("%d", &stock);

                    addProduct(name, category, stock);
                    break;
                }

            case 2:
                {
                    char name[MAX_PRODUCT_NAME_LENGTH];

                    printf("\nEnter product name: ");
                    scanf("%s", name);

                    removeProduct(name);
                    break;
                }

            case 3:
                {
                    displayProducts();
                    break;
                }

            case 4:
                {
                    printf("\nGoodbye!\n");
                    break;
                }

            default:
                {
                    printf("\nInvalid option.\n");
                    break;
                }
        }
    } while (option != 4);

    return 0;
}