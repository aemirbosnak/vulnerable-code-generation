//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("\033[1;31mInventory is full! Cannot add more products.\033[0m\n");
        return;
    }
    
    Product newProduct;
    printf("Enter product name: ");
    scanf(" %[^\n]%*c", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount++] = newProduct;
    printf("\033[1;32mProduct added successfully!\033[0m\n");
}

void updateProduct() {
    char name[NAME_LENGTH];
    printf("Enter product name to update: ");
    scanf(" %[^\n]%*c", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Current quantity: %d\n", inventory[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("\033[1;32mProduct updated successfully!\033[0m\n");
            return;
        }
    }
    printf("\033[1;31mProduct not found!\033[0m\n");
}

void displayInventory() {
    if (productCount == 0) {
        printf("\033[1;33mInventory is empty!\033[0m\n");
        return;
    }

    printf("\033[1;34mProduct Inventory:\033[0m\n");
    printf("-------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Product Name", "Quantity", "Price");
    printf("-------------------------------------------------\n");
    
    for (int i = 0; i < productCount; i++) {
        printf("| %-20s | %-10d | $%-9.2f |\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("-------------------------------------------------\n");
}

void menu() {
    printf("\033[1;35m*** Welcome to the Product Inventory System ***\033[0m\n");
    printf("1. Add Product\n");
    printf("2. Update Product\n");
    printf("3. Display Inventory\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("\033[1;36mThank you for using the inventory system! Goodbye!\033[0m\n");
                exit(0);
            default:
                printf("\033[1;31mInvalid choice! Please try again.\033[0m\n");
        }
    }
    return 0;
}