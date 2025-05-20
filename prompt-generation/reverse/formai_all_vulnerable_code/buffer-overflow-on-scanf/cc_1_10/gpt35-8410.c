//FormAI DATASET v1.0 Category: Product Inventory System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct product_t {
    int id;
    char name[50];
    float price;
    int stock;
} Product;

int numProducts = 0;
Product products[MAX_PRODUCTS];

void addProduct() {
    Product product;

    product.id = numProducts + 1;

    printf("Enter product name: ");
    scanf("%s", &product.name);

    printf("Enter product price: ");
    scanf("%f", &product.price);

    printf("Enter product stock: ");
    scanf("%d", &product.stock);

    products[numProducts] = product;
    numProducts += 1;

    printf("Product added successfully!\n");
}

void removeProduct() {
    int productId;

    printf("Enter product ID to remove: ");
    scanf("%d", &productId);

    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == productId) {
            for (int j = i; j < numProducts-1; j++) {
                products[j] = products[j+1];
            }
            numProducts -= 1;
            printf("Product removed successfully!\n");
            return;
        }
    }

    printf("No product with ID %d found.\n", productId);
}

void displayProducts() {
    if (numProducts == 0) {
        printf("No products found.\n");
        return;
    }

    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Price", "Stock");

    for (int i = 0; i < numProducts; i++) {
        printf("%-10d %-20s %-10.2f %-10d\n", products[i].id, products[i].name, products[i].price, products[i].stock);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayProducts();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}