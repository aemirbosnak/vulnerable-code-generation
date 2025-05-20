//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define FILE_NAME "inventory.dat"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

int productCount = 0;  
Product products[MAX_PRODUCTS];

void loadProducts() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file != NULL) {
        productCount = fread(products, sizeof(Product), MAX_PRODUCTS, file);
        fclose(file);
    }
}

void saveProducts() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file != NULL) {
        fwrite(products, sizeof(Product), productCount, file);
        fclose(file);
    }
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    
    // Checking for duplicate ID.
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == newProduct.id) {
            printf("Product ID already exists!\n");
            return;
        }
    }
    
    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    products[productCount++] = newProduct;
    saveProducts();
    printf("Product added successfully!\n");
}

void viewInventory() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%-15s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void searchProduct() {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            printf("Product found:\n");
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
            return;
        }
    }
    
    printf("Product with ID %d not found.\n", id);
}

void displayMenu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. View Inventory\n");
    printf("3. Search Product\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    loadProducts();
    
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}