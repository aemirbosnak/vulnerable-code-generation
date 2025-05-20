//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Product;

void displayMenu() {
    printf("======= Product Inventory System =======\n");
    printf("1. Add Product\n");
    printf("2. Update Product\n");
    printf("3. Delete Product\n");
    printf("4. View All Products\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
    printf("========================================\n");
    printf("Please choose an option: ");
}

void addProduct(Product *products, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = *count + 1; // Simple ID assignment
    printf("Enter Product Name: ");
    scanf(" %[^\n]s", newProduct.name);
    printf("Enter Product Price: ");
    scanf("%f", &newProduct.price);
    printf("Enter Product Quantity: ");
    scanf("%d", &newProduct.quantity);

    products[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");
}

void updateProduct(Product *products, int count) {
    int id;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > count) {
        printf("Invalid Product ID!\n");
        return;
    }

    Product *product = &products[id - 1];
    printf("Updating Product: %s\n", product->name);
    printf("Enter new Product Name: ");
    scanf(" %[^\n]s", product->name);
    printf("Enter new Product Price: ");
    scanf("%f", &product->price);
    printf("Enter new Product Quantity: ");
    scanf("%d", &product->quantity);

    printf("Product updated successfully!\n");
}

void deleteProduct(Product *products, int *count) {
    int id;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > *count) {
        printf("Invalid Product ID!\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        products[i] = products[i + 1]; // Shift products left
    }
    (*count)--; // Reduce count
    printf("Product deleted successfully!\n");
}

void viewAllProducts(Product *products, int count) {
    if (count == 0) {
        printf("No products available.\n");
        return;
    }
    printf("========================================\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("========================================\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("========================================\n");
}

void searchProduct(Product *products, int count) {
    char searchName[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf(" %[^\n]s", searchName);
    
    int found = 0;
    printf("========================================\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("========================================\n");
    for (int i = 0; i < count; i++) {
        if (strstr(products[i].name, searchName) != NULL) {
            printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("No products found with the name \"%s\".\n", searchName);
    }
    printf("========================================\n");
}

int main() {
    Product products[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct(products, &productCount);
                break;
            case 2:
                updateProduct(products, productCount);
                break;
            case 3:
                deleteProduct(products, &productCount);
                break;
            case 4:
                viewAllProducts(products, productCount);
                break;
            case 5:
                searchProduct(products, productCount);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}