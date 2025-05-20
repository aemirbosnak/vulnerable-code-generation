//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define DESCRIPTION_LENGTH 200

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    
    printf("Enter product name: ");
    getchar();  // consume newline
    fgets(newProduct.name, NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // remove newline
    
    printf("Enter product description: ");
    fgets(newProduct.description, DESCRIPTION_LENGTH, stdin);
    newProduct.description[strcspn(newProduct.description, "\n")] = 0; // remove newline
    
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    inventory[productCount] = newProduct;
    productCount++;
    
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\n--- Product Inventory ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Description: %s\n", inventory[i].description);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("-------------------------\n");
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Updating product ID: %d\n", inventory[i].id);
            
            printf("Enter new product name: ");
            getchar();  // consume newline
            fgets(inventory[i].name, NAME_LENGTH, stdin);
            inventory[i].name[strcspn(inventory[i].name, "\n")] = 0; // remove newline
            
            printf("Enter new product description: ");
            fgets(inventory[i].description, DESCRIPTION_LENGTH, stdin);
            inventory[i].description[strcspn(inventory[i].description, "\n")] = 0; // remove newline
            
            printf("Enter new product price: ");
            scanf("%f", &inventory[i].price);
            
            printf("Enter new product quantity: ");
            scanf("%d", &inventory[i].quantity);
            
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found!\n", id);
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
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
    printf("Product with ID %d not found!\n", id);
}

void menu() {
    int choice;
    do {
        printf("\n------ Inventory Management System ------\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
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
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}