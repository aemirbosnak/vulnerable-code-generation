//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: complex
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

Product products[MAX_PRODUCTS];
int productCount = 0;

void displayMenu() {
    printf("\n=== Product Inventory System ===\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Delete Product\n");
    printf("4. Exit\n");
    printf("===============================\n");
    printf("Choose an option: ");
}

void addProduct() {
    if (productCount < MAX_PRODUCTS) {
        Product newProduct;

        printf("Enter product ID: ");
        scanf("%d", &newProduct.id);
        printf("Enter product name: ");
        scanf(" %[^\n]s", newProduct.name);
        printf("Enter quantity: ");
        scanf("%d", &newProduct.quantity);
        printf("Enter price: ");
        scanf("%f", &newProduct.price);

        products[productCount] = newProduct;
        productCount++;

        printf("Product added successfully!\n");
    } else {
        printf("Inventory full! Cannot add more products.\n");
    }
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products available.\n");
        return;
    }

    printf("\n=== Product List ===\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
               products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void deleteProduct() {
    if (productCount == 0) {
        printf("No products to delete.\n");
        return;
    }

    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            found = 1;
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

int main() {
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                printf("Exiting... Thank you for using the inventory system!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}