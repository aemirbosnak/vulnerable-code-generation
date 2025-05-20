//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    num_products++;
}

void remove_product() {
    if (num_products == 0) {
        printf("Error: No products to remove.\n");
        return;
    }

    printf("Enter product name to remove: ");
    char name[50];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            num_products--;
            break;
        }
    }
}

void display_products() {
    if (num_products == 0) {
        printf("Error: No products to display.\n");
        return;
    }

    printf("Product Name\tQuantity\tPrice\n");
    printf("------------------------------------------------\n");

    int i;
    for (i = 0; i < num_products; i++) {
        printf("%s\t\t%d\t\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    int choice;
    char name[50];

    do {
        printf("Choose an option:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_products();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}