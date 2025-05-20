//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for Product Inventory System
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Function to add a new product to the inventory
void addProduct(Product *products, int *count, int capacity) {
    if (*count >= capacity) {
        printf("Inventory is full. Cannot add new product.\n");
        return;
    }
    
    printf("Enter product name: ");
    scanf("%s", products[*count].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*count].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*count].price);
    
    (*count)++;
}

// Function to display the product inventory
void displayInventory(Product *products, int count) {
    printf("Product Inventory\n");
    printf("----------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %d units - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
    printf("\n");
}

// Function to search for a product by name
int searchProduct(Product *products, int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return i;
        }
    }
    
    return -1;
}

// Function to update the quantity of a product
void updateQuantity(Product *products, int count, int index, int newQuantity) {
    if (index < 0 || index >= count) {
        printf("Invalid product index.\n");
        return;
    }
    
    products[index].quantity = newQuantity;
}

// Function to remove a product from the inventory
void removeProduct(Product *products, int *count, int capacity) {
    if (*count <= 0) {
        printf("Inventory is empty. Cannot remove any product.\n");
        return;
    }
    
    printf("Enter the index of the product to remove: ");
    scanf("%d", &index);
    
    if (index < 0 || index >= *count) {
        printf("Invalid product index.\n");
        return;
    }
    
    *count = *count - 1;
}

// Function to calculate the total value of the inventory
float calculateTotalValue(Product *products, int count) {
    float totalValue = 0;
    for (int i = 0; i < count; i++) {
        totalValue += products[i].quantity * products[i].price;
    }
    
    return totalValue;
}

// Function to sort the product inventory based on price
void sortInventory(Product *products, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (products[j].price > products[j + 1].price) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    int capacity = 10;
    Product products[capacity];
    int count = 0;
    
    // Initialize the inventory with some products
    addProduct(products, &count, capacity);
    addProduct(products, &count, capacity);
    addProduct(products, &count, capacity);
    addProduct(products, &count, capacity);
    addProduct(products, &count, capacity);
    addProduct(products, &count, capacity);
    addProduct(products, &count, capacity);
    addProduct(products, &count, capacity);
    addProduct(products, &count, capacity);
    addProduct(products, &count, capacity);
    
    // Display the initial inventory
    printf("Initial Inventory:\n");
    displayInventory(products, count);
    
    // Add new products to the inventory
    addProduct(products, &count, capacity);
    addProduct(products, &count, capacity);
    addProduct(products, &count, capacity);
    addProduct(products, &count, capacity);
    
    // Display the updated inventory
    printf("Updated Inventory:\n");
    displayInventory(products, count);
    
    // Search for a product by name
    char productName[50];
    printf("Enter the name of the product to search: ");
    scanf("%s", productName);
    int index = searchProduct(products, count, productName);
    if (index >= 0) {
        printf("Product found at index %d.\n", index);
    } else {
        printf("Product not found.\n");
    }
    
    // Update the quantity of a product
    printf("Enter the index of the product to update: ");
    scanf("%d", &index);
    int newQuantity;
    printf("Enter the new quantity: ");
    scanf("%d", &newQuantity);
    updateQuantity(products, count, index, newQuantity);
    
    // Display the updated inventory
    printf("Updated Inventory:\n");
    displayInventory(products, count);
    
    // Remove a product from the inventory
    printf("Enter the index of the product to remove: ");
    scanf("%d", &index);
    removeProduct(products, &count, capacity);
    
    // Display the updated inventory
    printf("Updated Inventory:\n");
    displayInventory(products, count);
    
    // Calculate the total value of the inventory
    float totalValue = calculateTotalValue(products, count);
    printf("Total value of the inventory: $%.2f\n", totalValue);
    
    // Sort the product inventory based on price
    sortInventory(products, count);
    
    // Display the sorted inventory
    printf("Sorted Inventory:\n");
    displayInventory(products, count);
    
    return 0;
}