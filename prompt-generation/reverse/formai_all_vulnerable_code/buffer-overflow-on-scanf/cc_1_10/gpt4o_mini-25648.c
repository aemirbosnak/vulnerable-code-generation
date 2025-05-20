//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 200

typedef struct {
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void displayMenu() {
    printf("\n=== Product Inventory System ===\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Warning: Inventory is full. Cannot add more products!\n");
        return;
    }
    
    Product newProduct;
    
    printf("Enter product name: ");
    scanf(" %49[^\n]", newProduct.name); // Scan with whitespace allowed
    printf("Enter product description: ");
    scanf(" %199[^\n]", newProduct.description);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products to display!\n");
        return;
    }

    printf("\n=== Current Inventory ===\n");
    for (int i = 0; i < productCount; i++) {
        printf("Product %d: %s\n", i + 1, inventory[i].name);
        printf(" - Description: %s\n", inventory[i].description);
        printf(" - Quantity: %d\n", inventory[i].quantity);
        printf(" - Price: $%.2f\n", inventory[i].price);
    }
}

void updateProduct() {
    int index;
    printf("Enter the product number to update (1-%d): ", productCount);
    scanf("%d", &index);
    
    if (index < 1 || index > productCount) {
        printf("Sensitive Alert: Invalid product number!\n");
        return;
    }
    
    printf("Updating Product %d: %s\n", index, inventory[index - 1].name);
    
    printf("Enter new name (leave blank to keep unchanged): ");
    char newName[NAME_LENGTH];
    scanf(" %49[^\n]", newName);
    
    if (strlen(newName) > 0) {
        strcpy(inventory[index - 1].name, newName);
    }
    
    printf("Enter new description (leave blank to keep unchanged): ");
    char newDesc[DESC_LENGTH];
    scanf(" %199[^\n]", newDesc);
    
    if (strlen(newDesc) > 0) {
        strcpy(inventory[index - 1].description, newDesc);
    }
    
    printf("Enter new quantity (enter -1 to keep unchanged): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    
    if (newQuantity != -1) {
        inventory[index - 1].quantity = newQuantity;
    }
    
    printf("Enter new price (enter -1 to keep unchanged): ");
    float newPrice;
    scanf("%f", &newPrice);
    
    if (newPrice != -1) {
        inventory[index - 1].price = newPrice;
    }
    
    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int index;
    printf("Enter the product number to delete (1-%d): ", productCount);
    scanf("%d", &index);
    
    if (index < 1 || index > productCount) {
        printf("Caution: Invalid product number!\n");
        return;
    }
    
    for (int i = index - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    productCount--;
    printf("Product deleted successfully!\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("Exiting... make sure nothing suspicious happens!\n");
                exit(0);
            default:
                printf("Alert: Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}