//FormAI DATASET v1.0 Category: Data mining ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

typedef struct {
    int id;
    int quantity;
    float total_price;
} Sale;

void read_products(Product products[], int num_products) {
    for (int i = 0; i < num_products; i++) {
        printf("Enter details of product %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &products[i].id);
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Price: ");
        scanf("%f", &products[i].price);
    }
}

void print_products(Product products[], int num_products) {
    printf("ID\tName\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%.2f\n", products[i].id, products[i].name, products[i].price);
    }
}

void read_sales(Sale sales[], int num_sales) {
    for (int i = 0; i < num_sales; i++) {
        printf("Enter details of sale %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &sales[i].id);
        printf("Quantity: ");
        scanf("%d", &sales[i].quantity);
        sales[i].total_price = 0.0;
    }
}

void calculate_total_sales(Sale sales[], int num_sales, Product products[], int num_products) {
    for (int i = 0; i < num_sales; i++) {
        for (int j = 0; j < num_products; j++) {
            if (sales[i].id == products[j].id) {
                sales[i].total_price = sales[i].quantity * products[j].price;
            }
        }
    }
}

void print_sales(Sale sales[], int num_sales) {
    printf("ID\tQuantity\tTotal Price\n");
    for (int i = 0; i < num_sales; i++) {
        printf("%d\t%d\t\t%.2f\n", sales[i].id, sales[i].quantity, sales[i].total_price);
    }
}

int main() {
    int num_products, num_sales;
    printf("Enter number of products: ");
    scanf("%d", &num_products);

    Product products[num_products];
    read_products(products, num_products);
    printf("\nProducts:\n");
    print_products(products, num_products);

    printf("\nEnter number of sales: ");
    scanf("%d", &num_sales);

    Sale sales[num_sales];
    read_sales(sales, num_sales);
    calculate_total_sales(sales, num_sales, products, num_products);
    printf("\nSales:\n");
    print_sales(sales, num_sales);
    
    return 0;
}