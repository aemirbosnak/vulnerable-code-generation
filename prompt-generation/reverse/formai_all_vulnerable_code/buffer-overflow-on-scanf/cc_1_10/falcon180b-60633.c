//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 100
#define MAX_ORDERS 100

typedef struct {
    char name[50];
    int price;
    int quantity;
} Product;

typedef struct {
    char name[50];
    char address[100];
    int phone;
} Customer;

typedef struct {
    int order_id;
    int product_id;
    int quantity;
    float price;
} Order;

void addProduct(Product products[], int *num_products) {
    printf("Enter product name: ");
    scanf("%s", products[*num_products].name);
    printf("Enter product price: ");
    scanf("%d", &products[*num_products].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[*num_products].quantity);
    (*num_products)++;
}

void viewProducts(Product products[], int num_products) {
    printf("\nProduct List:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - $%.2f - %d units\n", i+1, products[i].name, products[i].price, products[i].quantity);
    }
}

void addCustomer(Customer customers[], int *num_customers) {
    printf("Enter customer name: ");
    scanf("%s", customers[*num_customers].name);
    printf("Enter customer address: ");
    scanf("%s", customers[*num_customers].address);
    printf("Enter customer phone number: ");
    scanf("%d", &customers[*num_customers].phone);
    (*num_customers)++;
}

void viewCustomers(Customer customers[], int num_customers) {
    printf("\nCustomer List:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%d. %s - %s - %d\n", i+1, customers[i].name, customers[i].address, customers[i].phone);
    }
}

void addOrder(Order orders[], int *num_orders) {
    printf("Enter order ID: ");
    scanf("%d", &orders[*num_orders].order_id);
    printf("Enter product ID: ");
    scanf("%d", &orders[*num_orders].product_id);
    printf("Enter quantity: ");
    scanf("%d", &orders[*num_orders].quantity);
    printf("Enter price: ");
    scanf("%f", &orders[*num_orders].price);
    (*num_orders)++;
}

void viewOrders(Order orders[], int num_orders) {
    printf("\nOrder List:\n");
    for (int i = 0; i < num_orders; i++) {
        printf("%d. Order ID: %d - Product ID: %d - Quantity: %d - Price: $%.2f\n", i+1, orders[i].order_id, orders[i].product_id, orders[i].quantity, orders[i].price);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;
    Order orders[MAX_ORDERS];
    int num_orders = 0;

    addProduct(products, &num_products);
    viewProducts(products, num_products);

    addCustomer(customers, &num_customers);
    viewCustomers(customers, num_customers);

    addOrder(orders, &num_orders);
    viewOrders(orders, num_orders);

    return 0;
}