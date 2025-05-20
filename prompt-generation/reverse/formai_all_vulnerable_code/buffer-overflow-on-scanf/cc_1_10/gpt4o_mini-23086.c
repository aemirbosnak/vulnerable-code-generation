//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void removeProduct();
void displayProducts();
void updateProduct();

int main() {
    int choice;

    while (1) {
        printf("\n----- Product Inventory System -----\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Products\n");
        printf("4. Update Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayProducts();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!\n");
        }
    }
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1;

    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void removeProduct() {
    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Invalid product ID! Please try again.\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product removed successfully!\n");
}

void displayProducts() {
    printf("\n----- Current Inventory -----\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Price: $%.2f\n", inventory[i].price);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("-----------------------------\n");
    }

    if (productCount == 0) {
        printf("No products in inventory.\n");
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Invalid product ID! Please try again.\n");
        return;
    }

    printf("Updating product ID %d: \n", id);
    Product *prod = &inventory[id - 1];
    
    printf("Current Name: %s\n", prod->name);
    printf("Enter new name (or press enter to keep current): ");
    char tempName[NAME_LENGTH];
    scanf(" %[^\n]", tempName);
    if (strcmp(tempName, "") != 0) {
        strcpy(prod->name, tempName);
    }

    printf("Current Price: $%.2f\n", prod->price);
    printf("Enter new price (or press 0 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice > 0) {
        prod->price = newPrice;
    }

    printf("Current Quantity: %d\n", prod->quantity);
    printf("Enter new quantity (or -1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity != -1) {
        prod->quantity = newQuantity;
    }

    printf("Product updated successfully!\n");
}