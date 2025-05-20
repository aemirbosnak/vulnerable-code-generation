//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: recursive
// Product Inventory System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product Struct
typedef struct {
  char name[50];
  int quantity;
} Product;

// Inventory Struct
typedef struct {
  Product* products;
  int num_products;
} Inventory;

// Function to print the inventory
void print_inventory(Inventory* inventory) {
  for (int i = 0; i < inventory->num_products; i++) {
    printf("%s: %d\n", inventory->products[i].name, inventory->products[i].quantity);
  }
}

// Function to add a product to the inventory
void add_product(Inventory* inventory, Product* product) {
  inventory->num_products++;
  inventory->products = realloc(inventory->products, inventory->num_products * sizeof(Product));
  memcpy(&inventory->products[inventory->num_products - 1], product, sizeof(Product));
}

// Function to remove a product from the inventory
void remove_product(Inventory* inventory, char* name) {
  for (int i = 0; i < inventory->num_products; i++) {
    if (strcmp(inventory->products[i].name, name) == 0) {
      inventory->num_products--;
      memmove(&inventory->products[i], &inventory->products[i + 1], (inventory->num_products - i) * sizeof(Product));
      break;
    }
  }
}

// Function to update the quantity of a product in the inventory
void update_quantity(Inventory* inventory, char* name, int quantity) {
  for (int i = 0; i < inventory->num_products; i++) {
    if (strcmp(inventory->products[i].name, name) == 0) {
      inventory->products[i].quantity = quantity;
      break;
    }
  }
}

// Main function
int main() {
  // Initialize the inventory
  Inventory* inventory = malloc(sizeof(Inventory));
  inventory->num_products = 0;
  inventory->products = NULL;

  // Add some products to the inventory
  Product p1 = {"Apple", 5};
  Product p2 = {"Orange", 10};
  Product p3 = {"Banana", 15};
  add_product(inventory, &p1);
  add_product(inventory, &p2);
  add_product(inventory, &p3);

  // Print the inventory
  print_inventory(inventory);

  // Remove a product from the inventory
  remove_product(inventory, "Orange");

  // Update the quantity of a product in the inventory
  update_quantity(inventory, "Banana", 20);

  // Print the updated inventory
  print_inventory(inventory);

  return 0;
}