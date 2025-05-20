//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;

    do {
        printf("Product Inventory System\n");
        printf("------------------------\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. View products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (num_products == MAX_PRODUCTS) {
                printf("Maximum number of products reached.\n");
            } else {
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
            break;

        case '2':
            if (num_products == 0) {
                printf("No products to remove.\n");
            } else {
                printf("Enter product name to remove: ");
                scanf("%s", products[0].name);
                for (int i = 1; i < num_products; i++) {
                    strcpy(products[i-1].name, products[i].name);
                    strcpy(products[i-1].description, products[i].description);
                    products[i-1].quantity = products[i].quantity;
                    products[i-1].price = products[i].price;
                }
                num_products--;
            }
            break;

        case '3':
            printf("Product Name\tDescription\tQuantity\tPrice\n");
            for (int i = 0; i < num_products; i++) {
                printf("%s\t%s\t%d\t%.2lf\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
            }
            break;

        case '4':
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice!= '4');

    return 0;
}