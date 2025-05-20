//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: light-weight
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
void showInventory();
void updateProduct();
void deleteProduct();
void findProduct();
void displayMenu();

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addProduct(); break;
            case 2: showInventory(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: findProduct(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. Show Inventory\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Find Product\n");
    printf("6. Exit\n");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1; // Product ID based on count
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void showInventory() {
    printf("\n--- Current Inventory ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
            inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    if (productCount == 0) {
        printf("Inventory is empty.\n");
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }

    printf("Updating Product ID %d:\n", id);
    printf("Enter new product name: ");
    scanf("%s", inventory[id - 1].name);
    printf("Enter new product quantity: ");
    scanf("%d", &inventory[id - 1].quantity);
    printf("Enter new product price: ");
    scanf("%f", &inventory[id - 1].price);

    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1]; // Shift products left
    }

    productCount--;
    printf("Product deleted successfully!\n");
}

void findProduct() {
    char name[NAME_LENGTH];
    printf("Enter product name to find: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("Product not found in inventory.\n");
    }
}