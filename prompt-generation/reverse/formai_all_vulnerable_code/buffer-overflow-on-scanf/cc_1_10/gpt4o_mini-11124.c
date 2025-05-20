//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product product;
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter product price: ");
    scanf("%f", &product.price);
    
    inventory[productCount] = product;
    productCount++;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("Product Inventory:\n");
    printf("------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-8s |\n", "Name", "Quantity", "Price");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("| %-20s | %-10d | $%-7.2f |\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("------------------------------------------------------\n");
}

void updateProductQuantity() {
    char name[NAME_LENGTH];
    printf("Enter product name to update quantity: ");
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            int newQuantity;
            printf("Current quantity: %d\n", inventory[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

float totalStockValue() {
    float totalValue = 0.0;
    for (int i = 0; i < productCount; i++) {
        totalValue += inventory[i].quantity * inventory[i].price;
    }
    return totalValue;
}

void displayTotalStockValue() {
    printf("Total stock value: $%.2f\n", totalStockValue());
}

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product Quantity\n");
    printf("4. Display Total Stock Value\n");
    printf("5. Exit\n");
    printf("--------------------------------\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                updateProductQuantity();
                break;
            case 4:
                displayTotalStockValue();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option! Please select again.\n");
        }
    }
    return 0;
}