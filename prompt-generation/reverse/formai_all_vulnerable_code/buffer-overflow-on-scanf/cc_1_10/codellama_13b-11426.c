//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for product information
struct Product {
  int id;
  char name[50];
  double price;
  int quantity;
};

// Define function to display product information
void display_product(struct Product product) {
  printf("Product ID: %d\n", product.id);
  printf("Product Name: %s\n", product.name);
  printf("Product Price: %.2f\n", product.price);
  printf("Product Quantity: %d\n", product.quantity);
}

// Define function to add a new product
void add_product(struct Product *product) {
  printf("Enter product ID: ");
  scanf("%d", &product->id);
  printf("Enter product name: ");
  scanf("%s", product->name);
  printf("Enter product price: ");
  scanf("%lf", &product->price);
  printf("Enter product quantity: ");
  scanf("%d", &product->quantity);
}

// Define function to update product information
void update_product(struct Product *product) {
  printf("Enter product ID: ");
  scanf("%d", &product->id);
  printf("Enter product name: ");
  scanf("%s", product->name);
  printf("Enter product price: ");
  scanf("%lf", &product->price);
  printf("Enter product quantity: ");
  scanf("%d", &product->quantity);
}

// Define function to delete a product
void delete_product(struct Product *product) {
  printf("Enter product ID: ");
  scanf("%d", &product->id);
  printf("Product deleted successfully.\n");
}

// Define function to search for a product
void search_product(struct Product *product) {
  printf("Enter product ID: ");
  scanf("%d", &product->id);
  printf("Product found successfully.\n");
}

int main() {
  // Declare a structure for product information
  struct Product product;

  // Initialize product ID, name, price, and quantity
  product.id = 1;
  strcpy(product.name, "Product 1");
  product.price = 10.99;
  product.quantity = 10;

  // Display product information
  display_product(product);

  // Add a new product
  add_product(&product);

  // Update product information
  update_product(&product);

  // Delete a product
  delete_product(&product);

  // Search for a product
  search_product(&product);

  return 0;
}