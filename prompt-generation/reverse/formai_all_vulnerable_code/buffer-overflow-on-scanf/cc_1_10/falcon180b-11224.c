//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    num_products++;
    printf("Enter product name: ");
    scanf("%s", products[num_products - 1].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products - 1].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products - 1].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products - 1].price);
}

void display_products() {
    printf("Product Name\tProduct Description\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%s\t\t%d\t\t%.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add product\n2. Display products\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_product();
            break;
        case 2:
            display_products();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}