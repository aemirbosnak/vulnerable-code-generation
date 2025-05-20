//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct {
  int id;
  char name[50];
  int quantity;
  float price;
} Product;

// Database of products
Product products[] = {
  {1, "Apple", 10, 1.0},
  {2, "Orange", 5, 1.5},
  {3, "Banana", 15, 0.8},
  {4, "Strawberry", 7, 1.2},
  {5, "Blueberry", 12, 1.4}
};

// Number of products in the database
int num_products = sizeof(products) / sizeof(Product);

// Function to get product by id
Product* get_product(int id) {
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == id) {
      return &products[i];
    }
  }
  return NULL;
}

// Function to add product to the database
void add_product(Product product) {
  products[num_products] = product;
  num_products++;
}

// Function to delete product from the database
void delete_product(int id) {
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == id) {
      for (int j = i; j < num_products - 1; j++) {
        products[j] = products[j + 1];
      }
      num_products--;
      break;
    }
  }
}

// Function to update product in the database
void update_product(Product product) {
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == product.id) {
      products[i] = product;
      break;
    }
  }
}

// Function to print all products in the database
void print_products() {
  printf("ID\tName\tQuantity\tPrice\n");
  for (int i = 0; i < num_products; i++) {
    printf("%d\t%s\t%d\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
  }
}

// Main function
int main() {
  // Add a new product
  Product new_product = {6, "Grape", 8, 1.3};
  add_product(new_product);

  // Delete a product
  delete_product(3);

  // Update a product
  Product updated_product = {2, "Orange", 7, 1.6};
  update_product(updated_product);

  // Print all products
  print_products();

  return 0;
}