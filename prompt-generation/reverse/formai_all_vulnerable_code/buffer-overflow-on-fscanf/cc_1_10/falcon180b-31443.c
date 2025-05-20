//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CATEGORIES 20
#define MAX_CUSTOMERS 50
#define MAX_ORDER_ITEMS 100
#define MAX_ORDERS 50

typedef struct product {
    char name[50];
    int category;
    double price;
    int quantity;
} Product;

typedef struct category {
    char name[50];
    int quantity;
} Category;

typedef struct customer {
    char name[50];
    int id;
} Customer;

typedef struct order_item {
    Product product;
    int quantity;
} OrderItem;

typedef struct order {
    Customer customer;
    OrderItem items[MAX_ORDER_ITEMS];
    int item_count;
} Order;

int main() {
    Product products[MAX_PRODUCTS];
    Category categories[MAX_CATEGORIES];
    Customer customers[MAX_CUSTOMERS];
    Order orders[MAX_ORDERS];

    int num_products = 0, num_categories = 0, num_customers = 0, num_orders = 0;

    FILE *fp = fopen("products.txt", "r");
    if (fp!= NULL) {
        while (fscanf(fp, "%s %d %lf %d", products[num_products].name, &products[num_products].category, &products[num_products].price, &products[num_products].quantity)!= EOF) {
            num_products++;
        }
        fclose(fp);
    }

    fp = fopen("categories.txt", "r");
    if (fp!= NULL) {
        while (fscanf(fp, "%s %d", categories[num_categories].name, &categories[num_categories].quantity)!= EOF) {
            num_categories++;
        }
        fclose(fp);
    }

    fp = fopen("customers.txt", "r");
    if (fp!= NULL) {
        while (fscanf(fp, "%s %d", customers[num_customers].name, &customers[num_customers].id)!= EOF) {
            num_customers++;
        }
        fclose(fp);
    }

    fp = fopen("orders.txt", "r");
    if (fp!= NULL) {
        while (fscanf(fp, "%s %s %d %d", orders[num_orders].customer.name, orders[num_orders].items[0].product.name, &orders[num_orders].items[0].quantity, &orders[num_orders].item_count)!= EOF) {
            num_orders++;
        }
        fclose(fp);
    }

    // TODO: implement inventory management functions

    return 0;
}