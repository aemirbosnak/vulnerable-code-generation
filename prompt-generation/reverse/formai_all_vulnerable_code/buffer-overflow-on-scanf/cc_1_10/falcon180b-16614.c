//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void addProduct() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Cannot add more products. Inventory is full.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);

    num_products++;

    printf("Product added successfully.\n");
}

void removeProduct() {
    if (num_products == 0) {
        printf("Error: Inventory is empty.\n");
        return;
    }

    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; i++) {
        if (id == i) {
            num_products--;
            return;
        }
    }

    printf("Product not found.\n");
}

void displayProducts() {
    if (num_products == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("Product ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%d\t%.2lf\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    num_products = 0;

    while (1) {
        printf("\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
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
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}