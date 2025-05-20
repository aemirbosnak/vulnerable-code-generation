//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    char name[100];
    char address[200];
    char phone[20];
} Customer;

typedef struct {
    Product product;
    int quantity;
    float total_price;
} OrderItem;

typedef struct {
    Customer customer;
    OrderItem *items;
    int num_items;
    float total_price;
} Order;

// Create a new product
Product create_product(char *name, int quantity, float price) {
    Product product;
    strcpy(product.name, name);
    product.quantity = quantity;
    product.price = price;
    return product;
}

// Create a new customer
Customer create_customer(char *name, char *address, char *phone) {
    Customer customer;
    strcpy(customer.name, name);
    strcpy(customer.address, address);
    strcpy(customer.phone, phone);
    return customer;
}

// Create a new order item
OrderItem create_order_item(Product product, int quantity) {
    OrderItem order_item;
    order_item.product = product;
    order_item.quantity = quantity;
    order_item.total_price = product.price * quantity;
    return order_item;
}

// Create a new order
Order create_order(Customer customer, OrderItem *items, int num_items) {
    Order order;
    order.customer = customer;
    order.items = items;
    order.num_items = num_items;
    order.total_price = 0;
    for (int i = 0; i < num_items; i++) {
        order.total_price += order.items[i].total_price;
    }
    return order;
}

// Print the details of a product
void print_product(Product product) {
    printf("Name: %s\n", product.name);
    printf("Quantity: %d\n", product.quantity);
    printf("Price: %.2f\n", product.price);
}

// Print the details of a customer
void print_customer(Customer customer) {
    printf("Name: %s\n", customer.name);
    printf("Address: %s\n", customer.address);
    printf("Phone: %s\n", customer.phone);
}

// Print the details of an order item
void print_order_item(OrderItem order_item) {
    printf("Product: %s\n", order_item.product.name);
    printf("Quantity: %d\n", order_item.quantity);
    printf("Total Price: %.2f\n", order_item.total_price);
}

// Print the details of an order
void print_order(Order order) {
    printf("Customer: %s\n", order.customer.name);
    printf("Order Items:\n");
    for (int i = 0; i < order.num_items; i++) {
        print_order_item(order.items[i]);
    }
    printf("Total Price: %.2f\n", order.total_price);
}

int main() {
    // Create some products
    Product product1 = create_product("Apple", 100, 1.5);
    Product product2 = create_product("Orange", 50, 2.0);
    Product product3 = create_product("Banana", 25, 1.25);

    // Create a customer
    Customer customer = create_customer("John Doe", "123 Main Street", "555-1212");

    // Create some order items
    OrderItem order_item1 = create_order_item(product1, 2);
    OrderItem order_item2 = create_order_item(product2, 3);
    OrderItem order_item3 = create_order_item(product3, 1);

    OrderItem *order_items[] = { &order_item1, &order_item2, &order_item3 };

    // Create an order
    Order order = create_order(customer, order_items, 3);

    // Print the order
    print_order(order);

    return 0;
}