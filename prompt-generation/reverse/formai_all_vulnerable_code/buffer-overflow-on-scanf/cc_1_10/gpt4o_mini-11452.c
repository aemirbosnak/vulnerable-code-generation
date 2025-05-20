//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: lively
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

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Search Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("\nInventory Full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = productCount + 1;

    printf("Enter product name: ");
    scanf(" %[^\n]%*c", newProduct.name);
    
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount] = newProduct;
    productCount++;
    printf("\nProduct added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("\nNo products in inventory.\n");
        return;
    }
    
    printf("\n--- Product List ---\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%-10s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct() {
    char name[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf(" %[^\n]%*c", name);
    
    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < productCount; i++) {
        if (strcasecmp(inventory[i].name, name) == 0) {
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", 
                    inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found in inventory.\n");
    }
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }
    
    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    productCount--;
    printf("Product deleted successfully!\n");
}

int main() {
    int choice;
    do {
        displayMenu();
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
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}