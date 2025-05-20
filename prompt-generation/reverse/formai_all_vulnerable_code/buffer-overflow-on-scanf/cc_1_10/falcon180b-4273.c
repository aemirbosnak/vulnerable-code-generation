//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Cannot add more products.\n");
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

void print_products() {
    printf("\nProduct Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s - %d units - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void update_product() {
    printf("\nEnter product index to update: ");
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= num_products) {
        printf("Error: Invalid product index.\n");
        return;
    }

    printf("\nEnter new product name: ");
    scanf("%s", products[index].name);

    printf("Enter new product quantity: ");
    scanf("%d", &products[index].quantity);

    printf("Enter new product price: ");
    scanf("%f", &products[index].price);
}

void delete_product() {
    printf("\nEnter product index to delete: ");
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= num_products) {
        printf("Error: Invalid product index.\n");
        return;
    }

    for (int i = index; i < num_products - 1; i++) {
        products[i] = products[i + 1];
    }

    num_products--;
}

int main() {
    add_product();
    add_product();
    print_products();
    update_product();
    delete_product();
    print_products();

    return 0;
}