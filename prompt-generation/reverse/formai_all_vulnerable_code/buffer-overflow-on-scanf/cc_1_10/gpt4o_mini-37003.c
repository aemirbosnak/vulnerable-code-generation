//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: optimized
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

void addProduct();
void removeProduct();
void updateProduct();
void displayProducts();
int findProduct(int id);

int main() {
    int choice;

    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product\n");
        printf("4. Display Products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: removeProduct(); break;
            case 3: updateProduct(); break;
            case 4: displayProducts(); break;
            case 5: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = productCount + 1; // Simple ID assignment based on count
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void removeProduct() {
    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);

    int index = findProduct(id);
    if (index == -1) {
        printf("Product not found!\n");
        return;
    }

    for (int i = index; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product removed successfully!\n");
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    int index = findProduct(id);
    if (index == -1) {
        printf("Product not found!\n");
        return;
    }

    printf("Enter new product name: ");
    scanf("%s", inventory[index].name);
    printf("Enter new quantity: ");
    scanf("%d", &inventory[index].quantity);
    printf("Enter new price: ");
    scanf("%f", &inventory[index].price);

    printf("Product updated successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\n--- List of Products ---\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int findProduct(int id) {
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }
    return -1;
}