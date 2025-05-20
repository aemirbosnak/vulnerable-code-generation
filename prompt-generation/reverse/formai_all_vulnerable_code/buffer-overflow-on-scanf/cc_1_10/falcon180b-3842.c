//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void addProduct() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Product limit reached.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    num_products++;

    printf("Product added successfully.\n");
}

void viewProducts() {
    printf("Product ID\tProduct Name\tQuantity\tPrice\n");

    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%d\t%.2f\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
}

void updateProduct() {
    printf("Enter product ID: ");
    int id;
    scanf("%d", &id);

    if (id < 1 || id > num_products) {
        printf("Invalid product ID.\n");
        return;
    }

    printf("Enter new product name: ");
    scanf("%s", products[id-1].name);

    printf("Enter new product quantity: ");
    scanf("%d", &products[id-1].quantity);

    printf("Enter new product price: ");
    scanf("%f", &products[id-1].price);

    printf("Product updated successfully.\n");
}

void deleteProduct() {
    printf("Enter product ID: ");
    int id;
    scanf("%d", &id);

    if (id < 1 || id > num_products) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id-1; i < num_products-1; i++) {
        products[i] = products[i+1];
    }

    num_products--;

    printf("Product deleted successfully.\n");
}

int main() {
    int choice;

    do {
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. View products\n");
        printf("3. Update product\n");
        printf("4. Delete product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}