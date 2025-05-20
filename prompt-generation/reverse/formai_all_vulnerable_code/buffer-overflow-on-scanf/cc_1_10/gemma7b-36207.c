//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store product information
typedef struct product {
    char name[20];
    int quantity;
    float price;
} product;

// Define a function to add a product to the inventory
void addProduct(product *p) {
    printf("Enter product name: ");
    scanf("%s", p->name);

    printf("Enter product quantity: ");
    scanf("%d", &p->quantity);

    printf("Enter product price: ");
    scanf("%f", &p->price);
}

// Define a function to display the inventory
void displayInventory(product *p) {
    printf("Inventory:\n");
    for (int i = 0; i < p->quantity; i++) {
        printf("%s - %d - %.2f\n", p->name, p->quantity, p->price);
    }
}

// Define a function to update the inventory
void updateInventory(product *p) {
    printf("Enter product name: ");
    scanf("%s", p->name);

    printf("Enter the quantity to update: ");
    scanf("%d", &p->quantity);

    printf("Enter the new price: ");
    scanf("%f", &p->price);
}

// Main function
int main() {
    // Create an array of products
    product products[10];

    // Initialize the inventory
    for (int i = 0; i < 10; i++) {
        products[i].quantity = 0;
    }

    // Add products to the inventory
    addProduct(products);
    addProduct(products);
    addProduct(products);

    // Display the inventory
    displayInventory(products);

    // Update the inventory
    updateInventory(products);

    // Display the updated inventory
    displayInventory(products);

    return 0;
}