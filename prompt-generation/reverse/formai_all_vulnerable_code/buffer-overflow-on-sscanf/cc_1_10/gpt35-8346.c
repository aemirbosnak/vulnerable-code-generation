//FormAI DATASET v1.0 Category: Database querying ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    float price;
} Product;

void addProductToFile(Product product) {
    FILE *file = fopen("products.txt", "a");
    fprintf(file, "%d %s %.2f\n", product.id, product.name, product.price);
    fclose(file);
}

Product *getAllProductsFromFile(int *count) {
    FILE *file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return NULL;
    }
    *count = 0;
    Product *products = NULL;
    char line[50];
    while (fgets(line, 50, file) != NULL) {
        (*count)++;
        products = realloc(products, sizeof(Product) * (*count));
        sscanf(line, "%d %s %f", &products[*count - 1].id, products[*count - 1].name, &products[*count - 1].price);
    }
    fclose(file);
    return products;
}

void printProduct(Product product) {
    printf("%d %s %.2f\n", product.id, product.name, product.price);
}

void printAllProducts(Product *products, int count) {
    for (int i = 0; i < count; i++) {
        printProduct(products[i]);
    }
}

void searchProductsByName(char *name, Product *products, int count) {
    for (int i = 0; i < count; i++) {
        if (strstr(products[i].name, name) != NULL) {
            printProduct(products[i]);
        }
    }
}

void searchProductsByPriceRange(float minPrice, float maxPrice, Product *products, int count) {
    for (int i = 0; i < count; i++) {
        if (products[i].price >= minPrice && products[i].price <= maxPrice) {
            printProduct(products[i]);
        }
    }
}

int main() {
    Product product1 = {1, "Product 1", 20.99};
    Product product2 = {2, "Product 2", 15.99};
    Product product3 = {3, "Product 3", 25.99};
    
    addProductToFile(product1);
    addProductToFile(product2);
    addProductToFile(product3);
    
    int count;
    Product *products = getAllProductsFromFile(&count);
    if (products != NULL) {
        printf("All products\n");
        printAllProducts(products, count);
        
        printf("\nSearch products by name\n");
        searchProductsByName("Prod", products, count);
        
        printf("\nSearch products by price range\n");
        searchProductsByPriceRange(18.99, 24.99, products, count);
        
        free(products);
    }
    return 0;
}