//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    num_products++;
}

void remove_product() {
    num_products--;
}

void display_products() {
    for (int i = 0; i < num_products; i++) {
        printf("Product %d:\n", i+1);
        printf("Name: %s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Price: %d\n\n", products[i].price);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int price;

    do {
        printf("Product Inventory System\n");
        printf("1. Add product\n2. Remove product\n3. Display products\n0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product description: ");
                scanf("%s", description);
                printf("Enter product price: ");
                scanf("%d", &price);
                add_product();
                printf("Product added successfully!\n");
                break;
            case 2:
                remove_product();
                printf("Product removed successfully!\n");
                break;
            case 3:
                display_products();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 0);

    return 0;
}