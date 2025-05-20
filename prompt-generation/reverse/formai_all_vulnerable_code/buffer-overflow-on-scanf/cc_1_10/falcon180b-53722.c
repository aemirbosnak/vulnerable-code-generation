//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_CUSTOMERS 1000
#define MAX_ORDERS 1000

typedef struct {
    int id;
    char name[100];
    char address[200];
} customer;

typedef struct {
    int id;
    char name[100];
    float price;
    int quantity;
} product;

typedef struct {
    int id;
    int customer_id;
    int product_id;
    int quantity;
    float total_price;
} order;

customer customers[MAX_CUSTOMERS];
product products[MAX_PRODUCTS];
order orders[MAX_ORDERS];

int num_customers = 0;
int num_products = 0;
int num_orders = 0;

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter customer address: ");
    scanf("%s", customers[num_customers].address);
    customers[num_customers].id = num_customers + 1;
    num_customers++;
}

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    products[num_products].id = num_products + 1;
    num_products++;
}

void add_order() {
    printf("Enter order customer ID: ");
    scanf("%d", &orders[num_orders].customer_id);
    printf("Enter order product ID: ");
    scanf("%d", &orders[num_orders].product_id);
    printf("Enter order quantity: ");
    scanf("%d", &orders[num_orders].quantity);
    orders[num_orders].total_price = orders[num_orders].quantity * products[orders[num_orders].product_id - 1].price;
    orders[num_orders].id = num_orders + 1;
    num_orders++;
}

void view_customers() {
    printf("Customer ID\tName\tAddress\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%d\t%s\t%s\n", customers[i].id, customers[i].name, customers[i].address);
    }
}

void view_products() {
    printf("Product ID\tName\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%.2f\n", products[i].id, products[i].name, products[i].price);
    }
}

void view_orders() {
    printf("Order ID\tCustomer ID\tProduct ID\tQuantity\tTotal Price\n");
    for (int i = 0; i < num_orders; i++) {
        printf("%d\t%d\t%d\t%d\t%.2f\n", orders[i].id, orders[i].customer_id, orders[i].product_id, orders[i].quantity, orders[i].total_price);
    }
}

int main() {
    add_customer();
    add_customer();
    add_product();
    add_product();
    add_order();
    add_order();

    view_customers();
    view_products();
    view_orders();

    return 0;
}