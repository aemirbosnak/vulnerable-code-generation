//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000

struct product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
};

int main() {
    int num_products = 0;
    struct product products[MAX_PRODUCTS];

    while(num_products < MAX_PRODUCTS) {
        printf("Enter product name (leave blank to finish): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if(strlen(name) == 0) {
            break;
        }

        strcpy(products[num_products].name, name);
        printf("Enter product description: ");
        scanf("%s", products[num_products].description);
        printf("Enter product quantity: ");
        scanf("%d", &products[num_products].quantity);
        printf("Enter product price: ");
        scanf("%f", &products[num_products].price);

        num_products++;
    }

    printf("\nProduct Inventory:\n");
    printf("--------------------\n");
    printf("Name\tDescription\tQuantity\tPrice\n");
    printf("--------------------\n");

    for(int i = 0; i < num_products; i++) {
        printf("%-30s%-40s%d%10.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }

    return 0;
}