//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_WAREHOUSES 10
#define MAX_ORDERS 50
#define MAX_ORDER_ITEMS 20

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    char name[50];
    int capacity;
    int current_quantity;
} Warehouse;

typedef struct {
    int warehouse_id;
    int product_id;
    int quantity;
} OrderItem;

typedef struct {
    int order_id;
    OrderItem items[MAX_ORDER_ITEMS];
    int num_items;
} Order;

int main() {
    Product products[MAX_PRODUCTS];
    Warehouse warehouses[MAX_WAREHOUSES];
    Order orders[MAX_ORDERS];

    int num_products = 0, num_warehouses = 0, num_orders = 0;

    // Add products
    Product apple = {"Apple", 1000, 0.5};
    Product banana = {"Banana", 500, 0.3};
    Product orange = {"Orange", 200, 0.7};
    products[num_products++] = apple;
    products[num_products++] = banana;
    products[num_products++] = orange;

    // Add warehouses
    Warehouse w1 = {"Warehouse 1", 1000, 0};
    Warehouse w2 = {"Warehouse 2", 2000, 0};
    warehouses[num_warehouses++] = w1;
    warehouses[num_warehouses++] = w2;

    // Add orders
    Order o1 = {1, {{1, 100, 0.5}, {2, 200, 0.3}}, 2};
    Order o2 = {2, {{3, 50, 0.7}}, 1};
    orders[num_orders++] = o1;
    orders[num_orders++] = o2;

    // Process orders
    for (int i = 0; i < num_orders; i++) {
        Order current_order = orders[i];
        int total_price = 0;

        for (int j = 0; j < current_order.num_items; j++) {
            int product_id = current_order.items[j].product_id;
            int quantity = current_order.items[j].quantity;

            Product product = products[product_id];
            float price = product.price;

            total_price += quantity * price;
        }

        printf("Order %d processed. Total price: $%.2f\n", current_order.order_id, total_price);
    }

    return 0;
}