//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
} Product;

void addProduct(Product* products, int numProducts) {
    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product description: ");
    scanf("%s", newProduct.description);
    printf("Enter product category: ");
    scanf("%s", newProduct.category);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    products[numProducts] = newProduct;
    numProducts++;
}

void displayProduct(Product product) {
    printf("Product Name: %s\n", product.name);
    printf("Product Description: %s\n", product.description);
    printf("Product Category: %s\n", product.category);
    printf("Product Quantity: %d\n", product.quantity);
    printf("Product Price: $%.2f\n\n", product.price);
}

void displayProducts(Product* products, int numProducts) {
    printf("Product Inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        displayProduct(products[i]);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;
    int choice;
    
    do {
        printf("Product Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct(products, numProducts);
                break;
            case 2:
                displayProducts(products, numProducts);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);
    
    return 0;
}