//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product ID: ");
    scanf("%d", &products[num_products].id);

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product description: ");
    scanf("%s", products[num_products].description);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);

    num_products++;
}

void display_products() {
    printf("Product ID | Product Name | Product Description | Quantity | Price\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d | %s | %s | %d | $%.2lf\n", products[i].id, products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

void search_product() {
    printf("Enter product ID to search: ");
    int id;
    scanf("%d", &id);

    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            printf("Product found:\n");
            printf("Product ID: %d\n", products[i].id);
            printf("Product Name: %s\n", products[i].name);
            printf("Product Description: %s\n", products[i].description);
            printf("Product Quantity: %d\n", products[i].quantity);
            printf("Product Price: $%.2lf\n", products[i].price);
        }
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search product\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                printf("Thank you for using the Product Inventory System!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}