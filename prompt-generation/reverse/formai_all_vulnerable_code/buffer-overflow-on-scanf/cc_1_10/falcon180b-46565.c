//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter quantity: ");
    scanf("%d", &products[num_products].quantity);
    num_products++;
}

void remove_product() {
    printf("Enter product index: ");
    int index;
    scanf("%d", &index);
    if (index >= 0 && index < num_products) {
        num_products--;
        for (int i = index; i < num_products; i++) {
            strcpy(products[i].name, products[i + 1].name);
            products[i].quantity = products[i + 1].quantity;
        }
        products[num_products].name[0] = '\0';
        products[num_products].quantity = 0;
    } else {
        printf("Invalid product index.\n");
    }
}

void display_products() {
    printf("Product Name\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    num_products = 0;
    add_product();
    add_product();
    display_products();
    remove_product();
    display_products();
    return 0;
}