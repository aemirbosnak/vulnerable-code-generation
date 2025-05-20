//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_QUANTITY 1000
#define MAX_PRICE 9999.99

struct product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
};

int main() {
    int num_products = 0;
    struct product products[MAX_PRODUCTS];

    while (num_products < MAX_PRODUCTS) {
        printf("Enter product name (or 'done' to finish): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter product description: ");
        char description[MAX_DESCRIPTION_LENGTH];
        scanf("%s", description);

        printf("Enter product quantity: ");
        int quantity;
        scanf("%d", &quantity);

        printf("Enter product price: ");
        float price;
        scanf("%f", &price);

        strcpy(products[num_products].name, name);
        strcpy(products[num_products].description, description);
        products[num_products].quantity = quantity;
        products[num_products].price = price;

        num_products++;
    }

    printf("\nProduct Inventory:\n");
    printf("--------------------\n");
    printf("Name\t\tDescription\tQuantity\tPrice\n");

    for (int i = 0; i < num_products; i++) {
        printf("%-50s\t", products[i].name);
        printf("%s\t", products[i].description);
        printf("%-10d\t", products[i].quantity);
        printf("$%.2f\n", products[i].price);
    }

    return 0;
}