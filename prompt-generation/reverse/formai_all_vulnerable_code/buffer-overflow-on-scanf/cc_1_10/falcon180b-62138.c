//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    while (num_products < MAX_PRODUCTS) {
        printf("Enter product name (or 'done' to finish): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter quantity: ");
        int quantity;
        scanf("%d", &quantity);

        printf("Enter price: ");
        float price;
        scanf("%f", &price);

        strcpy(products[num_products].name, name);
        products[num_products].quantity = quantity;
        products[num_products].price = price;

        num_products++;
    }

    printf("\nProduct Inventory:\n");
    printf("--------------------\n");
    printf("Name\t\tQuantity\tPrice\n");

    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%d\t\t$%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }

    return 0;
}