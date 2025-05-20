//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
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
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Display Products\n");
    printf("4. Search Product by Name\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = productCount + 1; // simple ID assignment based on count

    printf("Enter product name: ");
    scanf("%s", newProduct.name);

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount++] = newProduct; // Add new product to inventory
    printf("Product added successfully!\n");
}

void removeProduct() {
    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Invalid Product ID!\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1]; // Shift products to the left
    }
    
    productCount--;
    printf("Product removed successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory!\n");
        return;
    }
    
    printf("\n--- Inventory List ---\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------\n");
    
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct() {
    char searchName[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", searchName);
    
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
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
                removeProduct();
                break;
            case 3:
                displayProducts();
                break;
            case 4:
                searchProduct();
                break;
            case 5:
                printf("Exiting the Product Inventory System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}