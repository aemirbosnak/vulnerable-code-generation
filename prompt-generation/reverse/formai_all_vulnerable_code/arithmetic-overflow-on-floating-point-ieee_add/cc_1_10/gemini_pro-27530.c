//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[50];
    float price;
    int quantity;
};

struct order {
    int order_id;
    char customer_name[50];
    char order_date[50];
    struct item items[100];
    int num_items;
};

void add_item(struct order *order, struct item item) {
    order->items[order->num_items] = item;
    order->num_items++;
}

float calculate_total(struct order order) {
    float total = 0;
    for (int i = 0; i < order.num_items; i++) {
        total += order.items[i].price * order.items[i].quantity;
    }
    return total;
}

void print_receipt(struct order order) {
    printf("Order ID: %d\n", order.order_id);
    printf("Customer Name: %s\n", order.customer_name);
    printf("Order Date: %s\n", order.order_date);
    printf("-----------------------------------------------------\n");
    printf("Item Name\tPrice\tQuantity\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < order.num_items; i++) {
        printf("%s\t%.2f\t%d\n", order.items[i].name, order.items[i].price, order.items[i].quantity);
    }
    printf("-----------------------------------------------------\n");
    printf("Total: %.2f\n", calculate_total(order));
}

int main() {
    // Create a new order
    struct order order;
    order.order_id = 1;
    strcpy(order.customer_name, "John Doe");
    strcpy(order.order_date, "2023-03-08");
    order.num_items = 0;

    // Add items to the order
    struct item item1;
    strcpy(item1.name, "Coffee");
    item1.price = 2.50;
    item1.quantity = 2;
    add_item(&order, item1);

    struct item item2;
    strcpy(item2.name, "Tea");
    item2.price = 1.50;
    item2.quantity = 1;
    add_item(&order, item2);

    // Print the receipt
    print_receipt(order);

    return 0;
}