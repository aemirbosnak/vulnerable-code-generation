//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 1000
#define MAX_CUSTOMERS 100
#define MAX_ORDERS 1000

// Structures

typedef struct {
    char name[50];
    char description[100];
    int quantity;
    double price;
} Item;

typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
} Customer;

typedef struct {
    int id;
    int item_id;
    int quantity;
    double total_cost;
    double delivery_cost;
    int delivery_time;
} Order;

// Functions

void print_item(Item item) {
    printf("Name: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Quantity: %d\n", item.quantity);
    printf("Price: %.2f\n", item.price);
}

void print_customer(Customer customer) {
    printf("Name: %s\n", customer.name);
    printf("Address: %s\n", customer.address);
    printf("Phone: %s\n", customer.phone);
    printf("Email: %s\n", customer.email);
}

void print_order(Order order) {
    printf("ID: %d\n", order.id);
    printf("Item ID: %d\n", order.item_id);
    printf("Quantity: %d\n", order.quantity);
    printf("Total Cost: %.2f\n", order.total_cost);
    printf("Delivery Cost: %.2f\n", order.delivery_cost);
    printf("Delivery Time: %d\n", order.delivery_time);
}

// Main Function

int main() {
    // Declare variables
    int n_items, n_customers, n_orders;
    Item items[MAX_ITEMS];
    Customer customers[MAX_CUSTOMERS];
    Order orders[MAX_ORDERS];
    int i, j, k;

    // Get input
    printf("Enter number of items: ");
    scanf("%d", &n_items);
    for (i = 0; i < n_items; i++) {
        printf("Enter item %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", items[i].name);
        printf("Description: ");
        scanf("%s", items[i].description);
        printf("Quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Price: ");
        scanf("%lf", &items[i].price);
    }

    printf("Enter number of customers: ");
    scanf("%d", &n_customers);
    for (i = 0; i < n_customers; i++) {
        printf("Enter customer %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", customers[i].name);
        printf("Address: ");
        scanf("%s", customers[i].address);
        printf("Phone: ");
        scanf("%s", customers[i].phone);
        printf("Email: ");
        scanf("%s", customers[i].email);
    }

    printf("Enter number of orders: ");
    scanf("%d", &n_orders);
    for (i = 0; i < n_orders; i++) {
        printf("Enter order %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &orders[i].id);
        printf("Item ID: ");
        scanf("%d", &orders[i].item_id);
        printf("Quantity: ");
        scanf("%d", &orders[i].quantity);
        printf("Total Cost: ");
        scanf("%lf", &orders[i].total_cost);
        printf("Delivery Cost: ");
        scanf("%lf", &orders[i].delivery_cost);
        printf("Delivery Time: ");
        scanf("%d", &orders[i].delivery_time);
    }

    // Display items
    printf("\nItems:\n");
    for (i = 0; i < n_items; i++) {
        print_item(items[i]);
    }

    // Display customers
    printf("\nCustomers:\n");
    for (i = 0; i < n_customers; i++) {
        print_customer(customers[i]);
    }

    // Display orders
    printf("\nOrders:\n");
    for (i = 0; i < n_orders; i++) {
        print_order(orders[i]);
    }

    return 0;
}