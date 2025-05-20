//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void listProducts();
void removeProduct();
void showMenu();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                listProducts();
                break;
            case 3:
                removeProduct();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void showMenu() {
    printf("\n=========================\n");
    printf("   Product Inventory\n");
    printf("=========================\n");
    printf("1. Add Product\n");
    printf("2. List Products\n");
    printf("3. Remove Product\n");
    printf("4. Exit\n");
    printf("=========================\n");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full, cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1;

    printf("Enter product name: ");
    fgets(newProduct.name, NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = '\0'; // Remove newline

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    clearBuffer();

    inventory[productCount] = newProduct;
    productCount++;

    printf("Product added successfully!\n");
}

void listProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nAvailable Products:\n");
    printf("ID\tName\t\tQuantity\n");
    printf("------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
}

void removeProduct() {
    if (productCount == 0) {
        printf("No products to remove.\n");
        return;
    }

    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);
    clearBuffer();

    if (id <= 0 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;

    printf("Product removed successfully!\n");
}

void clearBuffer() {
    while (getchar() != '\n');
}