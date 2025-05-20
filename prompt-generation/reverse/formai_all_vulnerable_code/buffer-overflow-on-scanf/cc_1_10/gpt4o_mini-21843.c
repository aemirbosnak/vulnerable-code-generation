//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: satisfied
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

void addProduct(Product *products, int *totalProducts);
void viewProducts(Product *products, int totalProducts);
void searchProduct(Product *products, int totalProducts);
void updateProduct(Product *products, int totalProducts);
void deleteProduct(Product *products, int *totalProducts);
void menu();

int main() {
    Product products[MAX_PRODUCTS];
    int totalProducts = 0;
    int choice;

    do {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &totalProducts);
                break;
            case 2:
                viewProducts(products, totalProducts);
                break;
            case 3:
                searchProduct(products, totalProducts);
                break;
            case 4:
                updateProduct(products, totalProducts);
                break;
            case 5:
                deleteProduct(products, &totalProducts);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void menu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Search Product\n");
    printf("4. Update Product\n");
    printf("5. Delete Product\n");
    printf("6. Exit\n");
}

void addProduct(Product *products, int *totalProducts) {
    if (*totalProducts >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = *totalProducts + 1; // Simple ID generation
    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    products[*totalProducts] = newProduct;
    (*totalProducts)++;
    printf("Product added successfully!\n");
}

void viewProducts(Product *products, int totalProducts) {
    if (totalProducts == 0) {
        printf("No products in inventory.\n");
    } else {
        printf("\n--- Product List ---\n");
        printf("ID\tName\t\tQuantity\tPrice\n");
        printf("--------------------------------------\n");
        for (int i = 0; i < totalProducts; i++) {
            printf("%d\t%s\t\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
        }
    }
}

void searchProduct(Product *products, int totalProducts) {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < totalProducts; i++) {
        if (products[i].id == id) {
            printf("Product Found: %s, Quantity: %d, Price: %.2f\n", products[i].name, products[i].quantity, products[i].price);
            return;
        }
    }
    printf("Product ID %d not found.\n", id);
}

void updateProduct(Product *products, int totalProducts) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < totalProducts; i++) {
        if (products[i].id == id) {
            printf("Updating product: %s\n", products[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &products[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product ID %d not found.\n", id);
}

void deleteProduct(Product *products, int *totalProducts) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *totalProducts; i++) {
        if (products[i].id == id) {
            for (int j = i; j < *totalProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            (*totalProducts)--;
            printf("Product ID %d deleted successfully!\n", id);
            return;
        }
    }
    printf("Product ID %d not found.\n", id);
}