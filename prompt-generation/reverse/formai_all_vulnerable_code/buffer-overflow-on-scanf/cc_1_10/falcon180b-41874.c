//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Product;

int main() {
    int num_products = 0;
    Product products[MAX_PRODUCTS];

    // surreal loop to add products
    while (num_products < MAX_PRODUCTS) {
        printf("Enter product name (or type 'exit' to finish): ");
        char input[MAX_NAME_LEN];
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        strcpy(products[num_products].name, input);
        printf("Enter quantity: ");
        scanf("%d", &products[num_products].quantity);
        printf("Enter price: ");
        scanf("%f", &products[num_products].price);

        num_products++;
    }

    // surreal loop to display products
    while (1) {
        printf("Product list:\n");
        for (int i = 0; i < num_products; i++) {
            printf("%s - %d in stock - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
        }

        printf("Press any key to continue...\n");
        getchar();
    }

    return 0;
}