//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

void addProduct(Product* products, int count) {
    printf("Enter product name (max %d characters): ", MAX_NAME_LENGTH);
    scanf("%s", products[count].name);
    printf("Enter product description (max %d characters): ", MAX_DESCRIPTION_LENGTH);
    scanf("%s", products[count].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[count].quantity);
    printf("Enter product price: ");
    scanf("%lf", &products[count].price);
}

void displayProduct(Product product) {
    printf("Name: %s\n", product.name);
    printf("Description: %s\n", product.description);
    printf("Quantity: %d\n", product.quantity);
    printf("Price: $%.2f\n", product.price);
}

void calculateTotalValue(Product* products, int count) {
    double totalValue = 0;
    for (int i = 0; i < count; i++) {
        totalValue += products[i].quantity * products[i].price;
    }
    printf("Total value of inventory: $%.2f\n", totalValue);
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;

    while (count < MAX_PRODUCTS) {
        printf("Do you want to add a product? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            addProduct(products, count);
            count++;
        } else if (choice == 'n' || choice == 'N') {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Product inventory:\n");
    for (int i = 0; i < count; i++) {
        displayProduct(products[i]);
    }

    calculateTotalValue(products, count);

    return 0;
}