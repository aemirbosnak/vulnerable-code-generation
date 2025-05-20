//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for product
typedef struct {
    char name[50];
    int id;
    float price;
    int quantity;
} Product;

// Function to add a new product
void addProduct(Product products[], int size, int *count) {
    printf("Enter product name: ");
    scanf("%s", &products[*count].name);
    printf("Enter product ID: ");
    scanf("%d", &products[*count].id);
    printf("Enter product price: ");
    scanf("%f", &products[*count].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[*count].quantity);
    (*count)++;
}

// Function to display all products
void displayProducts(Product products[], int size, int count) {
    printf("Product List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
}

// Function to search for a specific product
int searchProduct(Product products[], int size, char name[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to update product quantity
void updateQuantity(Product products[], int size, int index, int quantity) {
    products[index].quantity += quantity;
}

// Function to delete a product
void deleteProduct(Product products[], int size, int index) {
    for (int i = index; i < size-1; i++) {
        products[i] = products[i+1];
    }
    size--;
}

int main() {
    Product products[100];
    int count = 0;

    // Initialize with some products
    addProduct(products, 100, &count);
    addProduct(products, 100, &count);

    // Display initial product list
    displayProducts(products, 100, count);

    // Search for a product
    int index = searchProduct(products, 100, "Product 1");
    if (index!= -1) {
        printf("Found product at index %d\n", index);
    } else {
        printf("Product not found\n");
    }

    // Update product quantity
    updateQuantity(products, 100, 0, 10);
    displayProducts(products, 100, count);

    // Delete a product
    deleteProduct(products, 100, 1);
    displayProducts(products, 100, count);

    return 0;
}