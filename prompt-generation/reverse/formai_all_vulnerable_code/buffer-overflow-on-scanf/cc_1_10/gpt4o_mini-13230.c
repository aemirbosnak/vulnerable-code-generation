//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 30

struct Product {
    char name[NAME_LENGTH];
    int quantity;
    float price;
};

struct Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    struct Product newProduct;

    printf("Enter product name: ");
    scanf(" %[^\n]%*c", newProduct.name);  // Taking string input with spaces
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount] = newProduct;
    productCount++;

    printf("Product '%s' added successfully!\n\n", newProduct.name);
}

void displayInventory() {
    if (productCount == 0) {
        printf("No products in inventory!\n\n");
        return;
    }

    printf("Product Inventory:\n");
    printf("--------------------------------------------------\n");
    printf("| %-20s | %-8s | %-8s |\n", "Product Name", "Quantity", "Price");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < productCount; i++) {
        printf("| %-20s | %-8d | $%-8.2f |\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    printf("--------------------------------------------------\n\n");
}

void modifyProduct() {
    if (productCount == 0) {
        printf("No products to modify!\n\n");
        return;
    }

    char productName[NAME_LENGTH];
    printf("Enter product name to modify: ");
    scanf(" %[^\n]%*c", productName);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            printf("Modifying product '%s'\n", productName);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product '%s' modified successfully!\n\n", productName);
            return;
        }
    }

    printf("Product '%s' not found in inventory!\n\n", productName);
}

void removeProduct() {
    if (productCount == 0) {
        printf("No products to remove!\n\n");
        return;
    }

    char productName[NAME_LENGTH];
    printf("Enter product name to remove: ");
    scanf(" %[^\n]%*c", productName);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            printf("Removing product '%s'\n", productName);
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product '%s' removed successfully!\n\n", productName);
            return;
        }
    }

    printf("Product '%s' not found in inventory!\n\n", productName);
}

void displayMenu() {
    printf("Product Inventory System\n");
    printf("--------------------------\n");
    printf("1. Add Product\n");
    printf("2. Display Inventory\n");
    printf("3. Modify Product\n");
    printf("4. Remove Product\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
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
                displayInventory();
                break;
            case 3:
                modifyProduct();
                break;
            case 4:
                removeProduct();
                break;
            case 5:
                printf("Exiting the Product Inventory System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n\n");
        }
    }

    return 0;
}