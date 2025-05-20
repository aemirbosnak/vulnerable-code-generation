//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }

    Product newProduct;
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product name: ");
    scanf(" %[^\n]%*c", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory!\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%-10s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void updateProduct() {
    int id, found = 0;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Updating Product: %s\n", inventory[i].name);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Product updated successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product ID %d not found!\n", id);
    }
}

void deleteProduct() {
    int id, found = 0;
    printf("Enter the ID of the product to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product ID %d not found!\n", id);
    }
}

void searchProduct() {
    int id, found = 0;
    printf("Enter the ID of the product to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Product Found: %s, Price: %.2f, Quantity: %d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Product ID %d not found!\n", id);
    }
}

int main() {
    int choice;
    
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");
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
                searchProduct();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}