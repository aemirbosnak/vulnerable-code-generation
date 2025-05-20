//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

struct product {
    char name[MAX_NAME_LEN];
    char description[MAX_NAME_LEN];
    char category[MAX_NAME_LEN];
    char barcode[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
};

void add_product(struct product *products, int num_products) {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter product category: ");
    scanf("%s", products[num_products].category);
    printf("Enter product barcode: ");
    scanf("%s", products[num_products].barcode);
    printf("Enter product price: ");
    scanf("%s", products[num_products].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
}

void display_products(struct product *products, int num_products) {
    for (int i = 0; i < num_products; i++) {
        printf("\nProduct %d:\n", i + 1);
        printf("Name: %s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Category: %s\n", products[i].category);
        printf("Barcode: %s\n", products[i].barcode);
        printf("Price: $%s\n", products[i].price);
        printf("Quantity: %d\n\n", products[i].quantity);
    }
}

int main() {
    struct product products[MAX_PRODUCTS];
    int num_products = 0;

    while (num_products < MAX_PRODUCTS) {
        printf("Do you want to add a product? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y') {
            add_product(products, num_products);
            num_products++;
        } else if (choice == 'n') {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    display_products(products, num_products);

    return 0;
}