//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: statistical
// Cafe Billing System in C

#include <stdio.h>
#include <stdlib.h>

struct order {
    char* name;
    char* item;
    int quantity;
    float price;
};

struct customer {
    char* name;
    int order_count;
    struct order* orders;
};

void print_order(struct order* order) {
    printf("%s: %s x %d = $%.2f\n", order->name, order->item, order->quantity, order->price);
}

void print_customer(struct customer* customer) {
    printf("Customer: %s\n", customer->name);
    for (int i = 0; i < customer->order_count; i++) {
        print_order(&customer->orders[i]);
    }
}

int main() {
    struct customer customers[10];
    int customer_count = 0;

    // Fill in customer information
    customers[customer_count].name = "John";
    customers[customer_count].order_count = 2;
    customers[customer_count].orders = (struct order*) malloc(2 * sizeof(struct order));
    customers[customer_count].orders[0].name = "John";
    customers[customer_count].orders[0].item = "Coffee";
    customers[customer_count].orders[0].quantity = 1;
    customers[customer_count].orders[0].price = 3.00;
    customers[customer_count].orders[1].name = "John";
    customers[customer_count].orders[1].item = "Donut";
    customers[customer_count].orders[1].quantity = 2;
    customers[customer_count].orders[1].price = 1.50;
    customer_count++;

    customers[customer_count].name = "Mary";
    customers[customer_count].order_count = 1;
    customers[customer_count].orders = (struct order*) malloc(1 * sizeof(struct order));
    customers[customer_count].orders[0].name = "Mary";
    customers[customer_count].orders[0].item = "Coffee";
    customers[customer_count].orders[0].quantity = 1;
    customers[customer_count].orders[0].price = 3.00;
    customer_count++;

    // Print customer information
    for (int i = 0; i < customer_count; i++) {
        print_customer(&customers[i]);
    }

    return 0;
}