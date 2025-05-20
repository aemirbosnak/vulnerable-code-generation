//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

int num_products = 0;
Product products[MAX_PRODUCTS];

int add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product description: ");
    scanf("%s", products[num_products].description);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);

    num_products++;
    return 0;
}

int view_products() {
    printf("Product ID\tName\tDescription\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%s\t%d\t%.2lf\n", i + 1, products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
    return 0;
}

int search_product_by_name() {
    printf("Enter product name to search: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            printf("Product found:\n");
            printf("ID: %d\n", i + 1);
            printf("Name: %s\n", products[i].name);
            printf("Description: %s\n", products[i].description);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: $.2lf\n\n", products[i].price);
        }
    }
    return 0;
}

int search_product_by_description() {
    printf("Enter product description to search: ");
    char description[MAX_DESCRIPTION_LENGTH];
    scanf("%s", description);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(description, products[i].description) == 0) {
            printf("Product found:\n");
            printf("ID: %d\n", i + 1);
            printf("Name: %s\n", products[i].name);
            printf("Description: %s\n", products[i].description);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: $.2lf\n\n", products[i].price);
        }
    }
    return 0;
}

int main() {
    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        printf("\n1. Add product\n2. View products\n3. Search by name\n4. Search by description\n5. Exit\n");
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
            search_product_by_name();
            break;
        case 4:
            search_product_by_description();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}