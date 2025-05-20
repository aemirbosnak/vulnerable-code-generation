//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CATEGORY_LENGTH 20
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000000

struct product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
};

int main() {
    struct product products[MAX_PRODUCTS];
    int num_products = 0;

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
        printf("Enter product category: ");
        char category[MAX_CATEGORY_LENGTH];
        scanf("%s", category);
        printf("Enter product quantity: ");
        int quantity;
        scanf("%d", &quantity);
        printf("Enter product price: ");
        float price;
        scanf("%f", &price);

        strcpy(products[num_products].name, name);
        strcpy(products[num_products].description, description);
        strcpy(products[num_products].category, category);
        products[num_products].quantity = quantity;
        products[num_products].price = price;
        num_products++;
    }

    printf("Product inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Category: %s\n", products[i].category);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2f\n\n", products[i].price);
    }

    return 0;
}