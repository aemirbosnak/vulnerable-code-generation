//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: accurate
// Product Inventory System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define product structure
struct Product {
  int id;
  char name[50];
  int price;
  int quantity;
};

// Define inventory structure
struct Inventory {
  struct Product *products;
  int capacity;
  int size;
};

// Function to initialize inventory
void init_inventory(struct Inventory *inventory, int capacity) {
  inventory->products = (struct Product *) malloc(sizeof(struct Product) * capacity);
  inventory->capacity = capacity;
  inventory->size = 0;
}

// Function to add product to inventory
void add_product(struct Inventory *inventory, struct Product *product) {
  if (inventory->size >= inventory->capacity) {
    printf("Inventory is full.\n");
    return;
  }

  inventory->products[inventory->size] = *product;
  inventory->size++;
}

// Function to update product in inventory
void update_product(struct Inventory *inventory, int id, struct Product *product) {
  for (int i = 0; i < inventory->size; i++) {
    if (inventory->products[i].id == id) {
      inventory->products[i] = *product;
      return;
    }
  }

  printf("Product not found.\n");
}

// Function to remove product from inventory
void remove_product(struct Inventory *inventory, int id) {
  for (int i = 0; i < inventory->size; i++) {
    if (inventory->products[i].id == id) {
      inventory->products[i] = inventory->products[inventory->size - 1];
      inventory->size--;
      return;
    }
  }

  printf("Product not found.\n");
}

// Function to display inventory
void display_inventory(struct Inventory *inventory) {
  for (int i = 0; i < inventory->size; i++) {
    printf("Product %d: %s (%d, %d)\n", inventory->products[i].id, inventory->products[i].name, inventory->products[i].price, inventory->products[i].quantity);
  }
}

int main() {
  // Initialize inventory
  struct Inventory inventory;
  init_inventory(&inventory, 10);

  // Add products to inventory
  struct Product p1 = {1, "Apple", 5, 10};
  struct Product p2 = {2, "Orange", 10, 5};
  add_product(&inventory, &p1);
  add_product(&inventory, &p2);

  // Update product in inventory
  struct Product p3 = {2, "Banana", 8, 15};
  update_product(&inventory, 2, &p3);

  // Remove product from inventory
  remove_product(&inventory, 1);

  // Display inventory
  display_inventory(&inventory);

  return 0;
}