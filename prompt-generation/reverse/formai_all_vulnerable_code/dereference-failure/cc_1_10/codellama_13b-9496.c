//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: brave
// Cafe Billing System
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define structs for items and orders
struct item {
  char name[20];
  float price;
};

struct order {
  char name[20];
  int quantity;
  struct item *items;
  float total;
};

// Function to calculate total price of an order
float calculate_total(struct order *order) {
  float total = 0;
  for (int i = 0; i < order->quantity; i++) {
    total += order->items[i].price;
  }
  return total;
}

// Function to print order details
void print_order(struct order *order) {
  printf("Order Details:\n");
  printf("Name: %s\n", order->name);
  printf("Quantity: %d\n", order->quantity);
  printf("Total: $%.2f\n", order->total);
}

// Main function
int main() {
  // Define items
  struct item items[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Cake", 3.00},
    {"Sandwich", 4.00}
  };

  // Define orders
  struct order orders[] = {
    {"Alice", 2, &items[0], 0},
    {"Bob", 3, &items[1], 0},
    {"Charlie", 1, &items[2], 0},
    {"David", 4, &items[3], 0}
  };

  // Calculate total for each order
  for (int i = 0; i < 4; i++) {
    orders[i].total = calculate_total(&orders[i]);
  }

  // Print order details
  for (int i = 0; i < 4; i++) {
    print_order(&orders[i]);
  }

  return 0;
}