//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char price[MAX_PRICE_LENGTH];
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product description: ");
    scanf("%s", products[num_products].description);

    printf("Enter product price: ");
    scanf("%s", products[num_products].price);

    num_products++;
}

void display_products() {
    printf("\nProduct Inventory:\n");
    printf("--------------------\n");

    int i;
    for (i = 0; i < num_products; i++) {
        printf("%d. %s\n", i+1, products[i].name);
        printf("%s\n", products[i].description);
        printf("%s\n\n", products[i].price);
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");

    int choice;
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add a product\n");
        printf("2. Display products\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                printf("Thank you for using the Product Inventory System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}