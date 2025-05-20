//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: interoperable
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
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full, cannot add more products.\n");
        return;
    }

    Product newProduct;
    printf("Enter Product Name: ");
    scanf("%s", newProduct.name);
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter Product Price: ");
    scanf("%f", &newProduct.price);
    printf("Enter Product Quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products available in inventory.\n");
        return;
    }

    printf("\nInventory Products:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("---------------------------------------\n");
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
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}

void menu() {
    int choice;
    do {
        printf("\n=== Product Inventory System ===\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Delete Product\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}