//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structures
typedef struct {
  int id;
  char name[50];
  char location[50];
  int quantity;
} Product;

typedef struct {
  int id;
  char name[50];
  char location[50];
  int quantity;
} Inventory;

// Function prototypes
void print_products(Product *products, int num_products);
void print_inventory(Inventory *inventory, int num_inventory);
bool search_product(Product *products, int num_products, char *name);
bool search_inventory(Inventory *inventory, int num_inventory, char *name);

// Main function
int main() {
  // Declare and initialize variables
  Product products[50];
  int num_products = 0;
  Inventory inventory[50];
  int num_inventory = 0;
  char search_name[50];
  bool found = false;

  // Initialize products
  products[0] = (Product){1, "Apple", "Fruit", 10};
  products[1] = (Product){2, "Banana", "Fruit", 20};
  products[2] = (Product){3, "Orange", "Fruit", 30};
  num_products = 3;

  // Initialize inventory
  inventory[0] = (Inventory){1, "Apple", "Fruit", 5};
  inventory[1] = (Inventory){2, "Banana", "Fruit", 10};
  inventory[2] = (Inventory){3, "Orange", "Fruit", 15};
  num_inventory = 3;

  // Print products and inventory
  print_products(products, num_products);
  print_inventory(inventory, num_inventory);

  // Search for a product
  printf("Enter the name of the product to search: ");
  scanf("%s", search_name);
  found = search_product(products, num_products, search_name);
  if (found) {
    printf("Product found: %s\n", search_name);
  } else {
    printf("Product not found: %s\n", search_name);
  }

  // Search for an inventory item
  printf("Enter the name of the inventory item to search: ");
  scanf("%s", search_name);
  found = search_inventory(inventory, num_inventory, search_name);
  if (found) {
    printf("Inventory item found: %s\n", search_name);
  } else {
    printf("Inventory item not found: %s\n", search_name);
  }

  return 0;
}

// Function definitions
void print_products(Product *products, int num_products) {
  printf("Products:\n");
  for (int i = 0; i < num_products; i++) {
    printf("%d. %s (%s) - %d\n", products[i].id, products[i].name, products[i].location, products[i].quantity);
  }
}

void print_inventory(Inventory *inventory, int num_inventory) {
  printf("Inventory:\n");
  for (int i = 0; i < num_inventory; i++) {
    printf("%d. %s (%s) - %d\n", inventory[i].id, inventory[i].name, inventory[i].location, inventory[i].quantity);
  }
}

bool search_product(Product *products, int num_products, char *name) {
  for (int i = 0; i < num_products; i++) {
    if (strcmp(products[i].name, name) == 0) {
      return true;
    }
  }
  return false;
}

bool search_inventory(Inventory *inventory, int num_inventory, char *name) {
  for (int i = 0; i < num_inventory; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      return true;
    }
  }
  return false;
}