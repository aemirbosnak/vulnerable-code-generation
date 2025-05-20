//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: random
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
    printf("\n=== Product Inventory System ===\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

void addProduct(Product *products, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Product limit reached!\n");
        return;
    }

    Product newProduct;
    newProduct.id = *count + 1;

    printf("Enter product name: ");
    scanf("%s", newProduct.name);

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    products[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");
}

void viewProducts(Product *products, int count) {
    if (count == 0) {
        printf("No products available!\n");
        return;
    }

    printf("\nID\tName\t\tQuantity\tPrice\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void updateProduct(Product *products, int count) {
    int id;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > count) {
        printf("Invalid product ID!\n");
        return;
    }

    Product *product = &products[id - 1];
    printf("Updating product: %s\n", product->name);

    printf("New name (current: %s): ", product->name);
    scanf("%s", product->name);

    printf("New quantity (current: %d): ", product->quantity);
    scanf("%d", &product->quantity);

    printf("New price (current: %.2f): ", product->price);
    scanf("%f", &product->price);

    printf("Product updated successfully!\n");
}

void deleteProduct(Product *products, int *count) {
    int id;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > *count) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        products[i] = products[i + 1];
    }

    (*count)--;
    printf("Product deleted successfully!\n");
}

void searchProduct(Product *products, int count) {
    char name[50];
    printf("Enter the product name to search: ");
    scanf("%s", name);

    int found = 0;
    printf("\nID\tName\t\tQuantity\tPrice\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("%d\t%s\t\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("No product found with the name '%s'!\n", name);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                viewProducts(products, count);
                break;
            case 3:
                updateProduct(products, count);
                break;
            case 4:
                deleteProduct(products, &count);
                break;
            case 5:
                searchProduct(products, count);
                break;
            case 6:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}