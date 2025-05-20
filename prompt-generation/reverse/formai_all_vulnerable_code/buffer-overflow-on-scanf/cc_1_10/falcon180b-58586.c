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
        printf("Error: Maximum number of products reached.\n");
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

void updateProduct() {
    printf("Enter product index to update: ");
    int index;
    scanf("%d", &index);
    if (index < 0 || index >= num_products) {
        printf("Error: Invalid product index.\n");
        return;
    }
    printf("Enter new product name: ");
    scanf("%s", products[index].name);
    printf("Enter new product quantity: ");
    scanf("%d", &products[index].quantity);
    printf("Enter new product price: ");
    scanf("%f", &products[index].price);
    printf("Product updated successfully.\n");
}

void deleteProduct() {
    printf("Enter product index to delete: ");
    int index;
    scanf("%d", &index);
    if (index < 0 || index >= num_products) {
        printf("Error: Invalid product index.\n");
        return;
    }
    num_products--;
    printf("Product deleted successfully.\n");
}

void viewProducts() {
    printf("Product ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%d\t%.2f\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    printf("Welcome to the product inventory system!\n");
    while (1) {
        printf("1. Add product\n2. Update product\n3. Delete product\n4. View products\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                viewProducts();
                break;
            case 5:
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }
    return 0;
}