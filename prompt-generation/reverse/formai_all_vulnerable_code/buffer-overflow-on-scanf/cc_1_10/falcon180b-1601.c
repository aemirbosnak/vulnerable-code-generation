//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
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
int num_products;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter product price: ");
    scanf("%s", products[num_products].price);
    num_products++;
}

void display_all_products() {
    printf("Product Name\tDescription\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t%s\t%s\n", products[i].name, products[i].description, products[i].price);
    }
}

void search_product_by_name() {
    printf("Enter product name to search: ");
    char search_name[MAX_NAME_LENGTH];
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, search_name) == 0) {
            printf("Product Name\tDescription\tPrice\n");
            printf("%s\t%s\t%s\n", products[i].name, products[i].description, products[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("Product not found\n");
    }
}

int main() {
    num_products = 0;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n2. Display all products\n3. Search product by name\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_product();
            break;
        case 2:
            display_all_products();
            break;
        case 3:
            search_product_by_name();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}