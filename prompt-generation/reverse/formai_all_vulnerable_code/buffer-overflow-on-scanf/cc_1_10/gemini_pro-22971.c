//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct Product {
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Cannot add more products. Inventory is full.\n");
        return;
    }

    Product product;

    printf("Enter product ID: ");
    scanf("%d", &product.id);

    printf("Enter product name: ");
    scanf("%s", product.name);

    printf("Enter product price: ");
    scanf("%f", &product.price);

    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);

    products[num_products++] = product;

    printf("Product added successfully.\n");
}

void remove_product() {
    int id;

    printf("Enter product ID to remove: ");
    scanf("%d", &id);

    int index = -1;

    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Product not found.\n");
        return;
    }

    for (int i = index; i < num_products - 1; i++) {
        products[i] = products[i + 1];
    }

    num_products--;

    printf("Product removed successfully.\n");
}

void update_product() {
    int id;

    printf("Enter product ID to update: ");
    scanf("%d", &id);

    int index = -1;

    for (int i = 0; i < num_products; i++) {
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

    printf("Enter product name: ");
    scanf("%s", product.name);

    printf("Enter product price: ");
    scanf("%f", &product.price);

    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);

    products[index] = product;

    printf("Product updated successfully.\n");
}

void search_product() {
    char name[MAX_NAME_LENGTH];

    printf("Enter product name to search for: ");
    scanf("%s", name);

    int found = 0;

    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Product found:\n");
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Price: %.2f\n", products[i].price);
            printf("Quantity: %d\n", products[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }
}

void list_products() {
    printf("Products:\n");
    for (int i = 0; i < num_products; i++) {
        printf("ID: %d\n", products[i].id);
        printf("Name: %s\n", products[i].name);
        printf("Price: %.2f\n", products[i].price);
        printf("Quantity: %d\n\n", products[i].quantity);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product\n");
        printf("4. Search Product\n");
        printf("5. List Products\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                update_product();
                break;
            case 4:
                search_product();
                break;
            case 5:
                list_products();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}