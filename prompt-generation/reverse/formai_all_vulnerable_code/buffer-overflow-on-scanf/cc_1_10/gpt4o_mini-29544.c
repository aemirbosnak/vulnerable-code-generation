//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

struct Product {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
};

struct Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full, cannot add more products.\n");
        return;
    }

    struct Product newProduct;
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount++] = newProduct;
    printf("Product added successfully.\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\nProduct Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%-10s\t%d\t\t%.2f\n", 
                inventory[i].id, 
                inventory[i].name, 
                inventory[i].quantity, 
                inventory[i].price);
    }
}

void deleteProduct() {
    int id, found = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void displayMenu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Delete Product\n");
    printf("4. Exit\n");
    printf("Select an option: ");
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
                viewProducts();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                printf("Exiting system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
    
    return 0;
}