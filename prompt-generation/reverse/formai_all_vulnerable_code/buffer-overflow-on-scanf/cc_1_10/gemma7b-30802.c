//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store product information
typedef struct product {
    char name[20];
    int quantity;
    float price;
} product;

// Function to add a product to the inventory
void addProduct(product *p) {
    printf("Enter product name: ");
    scanf("%s", p->name);
    printf("Enter product quantity: ");
    scanf("%d", &p->quantity);
    printf("Enter product price: ");
    scanf("%f", &p->price);
}

// Function to display the inventory
void displayInventory(product *p) {
    printf("Inventory:\n");
    for (int i = 0; i < p->quantity; i++) {
        printf("%s - %d - %.2f\n", p->name, p->quantity, p->price);
    }
}

// Function to update product quantity
void updateQuantity(product *p) {
    printf("Enter the quantity of the product you want to update: ");
    scanf("%d", &p->quantity);
}

// Main function
int main() {
    // Create an array of products
    product products[100];

    // Initialize the inventory
    products[0].quantity = 0;

    // Add products to the inventory
    addProduct(products);

    // Display the inventory
    displayInventory(products);

    // Update product quantity
    updateQuantity(products);

    // Display the updated inventory
    displayInventory(products);

    return 0;
}