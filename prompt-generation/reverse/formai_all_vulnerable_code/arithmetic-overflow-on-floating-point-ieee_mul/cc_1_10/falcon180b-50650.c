//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 100
#define MAX_SALES 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    int id;
    char name[50];
    char address[100];
} Customer;

typedef struct {
    int id;
    int product_id;
    int customer_id;
    int quantity;
    float total_price;
} Sale;

Product products[MAX_PRODUCTS];
Customer customers[MAX_CUSTOMERS];
Sale sales[MAX_SALES];

int num_products = 0;
int num_customers = 0;
int num_sales = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
}

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter customer address: ");
    scanf("%s", customers[num_customers].address);
    num_customers++;
}

void make_sale() {
    printf("Enter sale product ID: ");
    int product_id;
    scanf("%d", &product_id);
    printf("Enter sale customer ID: ");
    int customer_id;
    scanf("%d", &customer_id);
    printf("Enter sale quantity: ");
    int quantity;
    scanf("%d", &quantity);

    Product *product = &products[product_id];
    Customer *customer = &customers[customer_id];

    sales[num_sales].id = num_sales + 1;
    sales[num_sales].product_id = product_id;
    sales[num_sales].customer_id = customer_id;
    sales[num_sales].quantity = quantity;
    sales[num_sales].total_price = quantity * product->price;

    num_sales++;
}

void view_sales() {
    printf("Sale ID\tProduct ID\tCustomer ID\tQuantity\tTotal Price\n");
    for (int i = 0; i < num_sales; i++) {
        printf("%d\t%d\t%d\t%d\t%.2f\n", sales[i].id, sales[i].product_id, sales[i].customer_id, sales[i].quantity, sales[i].total_price);
    }
}

int main() {
    add_product();
    add_customer();
    make_sale();
    view_sales();

    return 0;
}