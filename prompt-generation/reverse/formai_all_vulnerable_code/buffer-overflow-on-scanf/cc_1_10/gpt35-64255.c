//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

/* Struct for storing product information */
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

/* Function to add a new product to the warehouse */
void addProduct(Product warehouse[], int *numProducts)
{
    Product newProduct;
    
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    warehouse[*numProducts] = newProduct;
    
    printf("Product added successfully!\n");
    *numProducts += 1;
}

/* Function to update the quantity of a product */
void updateQuantity(Product warehouse[], int numProducts)
{
    char productName[50];
    int quantity;
    int i, productIndex = -1;
    
    printf("Enter product name: ");
    scanf("%s", productName);
    
    for (i = 0; i < numProducts; i++) {
        if (strcmp(productName, warehouse[i].name) == 0) {
            productIndex = i;
            break;
        }
    }
    
    if (productIndex == -1) {
        printf("Product not found!\n");
    } else {
        printf("Enter new quantity: ");
        scanf("%d", &quantity);
        
        warehouse[productIndex].quantity = quantity;
        
        printf("Quantity updated successfully!\n");
    }
}

/* Function to display all products in the warehouse */
void displayProducts(Product warehouse[], int numProducts)
{
    int i;
    
    printf("Product Name\tQuantity\tPrice\n");
    
    for (i = 0; i < numProducts; i++) {
        printf("%s\t\t%d\t\t%.2f\n", warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

/* Main function */
int main()
{
    Product warehouse[MAX_PRODUCTS];
    int numProducts = 0;
    int choice;
    
    while (1) {
        printf("1. Add Product\n");
        printf("2. Update Quantity\n");
        printf("3. Display Products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(warehouse, &numProducts);
                break;
            case 2:
                updateQuantity(warehouse, numProducts);
                break;
            case 3:
                displayProducts(warehouse, numProducts);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}