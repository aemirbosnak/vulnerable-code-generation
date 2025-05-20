//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_PRODUCTS 100
#define MAX_ITEMS_PER_ORDER 10

typedef struct product {
    char name[50];
    float price;
    int quantity;
} product_t;

typedef struct order {
    char customer_name[50];
    char delivery_address[100];
    int num_items;
    product_t* items;
} order_t;

void print_product_list(product_t* products, int num_products) {
    int i;
    printf("Product List:\n");
    for (i = 0; i < num_products; i++) {
        printf("Name: %s, Price: %f, Quantity: %d\n", products[i].name, products[i].price, products[i].quantity);
    }
}

void print_order_list(order_t* orders, int num_orders) {
    int i;
    printf("Order List:\n");
    for (i = 0; i < num_orders; i++) {
        printf("Customer Name: %s, Delivery Address: %s, Num Items: %d\n", orders[i].customer_name, orders[i].delivery_address, orders[i].num_items);
    }
}

void add_product(product_t* products, int num_products, char* name, float price, int quantity) {
    product_t new_product;
    strcpy(new_product.name, name);
    new_product.price = price;
    new_product.quantity = quantity;
    products[num_products] = new_product;
    num_products++;
}

void add_order(order_t* orders, int num_orders, char* customer_name, char* delivery_address, int num_items, product_t* items) {
    order_t new_order;
    strcpy(new_order.customer_name, customer_name);
    strcpy(new_order.delivery_address, delivery_address);
    new_order.num_items = num_items;
    new_order.items = items;
    orders[num_orders] = new_order;
    num_orders++;
}

int main() {
    product_t products[MAX_PRODUCTS];
    order_t orders[MAX_ITEMS_PER_ORDER];

    int num_products = 0;
    int num_orders = 0;

    char product_name[50];
    char order_customer_name[50];
    char order_delivery_address[100];
    int num_items;
    product_t* items;

    while (true) {
        printf("1. Add Product\n");
        printf("2. Add Order\n");
        printf("3. Print Product List\n");
        printf("4. Print Order List\n");
        printf("5. Quit\n");
        printf("Enter your choice (1-5): ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", product_name);
                printf("Enter product price: ");
                scanf("%f", &products[num_products].price);
                printf("Enter product quantity: ");
                scanf("%d", &products[num_products].quantity);
                add_product(products, num_products, product_name, products[num_products].price, products[num_products].quantity);
                num_products++;
                break;
            case 2:
                printf("Enter customer name: ");
                scanf("%s", order_customer_name);
                printf("Enter delivery address: ");
                scanf("%s", order_delivery_address);
                printf("Enter number of items: ");
                scanf("%d", &num_items);
                items = (product_t*) malloc(num_items * sizeof(product_t));
                for (int i = 0; i < num_items; i++) {
                    printf("Enter product name: ");
                    scanf("%s", product_name);
                    printf("Enter product price: ");
                    scanf("%f", &items[i].price);
                    printf("Enter product quantity: ");
                    scanf("%d", &items[i].quantity);
                }
                add_order(orders, num_orders, order_customer_name, order_delivery_address, num_items, items);
                num_orders++;
                break;
            case 3:
                print_product_list(products, num_products);
                break;
            case 4:
                print_order_list(orders, num_orders);
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}