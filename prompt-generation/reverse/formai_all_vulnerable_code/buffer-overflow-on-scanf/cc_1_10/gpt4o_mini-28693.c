//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. Update Product\n");
    printf("3. Delete Product\n");
    printf("4. View Products\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1; // Assigning a new ID based on count

    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    Product *prod = &inventory[id - 1];
    printf("Updating Product ID %d\n", prod->id);
    printf("Current Name: %s\n", prod->name);
    printf("Current Quantity: %d\n", prod->quantity);
    printf("Current Price: %.2f\n", prod->price);

    printf("Enter new name: ");
    scanf(" %[^\n]", prod->name);
    printf("Enter new quantity: ");
    scanf("%d", &prod->quantity);
    printf("Enter new price: ");
    scanf("%f", &prod->price);

    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1]; // Shift products down
    }

    productCount--;
    printf("Product deleted successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products available in the inventory.\n");
        return;
    }

    printf("\n--- Product List ---\n");
    for (int i = 0; i < productCount; i++) {
        Product prod = inventory[i];
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", prod.id, prod.name, prod.quantity, prod.price);
    }
}

int main() {
    int option;

    do {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                viewProducts();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 5);

    return 0;
}