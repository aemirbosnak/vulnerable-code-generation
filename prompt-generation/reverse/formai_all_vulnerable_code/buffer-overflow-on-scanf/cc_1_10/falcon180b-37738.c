//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE_LENGTH 10
#define MAX_QUANTITY_LENGTH 10

struct product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char price[MAX_PRICE_LENGTH];
    char quantity[MAX_QUANTITY_LENGTH];
};

int num_products = 0;
struct product products[MAX_PRODUCTS];

void add_product(void) {
    if (num_products == MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%49s", products[num_products].name);

    printf("Enter product description: ");
    scanf("%99s", products[num_products].description);

    printf("Enter product price: ");
    scanf("%9s", products[num_products].price);

    printf("Enter product quantity: ");
    scanf("%9s", products[num_products].quantity);

    num_products++;
}

void display_all_products(void) {
    for (int i = 0; i < num_products; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: %s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Price: %s\n", products[i].price);
        printf("Quantity: %s\n\n", products[i].quantity);
    }
}

int main() {
    printf("Cyberpunk Product Inventory System\n");
    printf("---------------------------------\n");

    int choice;
    do {
        printf("1. Add product\n");
        printf("2. Display all products\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_product();
            break;
        case 2:
            display_all_products();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}