//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int id;
    float price;
    int quantity;
    char category[NAME_LENGTH];
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void displayInventory();
void restockAlert();
void searchProduct();
void deleteProduct();
void updateProductQuantity();
void clearScreen();

int main() {
    int choice;

    do {
        clearScreen();
        printf("=== Galactic Product Inventory System ===\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Restock Alert\n");
        printf("4. Search Product\n");
        printf("5. Update Product Quantity\n");
        printf("6. Delete Product\n");
        printf("0. Exit\n");
        printf("=========================================\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addProduct(); break;
            case 2: displayInventory(); break;
            case 3: restockAlert(); break;
            case 4: searchProduct(); break;
            case 5: updateProductQuantity(); break;
            case 6: deleteProduct(); break;
            case 0: printf("Exiting the system. Space awaits you!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product p;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product ID: ");
    scanf("%d", &p.id);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product category: ");
    scanf("%s", p.category);
    
    inventory[productCount++] = p;
    printf("Product added successfully!\n");
    getchar(); // To consume the newline character
    printf("Press Enter to continue...");
    getchar();
}

void displayInventory() {
    if (productCount == 0) {
        printf("No products in the inventory.\n");
    } else {
        printf("=== Product Inventory ===\n");
        for (int i = 0; i < productCount; i++) {
            Product p = inventory[i];
            printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d, Category: %s\n", p.id, p.name, p.price, p.quantity, p.category);
        }
    }
    getchar(); // To consume the newline character
    printf("Press Enter to continue...");
    getchar();
}

void restockAlert() {
    printf("=== Products Needing Restock ===\n");
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].quantity < 5) {
            printf("Alert: Product %s (ID: %d) is low on stock!\n", inventory[i].name, inventory[i].id);
        }
    }
    printf("Press Enter to continue...");
    getchar(); // To consume the newline character
    getchar();
}

void searchProduct() {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            Product p = inventory[i];
            printf("Product found: ID: %d, Name: %s, Price: %.2f, Quantity: %d, Category: %s\n", p.id, p.name, p.price, p.quantity, p.category);
            return;
        }
    }
    printf("Product not found.\n");
    getchar(); // To consume the newline character
    printf("Press Enter to continue...");
    getchar();
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
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
    getchar(); // To consume the newline character
    printf("Press Enter to continue...");
    getchar();
}

void updateProductQuantity() {
    int id, newQuantity;
    printf("Enter product ID to update quantity: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
    getchar(); // To consume the newline character
    printf("Press Enter to continue...");
    getchar();
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear screen
}