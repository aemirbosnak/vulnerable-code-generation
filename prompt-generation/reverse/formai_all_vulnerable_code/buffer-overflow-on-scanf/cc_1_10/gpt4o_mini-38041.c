//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: authentic
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

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    Product newProduct;
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product name: ");
    scanf(" %[^\n]%*c", newProduct.name);  // Read string with spaces
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    inventory[productCount++] = newProduct;
    printf("Product added successfully.\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("Current Inventory:\n");
    printf("ID\tName\t\tQuantity\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
}

void searchProduct() {
    int id, found = 0;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Product found:\n");
            printf("ID: %d | Name: %s | Quantity: %d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
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
            printf("Product with ID %d deleted successfully.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void menu() {
    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
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
                searchProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("Exiting the program...\n");
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