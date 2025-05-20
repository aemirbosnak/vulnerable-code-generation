//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    char name[50];
    int quantity;
    float price;
    int customer_id;
} Sale;

Product products[10];
int num_products = 0;

Sale sales[10];
int num_sales = 0;

void add_product(char name[], int quantity, float price) {
    Product new_product;
    strcpy(new_product.name, name);
    new_product.quantity = quantity;
    new_product.price = price;
    products[num_products++] = new_product;
}

void delete_product(char name[]) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            num_products--;
            for (int j = i; j < num_products - 1; j++) {
                products[j] = products[j + 1];
            }
            break;
        }
    }
}

Product* find_product(char name[]) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return &products[i];
        }
    }
    return NULL;
}

void calculate_sales(char name[]) {
    int i;
    int total_sales = 0;
    for (i = 0; i < num_sales; i++) {
        if (strcmp(sales[i].name, name) == 0) {
            total_sales += sales[i].quantity * sales[i].price;
        }
    }
    printf("Total sales of %s: $%.2f\n", name, total_sales);
}

int main() {
    char name[50];
    int quantity, price;
    float total_sales;

    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);
    printf("Enter product price: ");
    scanf("%f", &price);
    add_product(name, quantity, price);

    printf("Enter product name: ");
    scanf("%s", name);
    delete_product(name);

    printf("Enter product name: ");
    scanf("%s", name);
    Product* product = find_product(name);
    if (product == NULL) {
        printf("Product not found.\n");
    } else {
        printf("Product found.\n");
        printf("Name: %s\n", product->name);
        printf("Quantity: %d\n", product->quantity);
        printf("Price: $%.2f\n", product->price);
        calculate_sales(name);
    }

    return 0;
}