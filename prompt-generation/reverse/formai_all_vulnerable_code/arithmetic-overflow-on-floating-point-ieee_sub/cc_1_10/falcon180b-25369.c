//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50
#define MAX_ORDERS 100

typedef struct {
    char name[50];
    int id;
    float balance;
} Customer;

typedef struct {
    int id;
    char name[50];
    float price;
} Item;

typedef struct {
    int id;
    Customer* customer;
    Item* items[MAX_ITEMS];
    int num_items;
    float total_price;
} Order;

Customer customers[MAX_CUSTOMERS];
Item items[MAX_ITEMS];
Order orders[MAX_ORDERS];

int num_customers = 0;
int num_items = 0;
int num_orders = 0;

void add_customer() {
    num_customers++;
    Customer* new_customer = &customers[num_customers - 1];
    printf("Enter customer name: ");
    scanf("%s", new_customer->name);
    new_customer->id = num_customers;
    new_customer->balance = 0;
}

void add_item() {
    num_items++;
    Item* new_item = &items[num_items - 1];
    printf("Enter item name: ");
    scanf("%s", new_item->name);
    printf("Enter item price: ");
    scanf("%f", &new_item->price);
}

void add_order() {
    num_orders++;
    Order* new_order = &orders[num_orders - 1];
    printf("Enter customer ID: ");
    scanf("%d", &new_order->customer->id);
    new_order->customer = &customers[new_order->customer->id - 1];
    new_order->num_items = 0;
    new_order->total_price = 0;
}

void add_item_to_order(int order_id) {
    Order* order = &orders[order_id - 1];
    if (order->num_items >= MAX_ITEMS) {
        printf("Order is full.\n");
        return;
    }
    printf("Enter item ID: ");
    int item_id;
    scanf("%d", &item_id);
    Item* item = &items[item_id - 1];
    order->items[order->num_items++] = item;
    order->total_price += item->price;
}

void pay_order(int order_id) {
    Order* order = &orders[order_id - 1];
    Customer* customer = order->customer;
    if (customer->balance < order->total_price) {
        printf("Insufficient balance.\n");
        return;
    }
    customer->balance -= order->total_price;
    printf("Order paid successfully.\n");
}

int main() {
    add_customer();
    add_item();
    add_order();
    add_item_to_order(1);
    pay_order(1);
    return 0;
}