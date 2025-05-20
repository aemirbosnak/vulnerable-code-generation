//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    
    Product newProduct;
    printf("Enter product name: ");
    getchar(); // clear newline from previous input
    fgets(newProduct.name, MAX_NAME_LEN, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = '\0'; // remove newline
    
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    
    printf("\nInventory:\n");
    printf("%-30s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < productCount; i++) {
        printf("%-30s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    if (productCount == 0) {
        printf("No products in inventory to update.\n");
        return;
    }
    
    char name[MAX_NAME_LEN];
    printf("Enter the product name to update: ");
    getchar(); // clear newline
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove newline
    
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Updating product: %s\n", name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void deleteProduct() {
    if (productCount == 0) {
        printf("No products in inventory to delete.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    printf("Enter the product name to delete: ");
    getchar(); // clear newline
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove newline

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void showMenu() {
    printf("\nMedical Store Management System\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}