//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void displayProducts();
void updateProduct();
void deleteProduct();
void searchProduct();
void displayMenu();

int main() {
    int choice;
    do {
        displayMenu();
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
        }
    } while (choice != 6);
    return 0;
}

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
}

void addProduct() {
    if (productCount < MAX_PRODUCTS) {
        Product p;

        printf("Enter product ID: ");
        scanf("%d", &p.id);
        
        printf("Enter product name: ");
        scanf(" %[^\n]", p.name);
        
        printf("Enter product quantity: ");
        scanf("%d", &p.quantity);
        
        printf("Enter product price: ");
        scanf("%f", &p.price);

        inventory[productCount++] = p;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory is full, cannot add more products!\n");
    }
}

void displayProducts() {
    printf("\n--- Current Inventory ---\n");
    printf("%-10s %-25s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < productCount; i++) {
        printf("%-10d %-25s %-10d $%-9.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("--------------------------\n");
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Updating product %s:\n", inventory[i].name);
            printf("Enter new name: ");
            scanf(" %[^\n]", inventory[i].name);
            
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
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

void searchProduct() {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Product found: %s, Quantity: %d, Price: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product with ID %d not found!\n", id);
}