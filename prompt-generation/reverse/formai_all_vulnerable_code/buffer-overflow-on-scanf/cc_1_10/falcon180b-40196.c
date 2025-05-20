//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
}

void display_products() {
    printf("\nProduct Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t%d\t\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void search_product() {
    char search_name[50];
    printf("Enter product name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, search_name) == 0) {
            printf("\nProduct Name: %s\nQuantity: %d\nPrice: %.2f\n", products[i].name, products[i].quantity, products[i].price);
        }
    }
}

int main() {
    num_products = 0;
    while (num_products < MAX_PRODUCTS) {
        printf("\nChoose an option:\n1. Add product\n2. Display products\n3. Search product\n4. Exit\n");
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
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}