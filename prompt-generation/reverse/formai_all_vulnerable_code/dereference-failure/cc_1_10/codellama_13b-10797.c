//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
/*
 * C Warehouse Management System
 *
 * This program simulates the management of a warehouse with a simple
 * inventory system and a shipping system.
 *
 * Written by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_SHIPMENTS 100
#define MAX_ORDERS 100

// Structures
typedef struct {
  char name[50];
  int quantity;
  int price;
} Product;

typedef struct {
  char product[50];
  int quantity;
  int price;
} Order;

typedef struct {
  char order_id[50];
  char product[50];
  int quantity;
  int price;
} Shipment;

// Functions
void add_product(Product* products, int* num_products, char* name, int quantity, int price) {
  Product* new_product = malloc(sizeof(Product));
  strcpy(new_product->name, name);
  new_product->quantity = quantity;
  new_product->price = price;
  products[*num_products] = *new_product;
  (*num_products)++;
}

void add_order(Order* orders, int* num_orders, char* product, int quantity, int price) {
  Order* new_order = malloc(sizeof(Order));
  strcpy(new_order->product, product);
  new_order->quantity = quantity;
  new_order->price = price;
  orders[*num_orders] = *new_order;
  (*num_orders)++;
}

void add_shipment(Shipment* shipments, int* num_shipments, char* order_id, char* product, int quantity, int price) {
  Shipment* new_shipment = malloc(sizeof(Shipment));
  strcpy(new_shipment->order_id, order_id);
  strcpy(new_shipment->product, product);
  new_shipment->quantity = quantity;
  new_shipment->price = price;
  shipments[*num_shipments] = *new_shipment;
  (*num_shipments)++;
}

void print_products(Product* products, int num_products) {
  for (int i = 0; i < num_products; i++) {
    printf("%s: %d units @ $%d each\n", products[i].name, products[i].quantity, products[i].price);
  }
}

void print_orders(Order* orders, int num_orders) {
  for (int i = 0; i < num_orders; i++) {
    printf("%s: %d units @ $%d each\n", orders[i].product, orders[i].quantity, orders[i].price);
  }
}

void print_shipments(Shipment* shipments, int num_shipments) {
  for (int i = 0; i < num_shipments; i++) {
    printf("%s: %s - %d units @ $%d each\n", shipments[i].order_id, shipments[i].product, shipments[i].quantity, shipments[i].price);
  }
}

int main() {
  Product products[MAX_PRODUCTS];
  Order orders[MAX_ORDERS];
  Shipment shipments[MAX_SHIPMENTS];

  int num_products = 0;
  int num_orders = 0;
  int num_shipments = 0;

  // Add products
  add_product(products, &num_products, "Widget", 10, 100);
  add_product(products, &num_products, "Gadget", 20, 200);
  add_product(products, &num_products, "Thingamajig", 30, 300);

  // Add orders
  add_order(orders, &num_orders, "Widget", 5, 500);
  add_order(orders, &num_orders, "Gadget", 10, 1000);
  add_order(orders, &num_orders, "Thingamajig", 15, 1500);

  // Add shipments
  add_shipment(shipments, &num_shipments, "Order 1", "Widget", 5, 500);
  add_shipment(shipments, &num_shipments, "Order 2", "Gadget", 10, 1000);
  add_shipment(shipments, &num_shipments, "Order 3", "Thingamajig", 15, 1500);

  // Print inventory
  printf("Inventory:\n");
  print_products(products, num_products);

  // Print orders
  printf("\nOrders:\n");
  print_orders(orders, num_orders);

  // Print shipments
  printf("\nShipments:\n");
  print_shipments(shipments, num_shipments);

  return 0;
}