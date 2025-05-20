//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_SIZE 50
#define MAX_DESCRIPTION_SIZE 100

typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
    char description[MAX_DESCRIPTION_SIZE];
    int quantity;
    float price;
} Product;

void addProduct(Product* products, int* numProducts) {
    printf("Enter product name: ");
    scanf("%s", products[*numProducts].name);
    printf("Enter product description: ");
    scanf("%s", products[*numProducts].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[*numProducts].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*numProducts].price);
    (*numProducts)++;
}

void displayProducts(Product* products, int numProducts) {
    printf("Product ID\tName\tDescription\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%s\t%d\t$%.2f\n", products[i].id, products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

void searchProduct(Product* products, int numProducts, int id) {
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            printf("Product found:\n");
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Description: %s\n", products[i].description);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: $%.2f\n", products[i].price);
        }
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    addProduct(products, &numProducts);
    addProduct(products, &numProducts);

    displayProducts(products, numProducts);

    int searchId;
    printf("Enter product ID to search: ");
    scanf("%d", &searchId);
    searchProduct(products, numProducts, searchId);

    return 0;
}