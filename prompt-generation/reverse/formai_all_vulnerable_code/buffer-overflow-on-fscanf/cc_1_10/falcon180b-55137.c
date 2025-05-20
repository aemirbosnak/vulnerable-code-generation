//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

void readProducts(Product products[], int *numProducts) {
    FILE *fp = fopen("products.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open products file.\n");
        exit(1);
    }
    *numProducts = 0;
    while (fscanf(fp, "%s %s %d %lf", products[*numProducts].name, products[*numProducts].description, &products[*numProducts].quantity, &products[*numProducts].price)!= EOF) {
        (*numProducts)++;
    }
    fclose(fp);
}

void writeProducts(Product products[], int numProducts) {
    FILE *fp = fopen("products.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open products file.\n");
        exit(1);
    }
    for (int i = 0; i < numProducts; i++) {
        fprintf(fp, "%s %s %d %lf\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
    fclose(fp);
}

void displayProducts(Product products[], int numProducts) {
    for (int i = 0; i < numProducts; i++) {
        printf("%s - %s (%d in stock) - $%.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

void searchProduct(Product products[], int numProducts, char *name) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Found product: %s\n", products[i].name);
            printf("Description: %s\n", products[i].description);
            printf("Quantity in stock: %d\n", products[i].quantity);
            printf("Price: $%.2f\n", products[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;
    readProducts(products, &numProducts);
    char choice;
    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Display all products\n");
        printf("2. Search for a product\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
        case '1':
            displayProducts(products, numProducts);
            break;
        case '2':
            printf("Enter product name: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            searchProduct(products, numProducts, name);
            break;
        case '3':
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}