//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int numProducts = 0;

void addProduct() {
    if (numProducts >= MAX_PRODUCTS) {
        printf("Error: Warehouse is full.\n");
        return;
    }

    Product product;

    printf("Enter product ID: ");
    scanf("%d", &product.id);

    printf("Enter product name: ");
    scanf("%s", product.name);

    printf("Enter product description: ");
    scanf("%s", product.description);

    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);

    printf("Enter product price: ");
    scanf("%f", &product.price);

    products[numProducts] = product;
    numProducts++;

    printf("Product added successfully.\n");
}

void removeProduct() {
    int id;

    printf("Enter product ID to remove: ");
    scanf("%d", &id);

    int index = -1;

    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Product not found.\n");
        return;
    }

    for (int i = index; i < numProducts - 1; i++) {
        products[i] = products[i + 1];
    }

    numProducts--;

    printf("Product removed successfully.\n");
}

void updateProduct() {
    int id;

    printf("Enter product ID to update: ");
    scanf("%d", &id);

    int index = -1;

    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Product not found.\n");
        return;
    }

    Product product;

    printf("Enter new product name: ");
    scanf("%s", product.name);

    printf("Enter new product description: ");
    scanf("%s", product.description);

    printf("Enter new product quantity: ");
    scanf("%d", &product.quantity);

    printf("Enter new product price: ");
    scanf("%f", &product.price);

    products[index] = product;

    printf("Product updated successfully.\n");
}

void listProducts() {
    printf("Products in the warehouse:\n");

    for (int i = 0; i < numProducts; i++) {
        printf("ID: %d\n", products[i].id);
        printf("Name: %s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: %.2f\n\n", products[i].price);
    }
}

int main() {
    int choice;

    do {
        printf("Warehouse Management System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. List products\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                listProducts();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}