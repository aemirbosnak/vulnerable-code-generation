//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: inquisitive
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

void displayMenu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Update Product\n");
    printf("3. Delete Product\n");
    printf("4. Display Products\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
}

void addProduct(Product *products, int *productCount) {
    if (*productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = *productCount + 1; // simple ID management
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    products[*productCount] = newProduct;
    (*productCount)++;
    printf("Product added successfully!\n");
}

void updateProduct(Product *products, int productCount) {
    int id;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);

    if (id <= 0 || id > productCount) {
        printf("Invalid ID! Please try again.\n");
        return;
    }

    Product *product = &products[id - 1];
    printf("Updating Product: %s\n", product->name);
    printf("Current quantity: %d, Enter new quantity: ", product->quantity);
    scanf("%d", &product->quantity);
    printf("Current price: %.2f, Enter new price: ", product->price);
    scanf("%f", &product->price);
    printf("Product updated successfully!\n");
}

void deleteProduct(Product *products, int *productCount) {
    int id;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > *productCount) {
        printf("Invalid ID! Please try again.\n");
        return;
    }

    // Shift products down
    for (int i = id - 1; i < *productCount - 1; i++) {
        products[i] = products[i + 1];
    }

    (*productCount)--;
    printf("Product deleted successfully!\n");
}

void displayProducts(Product *products, int productCount) {
    if (productCount == 0) {
        printf("No products to display!\n");
        return;
    }

    printf("\nProduct List:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void searchProduct(Product *products, int productCount) {
    char name[50];
    printf("Enter product name to search: ");
    scanf("%s", name);

    printf("\nSearch Results:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
            return;
        }
    }
    printf("Product not found!\n");
}

int main() {
    Product products[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
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
                displayProducts(products, productCount);
                break;
            case 5:
                searchProduct(products, productCount);
                break;
            case 6:
                printf("Exiting the Product Inventory System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}