//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void add_product() {
    num_products++;
}

void remove_product(int index) {
    num_products--;
    for (int i = index; i < num_products; i++) {
        products[i] = products[i+1];
    }
}

void print_products() {
    printf("Product Name\tDescription\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-50s%-200s%10d%10.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    printf("Enter the number of products you want to add: ");
    scanf("%d", &num_products);
    for (int i = 0; i < num_products; i++) {
        printf("Enter product %d information:\n", i+1);
        printf("Product Name: ");
        scanf("%s", products[i].name);
        printf("Product Description: ");
        scanf("%s", products[i].description);
        printf("Product Quantity: ");
        scanf("%d", &products[i].quantity);
        printf("Product Price: ");
        scanf("%lf", &products[i].price);
        printf("\n");
    }
    printf("Product inventory added successfully!\n");
    print_products();
    return 0;
}