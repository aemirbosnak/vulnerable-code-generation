//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CATEGORY_LENGTH 20
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name (max %d characters):\n", MAX_NAME_LENGTH - 1);
    scanf("%s", products[num_products].name);

    printf("Enter product description (max %d characters):\n", MAX_DESCRIPTION_LENGTH - 1);
    scanf("%s", products[num_products].description);

    printf("Enter product category (max %d characters):\n", MAX_CATEGORY_LENGTH - 1);
    scanf("%s", products[num_products].category);

    printf("Enter product quantity:\n");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price:\n");
    scanf("%f", &products[num_products].price);

    num_products++;
}

void display_products() {
    printf("Product List:\n");
    printf("--------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("Name: %s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Category: %s\n", products[i].category);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2f\n\n", products[i].price);
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n\n");

    while (1) {
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Exit\n");
        printf("Enter your choice:\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}