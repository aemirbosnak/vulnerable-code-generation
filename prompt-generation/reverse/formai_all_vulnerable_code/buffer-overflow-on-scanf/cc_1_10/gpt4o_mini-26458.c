//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: lively
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
        printf("Inventory is full, cannot add more products!\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1; // Simple id assignment based on count.

    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name); // Allows spaces in input
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory!\n");
        return;
    }

    printf("\n--- Product Inventory ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n",
               inventory[i].id,
               inventory[i].name,
               inventory[i].quantity,
               inventory[i].price);
    }
    printf("------------------------\n");
}

void updateProduct() {
    int id;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);

    if (id <= 0 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }

    Product *product = &inventory[id - 1]; // Find product by id

    printf("Updating product ID %d\n", product->id);
    printf("Current name: %s\n", product->name);
    printf("Enter new name (or press ENTER to keep current): ");
    char newName[NAME_LENGTH];
    scanf(" %[^\n]", newName); // Read new name
    if (strlen(newName) > 0) {
        strcpy(product->name, newName);
    }

    printf("Current quantity: %d\n", product->quantity);
    printf("Enter new quantity (or -1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity != -1) {
        product->quantity = newQuantity;
    }

    printf("Current price: %.2f\n", product->price);
    printf("Enter new price (or -1 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice != -1) {
        product->price = newPrice;
    }

    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product deleted successfully!\n");
}

void menu() {
    int choice;
    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    menu();
    return 0;
}