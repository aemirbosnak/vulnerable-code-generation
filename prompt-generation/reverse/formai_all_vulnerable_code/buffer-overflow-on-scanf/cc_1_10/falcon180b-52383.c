//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int choice;
    struct product products[MAX_PRODUCTS];
    int num_products = 0;

    printf("Welcome to the Product Inventory System!\n");
    printf("Please choose an option:\n");
    printf("1. Add product\n");
    printf("2. Display products\n");
    printf("3. Update product\n");
    printf("4. Delete product\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    while (choice!= 5) {
        switch (choice) {
            case 1:
                if (num_products >= MAX_PRODUCTS) {
                    printf("Sorry, maximum number of products reached.\n");
                } else {
                    printf("Enter product name: ");
                    scanf("%s", products[num_products].name);
                    printf("Enter product quantity: ");
                    scanf("%d", &products[num_products].quantity);
                    printf("Enter product price: ");
                    scanf("%f", &products[num_products].price);
                    num_products++;
                    printf("Product added successfully!\n");
                }
                break;
            case 2:
                printf("Product Name\tQuantity\tPrice\n");
                for (int i = 0; i < num_products; i++) {
                    printf("%s\t\t%d\t\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
                }
                break;
            case 3:
                printf("Enter product name to update: ");
                scanf("%s", products[num_products-1].name);
                printf("Enter new product quantity: ");
                scanf("%d", &products[num_products-1].quantity);
                printf("Enter new product price: ");
                scanf("%f", &products[num_products-1].price);
                printf("Product updated successfully!\n");
                break;
            case 4:
                printf("Enter product name to delete: ");
                scanf("%s", products[num_products-1].name);
                num_products--;
                printf("Product deleted successfully!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("Please choose an option:\n");
        scanf("%d", &choice);
    }

    return 0;
}