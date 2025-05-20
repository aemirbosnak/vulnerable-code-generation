//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: authentic
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
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = productCount + 1; // Simple ID assignment
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    inventory[productCount] = newProduct;
    productCount++;
    
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

Product* searchProduct(int id) {
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            return &inventory[i];
        }
    }
    return NULL; // Not found
}

void deleteProduct(int id) {
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            inventory[i] = inventory[productCount - 1]; // Replace with last product
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}

void menu() {
    printf("\nProduct Inventory System\n");
    printf("-------------------------\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Search Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
}

int main() {
    int choice, id;
    
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                printf("Enter product ID to search: ");
                scanf("%d", &id);
                Product* foundProduct = searchProduct(id);
                if (foundProduct) {
                    printf("Found product - ID: %d, Name: %s, Price: %.2f, Quantity: %d\n",
                           foundProduct->id, foundProduct->name, foundProduct->price, foundProduct->quantity);
                } else {
                    printf("Product with ID %d not found.\n", id);
                }
                break;
            case 4:
                printf("Enter product ID to delete: ");
                scanf("%d", &id);
                deleteProduct(id);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}