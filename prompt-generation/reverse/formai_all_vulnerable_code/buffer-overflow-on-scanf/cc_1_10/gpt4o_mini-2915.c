//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
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
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product newProduct;
    newProduct.id = productCount + 1; 
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
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
    printf("\nID\tName\tQuantity\tPrice\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
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
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product deleted successfully!\n");
}

void searchProduct() {
    char name[NAME_LEN];
    printf("Enter product name to search: ");
    scanf("%s", name);
    int found = 0;
    printf("\nID\tName\tQuantity\tPrice\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("No product found with the name: %s\n", name);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Delete Product\n");
        printf("4. Search Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}