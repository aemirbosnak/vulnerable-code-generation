//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    int quantity;
    float price;
} Product;

void addProduct(Product inventory[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = *count + 1;
    
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    
    printf("Enter product description: ");
    scanf(" %[^\n]", newProduct.description); // to read a line with spaces
    
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    
    inventory[*count] = newProduct;
    (*count)++;
    
    printf("Product added successfully!\n");
}

void displayProducts(Product inventory[], int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }
    
    printf("\n--- Product Inventory ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Description: %s\n", inventory[i].description);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: $%.2f\n", inventory[i].price);
        printf("------------------------\n");
    }
}

void searchProduct(Product inventory[], int count) {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    
    if (id < 1 || id > count) {
        printf("Product not found.\n");
        return;
    }
    
    Product p = inventory[id - 1];
    printf("---- Product Found ----\n");
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Description: %s\n", p.description);
    printf("Quantity: %d\n", p.quantity);
    printf("Price: $%.2f\n", p.price);
    printf("------------------------\n");
}

void updateProduct(Product inventory[], int count) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > count) {
        printf("Product not found.\n");
        return;
    }
    
    Product *p = &inventory[id - 1];
    
    printf("Updating product: %s (ID: %d)\n", p->name, p->id);
    printf("Enter new quantity: ");
    scanf("%d", &p->quantity);
    
    printf("Enter new price: ");
    scanf("%f", &p->price);
    
    printf("Product updated successfully!\n");
}

void deleteProduct(Product inventory[], int *count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > *count) {
        printf("Product not found.\n");
        return;
    }
    
    for (int i = id - 1; i < *count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    (*count)--;
    printf("Product deleted successfully!\n");
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
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
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}