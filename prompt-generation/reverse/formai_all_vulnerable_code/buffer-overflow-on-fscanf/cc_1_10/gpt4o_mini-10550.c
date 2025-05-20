//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: invasive
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
        printf("Inventory full, can't add more products.\n");
        return;
    }
    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully.\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\nProduct Inventory:\n");
    printf("---------------------------------------------------\n");
    printf("| %-20s | %-8s | %-10s |\n", "Product Name", "Quantity", "Price");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("| %-20s | %-8d | $%-9.2f |\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("---------------------------------------------------\n");
}

void updateProduct() {
    char name[NAME_LENGTH];
    printf("Enter the product name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Updating product: %s\n", inventory[i].name);
            printf("Current quantity: %d\n", inventory[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Current price: $%.2f\n", inventory[i].price);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void deleteProduct() {
    char name[NAME_LENGTH];
    printf("Enter the product name to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void saveInventory() {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
    printf("Inventory saved successfully.\n");
}

void loadInventory() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("Error opening file or file not found!\n");
        return;
    }
    productCount = 0;
    while (fscanf(file, "%s %d %f", inventory[productCount].name, &inventory[productCount].quantity, &inventory[productCount].price) != EOF) {
        productCount++;
        if (productCount >= MAX_PRODUCTS) {
            printf("Maximum product limit reached from file.\n");
            break;
        }
    }
    fclose(file);
    printf("Inventory loaded successfully.\n");
}

int main() {
    int choice;
    
    loadInventory();
    
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save Inventory\n");
        printf("6. Exit\n");
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
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                saveInventory();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}