//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Define data structures for items and orders
typedef struct {
    char name[100];
    int quantity;
} Item;

typedef struct {
    char name[100];
    int quantity;
    char customer_name[100];
    int order_date;
} Order;

// Function prototypes
void create_items(Item* items, int num_items);
void create_orders(Order* orders, int num_orders);
void print_items(Item* items, int num_items);
void print_orders(Order* orders, int num_orders);

// Main function
int main() {
    // Create items and orders
    Item items[10];
    Order orders[10];

    create_items(items, 10);
    create_orders(orders, 10);

    // Print items and orders
    print_items(items, 10);
    print_orders(orders, 10);

    return 0;
}

// Function to create items
void create_items(Item* items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("Enter item name: ");
        scanf("%s", items[i].name);
        printf("Enter quantity: ");
        scanf("%d", &items[i].quantity);
    }
}

// Function to create orders
void create_orders(Order* orders, int num_orders) {
    for (int i = 0; i < num_orders; i++) {
        printf("Enter order name: ");
        scanf("%s", orders[i].name);
        printf("Enter quantity: ");
        scanf("%d", &orders[i].quantity);
        printf("Enter customer name: ");
        scanf("%s", orders[i].customer_name);
        printf("Enter order date: ");
        scanf("%d", &orders[i].order_date);
    }
}

// Function to print items
void print_items(Item* items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: %s, Quantity: %d\n", i + 1, items[i].name, items[i].quantity);
    }
}

// Function to print orders
void print_orders(Order* orders, int num_orders) {
    for (int i = 0; i < num_orders; i++) {
        printf("Order %d: %s, Quantity: %d, Customer: %s, Order Date: %d\n", i + 1, orders[i].name, orders[i].quantity, orders[i].customer_name, orders[i].order_date);
    }
}