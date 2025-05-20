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

void displayMenu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Delete Product\n");
    printf("4. Search Product\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product name: ");
    getchar(); // To clear newline from the buffer
    fgets(newProduct.name, NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    
    printf("\nProduct Inventory:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
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
    printf("Product not found!\n");
}

void searchProduct() {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Product found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product not found!\n");
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
                displayProducts(); 
                break;
            case 3: 
                deleteProduct(); 
                break;
            case 4: 
                searchProduct(); 
                break;
            case 5: 
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}