//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_STOCK 1000
#define MAX_ORDERS 100

typedef struct {
    char name[100];
    int quantity;
    float price;
} Product;

typedef struct {
    int id;
    char name[100];
    int quantity;
    float total;
} Order;

void add_product(Product* products, int num_products) {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
}

void view_products(Product* products, int num_products) {
    printf("Product ID | Product Name | Quantity | Price\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d | %s | %d | %.2f\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
}

void add_order(Order* orders, int num_orders) {
    printf("Enter order name: ");
    scanf("%s", orders[num_orders].name);
    num_orders++;
}

void view_orders(Order* orders, int num_orders) {
    printf("Order ID | Order Name | Quantity | Total\n");
    for (int i = 0; i < num_orders; i++) {
        printf("%d | %s | %d | %.2f\n", i+1, orders[i].name, orders[i].quantity, orders[i].total);
    }
}

void stock_management(Product* products, Order* orders, int num_products, int num_orders) {
    char choice;
    do {
        printf("\nStock Management\n");
        printf("1. View Products\n2. Add Product\n3. View Orders\n4. Add Order\n5. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                view_products(products, num_products);
                break;
            case '2':
                add_product(products, num_products);
                break;
            case '3':
                view_orders(orders, num_orders);
                break;
            case '4':
                add_order(orders, num_orders);
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
}

int main() {
    Product products[MAX_PRODUCTS];
    Order orders[MAX_ORDERS];
    int num_products = 0;
    int num_orders = 0;

    stock_management(products, orders, num_products, num_orders);

    return 0;
}