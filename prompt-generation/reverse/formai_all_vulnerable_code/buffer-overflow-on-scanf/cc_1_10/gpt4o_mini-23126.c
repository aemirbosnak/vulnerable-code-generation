//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: artistic
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

void addProduct(Product *inventory, int *count);
void displayProducts(Product *inventory, int count);
void searchProduct(Product *inventory, int count);
void updateProduct(Product *inventory, int count);
void deleteProduct(Product *inventory, int *count);
void menu();

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayProducts(inventory, count);
                break;
            case 3:
                searchProduct(inventory, count);
                break;
            case 4:
                updateProduct(inventory, count);
                break;
            case 5:
                deleteProduct(inventory, &count);
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void menu() {
    printf("\n==== Product Inventory System ====\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Search Product\n");
    printf("4. Update Product\n");
    printf("5. Delete Product\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void addProduct(Product *inventory, int *count) {
    if (*count < MAX_PRODUCTS) {
        Product newProduct;
        newProduct.id = *count + 1; // Simple ID assignment for demonstration
        printf("Enter product name: ");
        scanf("%s", newProduct.name);
        printf("Enter quantity: ");
        scanf("%d", &newProduct.quantity);
        printf("Enter price: ");
        scanf("%f", &newProduct.price);

        inventory[*count] = newProduct;
        (*count)++;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory full! Cannot add more products.\n");
    }
}

void displayProducts(Product *inventory, int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\n=== Product List ===\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct(Product *inventory, int count) {
    char name[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Found Product -> ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product not found!\n");
}

void updateProduct(Product *inventory, int count) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > count) {
        printf("Invalid ID! No product found with that ID.\n");
        return;
    }

    Product *product = &inventory[id - 1]; // Adjust for zero index
    printf("Updating Product -> Name: %s, Quantity: %d, Price: %.2f\n",
           product->name, product->quantity, product->price);
    printf("Enter new quantity: ");
    scanf("%d", &product->quantity);
    printf("Enter new price: ");
    scanf("%f", &product->price);
    printf("Product updated successfully!\n");
}

void deleteProduct(Product *inventory, int *count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > *count) {
        printf("Invalid ID! No product found with that ID.\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    (*count)--;
    printf("Product deleted successfully!\n");
}