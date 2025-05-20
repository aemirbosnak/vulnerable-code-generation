//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
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
    Product p;
    p.id = productCount + 1; // simple ID based on current count
    printf("Enter product name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter price: ");
    scanf("%f", &p.price);
    
    inventory[productCount++] = p;
    printf("Product added successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }
    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product deleted successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products to display.\n");
        return;
    }
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }
    Product *p = &inventory[id - 1];
    printf("Updating product: %s\n", p->name);
    printf("Enter new quantity: ");
    scanf("%d", &p->quantity);
    printf("Enter new price: ");
    scanf("%f", &p->price);
    
    printf("Product updated successfully!\n");
}

void displayMenu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Delete Product\n");
    printf("3. View Products\n");
    printf("4. Update Product\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                deleteProduct();
                break;
            case 3:
                viewProducts();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}