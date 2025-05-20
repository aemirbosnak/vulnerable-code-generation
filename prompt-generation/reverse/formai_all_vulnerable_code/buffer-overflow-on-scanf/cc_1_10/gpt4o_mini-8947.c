//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter Product Name: ");
    scanf(" %[^\n]", newProduct.name);
    printf("Enter Product Quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter Product Price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("---------------------------------------------\n");
}

void updateProduct() {
    int id;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Updating Product ID: %d\n", id);
            printf("Enter new Product Name: ");
            scanf(" %[^\n]", inventory[i].name);
            printf("Enter new Product Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new Product Price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    
    printf("Product with ID: %d not found.\n", id);
}

void deleteProduct() {
    int id;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product with ID: %d deleted successfully!\n", id);
            return;
        }
    }
    
    printf("Product with ID: %d not found.\n", id);
}

void searchProduct() {
    int id;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Product found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    
    printf("Product with ID: %d not found.\n", id);
}

void printMenu() {
    printf("\n-------- Product Inventory Menu --------\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
    printf("----------------------------------------\n");
}

int main() {
    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: searchProduct(); break;
            case 6: printf("Exiting system. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}