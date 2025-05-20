//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_SIZE 100 // Maximum number of products in the warehouse
#define PRODUCT_CODE_SIZE 10 // Maximum size of product code string

// Define structs
typedef struct {
    int quantity;
    float price;
    char code[PRODUCT_CODE_SIZE];
    char description[50];
} Product;

typedef struct {
    Product products[MAX_SIZE];
    int count;
} Warehouse;

// Function prototypes
void addProduct(Warehouse *warehouse);
void removeProduct(Warehouse *warehouse);
void displayProducts(Warehouse warehouse);

// Main function
int main() {
    int choice;
    Warehouse warehouse = { .count = 0 }; // Initialize warehouse count to 0
    do {
        printf("Warehouse Management System Menu:\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Warehouse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Allow user to make choice
        switch(choice) {
            case 1:
                addProduct(&warehouse);
                break;
            case 2:
                removeProduct(&warehouse);
                break;
            case 3:
                displayProducts(warehouse);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

// Add a product to the warehouse
void addProduct(Warehouse *warehouse) {
    if(warehouse->count >= MAX_SIZE) { // Check if warehouse is full
        printf("Warehouse is full, cannot add any more products.\n");
        return;
    }
    Product newProduct;
    printf("Enter the product code: ");
    scanf("%s", newProduct.code);
    printf("Enter the product description: ");
    scanf("%s", newProduct.description);
    printf("Enter the product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter the product quantity: ");
    scanf("%d", &newProduct.quantity);
    warehouse->products[warehouse->count] = newProduct;
    warehouse->count++;
    printf("Product added successfully.\n");
}

// Remove a product from the warehouse
void removeProduct(Warehouse *warehouse) {
    char code[PRODUCT_CODE_SIZE];
    printf("Enter the product code to be removed: ");
    scanf("%s", code);

    int index = -1;
    for(int i = 0; i < warehouse->count; i++) {
        if(strcmp(warehouse->products[i].code, code) == 0) { // If product code matches
            index = i; // Store index
            break;
        }
    }
    if(index == -1) { // If index not found
        printf("Product not found in the warehouse.\n");
        return;
    }

    // Shift products left to overwrite the removed product
    for(int i = index; i < warehouse->count - 1; i++) {
        warehouse->products[i] = warehouse->products[i+1];
    }
    warehouse->count--;
    printf("Product removed successfully.\n");
}

// Display all products in the warehouse
void displayProducts(Warehouse warehouse) {
    if(warehouse.count == 0) { // If warehouse is empty
        printf("Warehouse is empty, no products to display.\n");
        return;
    }

    printf("|%-12s|%-20s|%-12s|%-8s|\n", "Product Code", "Product Description", "Price", "Quantity");
    for(int i = 0; i < warehouse.count; i++) {
        printf("|%-12s|%-20s|%-12.2f|%-8d|\n", warehouse.products[i].code, warehouse.products[i].description, warehouse.products[i].price, warehouse.products[i].quantity);
    }
}