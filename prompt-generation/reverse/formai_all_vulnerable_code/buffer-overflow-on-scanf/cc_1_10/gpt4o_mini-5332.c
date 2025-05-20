//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1;
    
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < productCount; i++) {
        printf("%-10d %-20s %-10d $%-9.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id, found = 0;
    
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Updating product: %s\n", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product ID %d not found!\n", id);
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
            printf("Product deleted successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product ID %d not found!\n", id);
    }
}

void searchProduct() {
    char searchName[NAME_LENGTH];
    int found = 0;
    
    printf("Enter product name to search: ");
    scanf("%s", searchName);

    printf("\nSearch Results:\n");
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < productCount; i++) {
        if (strstr(inventory[i].name, searchName) != NULL) {
            found = 1;
            printf("%-10d %-20s %-10d $%-9.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
    
    if (!found) {
        printf("No products found with the name '%s'.\n", searchName);
    }
}

void inventoryMenu() {
    int choice;
    
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
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
                searchProduct();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1-6.\n");
        }
    } while (choice != 6);
}

int main() {
    inventoryMenu();
    return 0;
}