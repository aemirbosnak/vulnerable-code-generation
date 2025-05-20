//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
// Warehouse Management System
// Imaginative Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for warehouse items
typedef struct {
  char name[50];
  int quantity;
  double price;
} Item;

// Define structure for warehouse inventory
typedef struct {
  Item items[100];
  int num_items;
} Inventory;

// Define structure for warehouse order
typedef struct {
  Item items[10];
  int num_items;
  double total_cost;
} Order;

// Function to add item to inventory
void add_item_to_inventory(Inventory* inventory, Item item) {
  inventory->items[inventory->num_items] = item;
  inventory->num_items++;
}

// Function to remove item from inventory
void remove_item_from_inventory(Inventory* inventory, char* item_name) {
  int i;
  for (i = 0; i < inventory->num_items; i++) {
    if (strcmp(inventory->items[i].name, item_name) == 0) {
      inventory->items[i] = inventory->items[inventory->num_items - 1];
      inventory->num_items--;
      break;
    }
  }
}

// Function to process order
void process_order(Inventory* inventory, Order* order) {
  int i;
  for (i = 0; i < order->num_items; i++) {
    remove_item_from_inventory(inventory, order->items[i].name);
  }
  order->total_cost = 0;
  for (i = 0; i < order->num_items; i++) {
    order->total_cost += order->items[i].price;
  }
}

int main() {
  Inventory inventory;
  Order order;
  Item item1 = {"Apples", 10, 5.00};
  Item item2 = {"Bananas", 5, 2.00};
  Item item3 = {"Oranges", 15, 3.00};

  // Add items to inventory
  add_item_to_inventory(&inventory, item1);
  add_item_to_inventory(&inventory, item2);
  add_item_to_inventory(&inventory, item3);

  // Create order
  order.items[0] = item1;
  order.items[1] = item2;
  order.num_items = 2;

  // Process order
  process_order(&inventory, &order);

  // Print order details
  printf("Order: \n");
  for (int i = 0; i < order.num_items; i++) {
    printf("  %s: %d\n", order.items[i].name, order.items[i].quantity);
  }
  printf("Total cost: $%.2f\n", order.total_cost);

  return 0;
}