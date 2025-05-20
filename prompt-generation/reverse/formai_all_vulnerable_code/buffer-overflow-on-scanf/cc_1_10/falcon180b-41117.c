//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_CUSTOMERS 100
#define MAX_ORDERS 1000

struct item {
    char name[50];
    float price;
};

struct customer {
    char name[50];
    int id;
};

struct order {
    int order_id;
    int customer_id;
    struct item items[10];
    int num_items;
};

void add_item(struct item items[], int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[*num_items].price);
    (*num_items)++;
}

void display_items(struct item items[], int num_items) {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }
}

void add_customer(struct customer customers[], int *num_customers) {
    printf("Enter customer name: ");
    scanf("%s", customers[*num_customers].name);
    customers[*num_customers].id = (*num_customers) + 1;
    (*num_customers)++;
}

void display_customers(struct customer customers[], int num_customers) {
    printf("Customers:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%s - ID: %d\n", customers[i].name, customers[i].id);
    }
}

void add_order(struct order orders[], int *num_orders) {
    printf("Enter order ID: ");
    scanf("%d", &orders[*num_orders].order_id);
    printf("Enter customer ID: ");
    scanf("%d", &orders[*num_orders].customer_id);
    orders[*num_orders].num_items = 0;
}

void add_item_to_order(struct order *order) {
    printf("Enter item name: ");
    scanf("%s", &order->items[order->num_items].name);
    printf("Enter item price: ");
    scanf("%f", &order->items[order->num_items].price);
    order->num_items++;
}

void display_orders(struct order orders[], int num_orders) {
    printf("Orders:\n");
    for (int i = 0; i < num_orders; i++) {
        printf("Order ID: %d, Customer ID: %d\n", orders[i].order_id, orders[i].customer_id);
        printf("Items:\n");
        for (int j = 0; j < orders[i].num_items; j++) {
            printf("%s - $%.2f\n", orders[i].items[j].name, orders[i].items[j].price);
        }
    }
}

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;
    add_item(items, &num_items);
    display_items(items, num_items);

    struct customer customers[MAX_CUSTOMERS];
    int num_customers = 0;
    add_customer(customers, &num_customers);
    display_customers(customers, num_customers);

    struct order orders[MAX_ORDERS];
    int num_orders = 0;
    add_order(orders, &num_orders);
    display_orders(orders, num_orders);

    return 0;
}