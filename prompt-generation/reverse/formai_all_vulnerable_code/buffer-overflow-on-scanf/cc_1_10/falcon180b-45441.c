//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_QUANTITY 10000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

void addProduct(Product* inventory, int index) {
    printf("Enter product name: ");
    scanf("%s", inventory[index].name);

    printf("Enter product description: ");
    scanf("%s", inventory[index].description);

    printf("Enter product quantity: ");
    scanf("%d", &inventory[index].quantity);

    printf("Enter product price: ");
    scanf("%f", &inventory[index].price);
}

void displayProduct(Product product) {
    printf("Name: %s\n", product.name);
    printf("Description: %s\n", product.description);
    printf("Quantity: %d\n", product.quantity);
    printf("Price: $%.2f\n", product.price);
}

void displayInventory(Product* inventory, int size) {
    printf("Product Inventory:\n");
    for (int i = 0; i < size; i++) {
        displayProduct(inventory[i]);
    }
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int size = 0;

    while (size < MAX_PRODUCTS) {
        printf("Enter product information (name, description, quantity, price):\n");
        addProduct(inventory, size);
        size++;
    }

    displayInventory(inventory, size);

    return 0;
}