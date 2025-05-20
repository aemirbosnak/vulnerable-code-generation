//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 100
#define MAX_CODE_LEN 10
#define MAX_QTY_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char code[MAX_CODE_LEN];
    int qty;
    float price;
} product;

product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name (max %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", products[num_products].name);

    printf("Enter product code (max %d characters): ", MAX_CODE_LEN - 1);
    scanf("%s", products[num_products].code);

    printf("Enter product quantity: ");
    scanf("%s", products[num_products].qty);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    num_products++;
}

void display_products() {
    printf("Product ID\tProduct Name\tProduct Code\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%s\t%s\t%.2f\n", i + 1, products[i].name, products[i].code, products[i].qty, products[i].price);
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        printf("1. Add product\n2. Display products\n3. Exit\n");
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
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}