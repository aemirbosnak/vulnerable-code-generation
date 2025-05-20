//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: future-proof
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

// Function prototypes
void addProduct();
void displayProducts();
void searchProduct();
void updateProduct();
void deleteProduct();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("Product Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                deleteProduct();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = productCount + 1;

    printf("Enter product name: ");
    fgets(newProduct.name, NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0;  // Remove newline character

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    clearBuffer();

    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nProduct Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("---------------------------------------------\n");
}

void searchProduct() {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    clearBuffer();

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Product found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    clearBuffer();

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter new product name: ");
            fgets(inventory[i].name, NAME_LENGTH, stdin);
            inventory[i].name[strcspn(inventory[i].name, "\n")] = 0;  // Remove newline character

            printf("Enter new product quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new product price: ");
            scanf("%f", &inventory[i].price);
            clearBuffer();

            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    clearBuffer();

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void clearBuffer() {
    while (getchar() != '\n');  // Clear input buffer
}