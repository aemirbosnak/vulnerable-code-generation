//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
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
    
    Product newProduct;
    newProduct.id = productCount + 1;

    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully: %s\n", newProduct.name);
}

void removeProduct() {
    int id;
    printf("Enter product id to remove: ");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }
    
    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product removed successfully.\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    
    printf("\nProduct Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\n");
}

void displayMenu() {
    printf("Product Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Display Products\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
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
                removeProduct();
                break;
            case 3:
                displayProducts();
                break;
            case 4:
                printf("Exiting program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}