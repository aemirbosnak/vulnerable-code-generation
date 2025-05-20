//FormAI DATASET v1.0 Category: Product Inventory System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

struct Product {
    int productID;
    char productName[MAX_NAME_LENGTH];
    float productPrice;
    int productStock;
};

struct Product products[MAX_PRODUCTS];
int numProducts = 0;

void addProduct() {
    struct Product newProduct;
    printf("Product ID: ");
    scanf("%d", &newProduct.productID);
    printf("Product Name: ");
    scanf("%s", newProduct.productName);
    printf("Product Price: ");
    scanf("%f", &newProduct.productPrice);
    printf("Product Stock: ");
    scanf("%d", &newProduct.productStock);
    products[numProducts++] = newProduct;
}

void printProducts() {
    printf("Product ID | Product Name | Product Price | Product Stock\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%10d | %12s | %13.2f | %12d\n", products[i].productID, products[i].productName, products[i].productPrice, products[i].productStock);
    }
}

void searchProduct() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter product name: ");
    scanf("%s", searchName);

    for (int i = 0; i < numProducts; i++) {
        if (strcmp(searchName, products[i].productName) == 0) {
            printf("Product found!\n");
            printf("Product ID: %d\n", products[i].productID);
            printf("Product Name: %s\n", products[i].productName);
            printf("Product Price: %.2f\n", products[i].productPrice);
            printf("Product Stock: %d\n", products[i].productStock);
            return;
        }
    }

    printf("Product not found.\n");
}

int main() {
    int choice;

    do {
        printf("1. Add new product\n");
        printf("2. Print all products\n");
        printf("3. Search for a product\n");
        printf("4. Quit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                printProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}