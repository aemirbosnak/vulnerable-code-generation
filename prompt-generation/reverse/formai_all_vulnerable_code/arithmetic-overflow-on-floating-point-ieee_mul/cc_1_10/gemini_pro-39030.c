//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store item details
typedef struct Item {
  char name[50];
  int quantity;
  float price;
} Item;

// Structure to store warehouse details
typedef struct Warehouse {
  Item items[100];
  int num_items;
} Warehouse;

// Function to add an item to the warehouse
void add_item(Warehouse *warehouse, Item item) {
  warehouse->items[warehouse->num_items] = item;
  warehouse->num_items++;
}

// Function to remove an item from the warehouse
void remove_item(Warehouse *warehouse, char *name) {
  int i;
  for (i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
      warehouse->num_items--;
      return;
    }
  }
}

// Function to get the total value of the warehouse
float get_total_value(Warehouse *warehouse) {
  int i;
  float total_value = 0;
  for (i = 0; i < warehouse->num_items; i++) {
    total_value += warehouse->items[i].quantity * warehouse->items[i].price;
  }
  return total_value;
}

// Function to print the details of the warehouse
void print_warehouse(Warehouse *warehouse) {
  int i;
  printf("Warehouse Details:\n");
  printf("-----------------\n");
  printf("Number of Items: %d\n", warehouse->num_items);
  printf("Total Value: %.2f\n", get_total_value(warehouse));
  printf("\n");
  printf("Item List:\n");
  printf("----------\n");
  for (i = 0; i < warehouse->num_items; i++) {
    printf("%s (%d) - %.2f\n", warehouse->items[i].name, warehouse->items[i].quantity,
           warehouse->items[i].price);
  }
}

int main() {
  // Create a warehouse
  Warehouse warehouse;
  warehouse.num_items = 0;

  // Add some items to the warehouse
  Item item1 = {"Apples", 10, 1.50};
  add_item(&warehouse, item1);
  Item item2 = {"Oranges", 5, 2.00};
  add_item(&warehouse, item2);
  Item item3 = {"Bananas", 15, 1.25};
  add_item(&warehouse, item3);

  // Print the details of the warehouse
  print_warehouse(&warehouse);

  // Remove an item from the warehouse
  remove_item(&warehouse, "Oranges");

  // Print the details of the warehouse again
  print_warehouse(&warehouse);

  return 0;
}