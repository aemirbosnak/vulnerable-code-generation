//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: decentralized
// Decentralized Product Inventory System in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// Data structure to store products
typedef struct {
  int id;
  char name[20];
  int quantity;
} Product;

// Function to create a new product
Product create_product(int id, char *name, int quantity) {
  Product product;
  product.id = id;
  strcpy(product.name, name);
  product.quantity = quantity;
  return product;
}

// Function to add a product to inventory
void add_product(Product *product) {
  // Check if product already exists
  if (product->quantity == 0) {
    printf("Product already exists in inventory\n");
    return;
  }
  // Add product to inventory
  printf("Product added to inventory\n");
  product->quantity++;
}

// Function to remove a product from inventory
void remove_product(Product *product) {
  // Check if product exists
  if (product->quantity == 0) {
    printf("Product not found in inventory\n");
    return;
  }
  // Remove product from inventory
  printf("Product removed from inventory\n");
  product->quantity--;
}

// Function to display inventory
void display_inventory(Product *products, int num_products) {
  // Display inventory
  for (int i = 0; i < num_products; i++) {
    printf("Product %d: %s (%d)\n", products[i].id, products[i].name, products[i].quantity);
  }
}

// Main function
int main() {
  // Create products
  Product product1 = create_product(1, "Apple", 10);
  Product product2 = create_product(2, "Banana", 5);
  Product product3 = create_product(3, "Orange", 15);

  // Create inventory
  Product *products = (Product *)malloc(3 * sizeof(Product));
  products[0] = product1;
  products[1] = product2;
  products[2] = product3;
  int num_products = 3;

  // Add products to inventory
  add_product(&product1);
  add_product(&product2);
  add_product(&product3);

  // Remove products from inventory
  remove_product(&product1);
  remove_product(&product2);
  remove_product(&product3);

  // Display inventory
  display_inventory(products, num_products);

  return 0;
}