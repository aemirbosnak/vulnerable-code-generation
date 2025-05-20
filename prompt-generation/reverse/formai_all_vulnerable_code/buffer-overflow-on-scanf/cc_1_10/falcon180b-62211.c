//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product(Product* product) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }
    products[num_products++] = *product;
}

void remove_product(int index) {
    if (index < 0 || index >= num_products) {
        printf("Error: Invalid product index.\n");
        return;
    }
    num_products--;
    for (int i = index; i < num_products; i++) {
        products[i] = products[i+1];
    }
}

void display_products() {
    printf("Product Inventory:\n");
    printf("ID\tName\tDescription\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%s\t%d\t$%.2f\n", i+1, products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

int main() {
    Product new_product;
    int choice = 0;
    while (choice!= 4) {
        printf("Product Inventory System:\n");
        printf("1. Add Product\n2. Remove Product\n3. Display Products\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter product details:\n");
                printf("Name: ");
                scanf("%s", new_product.name);
                printf("Description: ");
                scanf("%s", new_product.description);
                printf("Quantity: ");
                scanf("%d", &new_product.quantity);
                printf("Price: $");
                scanf("%lf", &new_product.price);
                add_product(&new_product);
                break;
            case 2:
                printf("Enter product ID to remove: ");
                scanf("%d", &choice);
                remove_product(choice-1);
                break;
            case 3:
                display_products();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}