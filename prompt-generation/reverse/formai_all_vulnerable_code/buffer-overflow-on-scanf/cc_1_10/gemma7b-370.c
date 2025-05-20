//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store product information
typedef struct Product {
  char name[50];
  int quantity;
  float price;
} Product;

// Define a function to add a product to the inventory
void addProduct(Product *product) {
  printf("Enter product name: ");
  scanf("%s", product->name);

  printf("Enter product quantity: ");
  scanf("%d", &product->quantity);

  printf("Enter product price: ");
  scanf("%f", &product->price);
}

// Define a function to display the inventory
void displayInventory(Product *products) {
  int i = 0;
  for (i = 0; products[i].name[0] != '\0'; i++) {
    printf("%s - %d - %.2f\n", products[i].name, products[i].quantity, products[i].price);
  }
}

// Define a function to search for a product
Product *searchProduct(Product *products, char *name) {
  int i = 0;
  for (i = 0; products[i].name[0] != '\0'; i++) {
    if (strcmp(products[i].name, name) == 0) {
      return &products[i];
    }
  }
  return NULL;
}

// Main function
int main() {
  Product products[100];
  addProduct(products);
  addProduct(products);
  addProduct(products);
  displayInventory(products);
  Product *product = searchProduct(products, "Product 2");
  if (product) {
    printf("Product name: %s\n", product->name);
    printf("Quantity: %d\n", product->quantity);
    printf("Price: %.2f\n", product->price);
  } else {
    printf("Product not found.\n");
  }

  return 0;
}