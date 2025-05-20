//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    double price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;

    do {
        printf("Welcome to the Product Inventory System!\n");
        printf("Please choose an option:\n");
        printf("A - Add product\n");
        printf("D - Delete product\n");
        printf("U - Update product\n");
        printf("S - Search product\n");
        printf("Q - Quit\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'A':
                if(num_products >= MAX_PRODUCTS) {
                    printf("Maximum number of products reached.\n");
                } else {
                    printf("Enter product name: ");
                    scanf(" %s", products[num_products].name);
                    printf("Enter product quantity: ");
                    scanf(" %d", &products[num_products].quantity);
                    printf("Enter product price: ");
                    scanf(" %lf", &products[num_products].price);
                    num_products++;
                    printf("Product added successfully.\n");
                }
                break;

            case 'D':
                if(num_products == 0) {
                    printf("No products to delete.\n");
                } else {
                    printf("Enter product name to delete: ");
                    scanf(" %s", products[num_products-1].name);
                    num_products--;
                    printf("Product deleted successfully.\n");
                }
                break;

            case 'U':
                if(num_products == 0) {
                    printf("No products to update.\n");
                } else {
                    printf("Enter product name to update: ");
                    scanf(" %s", products[num_products-1].name);
                    printf("Enter new product quantity: ");
                    scanf(" %d", &products[num_products-1].quantity);
                    printf("Enter new product price: ");
                    scanf(" %lf", &products[num_products-1].price);
                    printf("Product updated successfully.\n");
                }
                break;

            case 'S':
                printf("Enter product name to search: ");
                scanf(" %s", products[num_products-1].name);
                printf("Product found: %s\n", products[num_products-1].name);
                break;

            case 'Q':
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 'Q');

    return 0;
}