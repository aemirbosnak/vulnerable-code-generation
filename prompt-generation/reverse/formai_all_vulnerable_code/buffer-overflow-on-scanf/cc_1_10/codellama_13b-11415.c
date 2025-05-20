//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
struct Product {
    char name[50];
    int quantity;
    float price;
};

// Function to add a new product
void addProduct(struct Product* products, int* size, int* capacity) {
    // Check if the array is full
    if (*size == *capacity) {
        // Reallocate memory for the array
        *capacity *= 2;
        products = realloc(products, *capacity * sizeof(struct Product));
    }

    // Prompt for product details
    printf("Enter product name: ");
    scanf("%s", products[*size].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*size].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*size].price);

    // Increment the size of the array
    *size += 1;
}

// Function to display all products
void displayProducts(struct Product* products, int size) {
    // Display header
    printf("Product Name\tQuantity\tPrice\n");

    // Display each product
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t%f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

// Function to find a product by name
struct Product* findProduct(struct Product* products, int size, char* name) {
    // Find the product with the given name
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return &products[i];
        }
    }

    // If the product is not found, return NULL
    return NULL;
}

// Function to update a product's quantity
void updateQuantity(struct Product* products, int size, char* name, int quantity) {
    // Find the product with the given name
    struct Product* product = findProduct(products, size, name);

    // If the product is found, update its quantity
    if (product != NULL) {
        product->quantity = quantity;
    }
}

// Function to delete a product
void deleteProduct(struct Product* products, int* size, int index) {
    // Move all products after the deleted product to the left
    for (int i = index; i < *size - 1; i++) {
        products[i] = products[i + 1];
    }

    // Decrement the size of the array
    *size -= 1;
}

int main() {
    // Initialize the array of products
    struct Product* products = NULL;
    int size = 0;
    int capacity = 10;

    // Add a few products
    addProduct(products, &size, &capacity);
    addProduct(products, &size, &capacity);
    addProduct(products, &size, &capacity);

    // Display all products
    displayProducts(products, size);

    // Update the quantity of a product
    updateQuantity(products, size, "Product 1", 10);

    // Delete a product
    deleteProduct(products, &size, 2);

    // Display all products again
    displayProducts(products, size);

    return 0;
}