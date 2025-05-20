//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Product;

void addProduct(Product *inventory, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full! Can't add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = *count + 1; // Automatic ID generation
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    inventory[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n\n");
}

void listProducts(Product *inventory, int count) {
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-10s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("\n");
}

void updateProduct(Product *inventory, int count) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > count) {
        printf("Product ID not found!\n\n");
        return;
    }

    Product *product = &inventory[id - 1];
    printf("Updating product: %s\n", product->name);
    printf("Enter new name (current: %s): ", product->name);
    scanf("%s", product->name);
    printf("Enter new price (current: %.2f): ", product->price);
    scanf("%f", &product->price);
    printf("Enter new quantity (current: %d): ", product->quantity);
    scanf("%d", &product->quantity);
    
    printf("Product updated successfully!\n\n");
}

void deleteProduct(Product *inventory, int *count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > *count) {
        printf("Product ID not found!\n\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    (*count)--;

    printf("Product deleted successfully!\n\n");
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    while (1) {
        printf("Welcome to the Happy Product Inventory System!\n");
        printf("1. Add Product\n");
        printf("2. List Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                if (count == 0) {
                    printf("No products in inventory!\n\n");
                } else {
                    listProducts(inventory, count);
                }
                break;
            case 3:
                if (count == 0) {
                    printf("No products to update!\n\n");
                } else {
                    updateProduct(inventory, count);
                }
                break;
            case 4:
                if (count == 0) {
                    printf("No products to delete!\n\n");
                } else {
                    deleteProduct(inventory, &count);
                }
                break;
            case 5:
                printf("Exiting the Happy Product Inventory System! Bye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }

    return 0;
}