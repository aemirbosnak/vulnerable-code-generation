//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: mathematical
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
    if (productCount < MAX_PRODUCTS) {
        Product p;
        printf("Enter Product ID: ");
        scanf("%d", &p.id);
        printf("Enter Product Name: ");
        scanf(" %[^\n]", p.name);
        printf("Enter Quantity: ");
        scanf("%d", &p.quantity);
        printf("Enter Price: ");
        scanf("%f", &p.price);
        
        inventory[productCount] = p;
        productCount++;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory is full!\n");
    }
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products available!\n");
        return;
    }
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%-15s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id, found = 0;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Updating product: %s\n", inventory[i].name);
            printf("Enter New Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter New Price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product not found!\n");
    }
}

void deleteProduct() {
    int id, found = 0;
    printf("Enter Product ID to delete: ");
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
        printf("Product not found!\n");
    }
}

void searchProduct() {
    char name[NAME_LENGTH];
    int found = 0;
    
    printf("Enter Product Name to search: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < productCount; i++) {
        if (strstr(inventory[i].name, name) != NULL) {
            found = 1;
            printf("Product Found: %d %-15s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
    
    if (!found) {
        printf("No product found with that name!\n");
    }
}

void displayMenu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
    printf("Select an option: ");
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
                viewProducts();
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
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}