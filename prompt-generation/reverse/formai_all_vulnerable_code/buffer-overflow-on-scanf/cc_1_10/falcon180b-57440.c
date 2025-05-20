//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_DECIMALS 2
#define MAX_CATEGORIES 10

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    char category[MAX_CATEGORIES];
} product;

product products[MAX_PRODUCTS];
int num_products;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    printf("Enter product category: ");
    scanf("%s", products[num_products].category);

    num_products++;
}

void display_products() {
    printf("\nProduct Name\tPrice\tCategory\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-50s\t%.2f\t%s\n", products[i].name, products[i].price, products[i].category);
    }
}

void search_product() {
    char search_name[MAX_NAME_LEN];
    printf("Enter product name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, search_name) == 0) {
            printf("\nProduct Name\tPrice\tCategory\n");
            printf("%-50s\t%.2f\t%s\n", products[i].name, products[i].price, products[i].category);
        }
    }
}

void main() {
    num_products = 0;

    while (1) {
        printf("\n\nProduct Inventory System\n");
        printf("1. Add product\n2. Display products\n3. Search product\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}