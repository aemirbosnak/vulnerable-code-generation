//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products and the maximum length of a product name
#define MAX_PRODUCTS 100
#define MAX_PRODUCT_NAME_LENGTH 50

// Define the structure of a product
typedef struct {
  char name[MAX_PRODUCT_NAME_LENGTH];
  int quantity;
  float price;
} product;

// Get the input from the user
void get_input(product *products, int *num_products) {
  printf("Enter the number of products: ");
  scanf("%d", num_products);

  for (int i = 0; i < *num_products; i++) {
    printf("Enter the name of product %d: ", i + 1);
    scanf("%s", products[i].name);

    printf("Enter the quantity of product %d: ", i + 1);
    scanf("%d", &products[i].quantity);

    printf("Enter the price of product %d: ", i + 1);
    scanf("%f", &products[i].price);
  }
}

// Print the output to the console
void print_output(product *products, int num_products) {
  printf("\nWarehouse Management System\n");
  printf("-----------------------------\n");

  for (int i = 0; i < num_products; i++) {
    printf("Product %d:\n", i + 1);
    printf("  Name: %s\n", products[i].name);
    printf("  Quantity: %d\n", products[i].quantity);
    printf("  Price: %.2f\n", products[i].price);
  }
}

// Main function
int main() {
  // Declare an array of products and a variable to store the number of products
  product products[MAX_PRODUCTS];
  int num_products;

  // Get the input from the user
  get_input(products, &num_products);

  // Print the output to the console
  print_output(products, num_products);

  return 0;
}