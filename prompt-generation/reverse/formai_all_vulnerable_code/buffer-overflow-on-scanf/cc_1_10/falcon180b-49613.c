//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    while (num_products < MAX_PRODUCTS) {
        printf("Enter product name (or type 'done' to finish): ");
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
        double price;
        scanf("%lf", &price);

        products[num_products] = (Product) {
           .name = name,
           .description = description,
           .quantity = quantity,
           .price = price,
        };

        num_products++;
    }

    printf("Product inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2f\n\n", products[i].price);
    }

    return 0;
}