//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_PRICE 1000000

typedef struct product {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    float price;
} Product;

int num_products = 0;
Product products[MAX_PRODUCTS];

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
    printf("Product added successfully.\n");
}

void view_products() {
    printf("Product ID\tProduct Name\tProduct Description\tProduct Price\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%s\t%.2f\n", i + 1, products[i].name, products[i].description, products[i].price);
    }
}

void search_product() {
    char search_name[MAX_NAME_LEN];
    printf("Enter product name to search: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, search_name) == 0) {
            printf("Product found: %s\n", products[i].name);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    while (1) {
        printf("\n1. Add product\n2. View products\n3. Search product\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_product();
            break;
        case 2:
            view_products();
            break;
        case 3:
            search_product();
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}