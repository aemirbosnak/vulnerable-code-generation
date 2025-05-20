//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name (max %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", products[num_products].name);

    printf("Enter product description (max %d characters): ", MAX_DESCRIPTION_LEN - 1);
    scanf("%s", products[num_products].description);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    num_products++;
}

void remove_product() {
    printf("Enter product name to remove: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    } else {
        num_products--;
        printf("Product removed.\n");
    }
}

void display_products() {
    printf("Product Name         Description         Quantity         Price\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < num_products; i++) {
        printf("%-30s %-40s %d $%.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

int main() {
    printf("Product Inventory System\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("0. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            exit(0);
        case 1:
            add_product();
            break;
        case 2:
            remove_product();
            break;
        case 3:
            display_products();
            break;
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}