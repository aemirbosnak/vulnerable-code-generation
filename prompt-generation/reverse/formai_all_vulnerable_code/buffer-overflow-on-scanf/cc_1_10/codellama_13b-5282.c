//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: safe
// Product Inventory System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store product details
struct product {
    char name[50];
    int quantity;
    float price;
};

// Function to add a new product to the inventory
void addProduct(struct product *products, int *size) {
    int index = *size;
    printf("Enter the name of the product: ");
    scanf("%s", products[index].name);
    printf("Enter the quantity of the product: ");
    scanf("%d", &products[index].quantity);
    printf("Enter the price of the product: ");
    scanf("%f", &products[index].price);
    *size += 1;
}

// Function to search a product in the inventory
int searchProduct(struct product *products, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to update a product in the inventory
void updateProduct(struct product *products, int index, int quantity, float price) {
    products[index].quantity = quantity;
    products[index].price = price;
}

// Function to display all products in the inventory
void displayProducts(struct product *products, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s - %d - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    struct product products[100];
    int size = 0;
    char name[50];

    addProduct(products, &size);
    addProduct(products, &size);
    addProduct(products, &size);

    displayProducts(products, size);

    int index = searchProduct(products, size, "Product 1");
    updateProduct(products, index, 50, 50.00);

    displayProducts(products, size);

    return 0;
}