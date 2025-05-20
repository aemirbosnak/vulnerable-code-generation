//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: shocked
/*
 * Unique C Product Inventory System Example Program
 *
 * This program is an example of a simple inventory system for a retail store.
 * It allows the user to add, remove, and view products in the inventory.
 *
 * Written in a shocked style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a product
typedef struct {
  char name[50];
  int quantity;
  float price;
} Product;

// Function to add a product to the inventory
void addProduct(Product *products, int *numProducts) {
  printf("Enter the name of the product: ");
  scanf("%s", &products[*numProducts].name);
  printf("Enter the quantity of the product: ");
  scanf("%d", &products[*numProducts].quantity);
  printf("Enter the price of the product: ");
  scanf("%f", &products[*numProducts].price);
  (*numProducts)++;
}

// Function to remove a product from the inventory
void removeProduct(Product *products, int *numProducts) {
  int index;
  printf("Enter the index of the product to remove: ");
  scanf("%d", &index);
  if (index >= 0 && index < *numProducts) {
    products[index] = products[*numProducts - 1];
    (*numProducts)--;
  } else {
    printf("Invalid index.\n");
  }
}

// Function to view the inventory
void viewInventory(Product *products, int numProducts) {
  for (int i = 0; i < numProducts; i++) {
    printf("%s: %d units at $%.2f each\n", products[i].name, products[i].quantity, products[i].price);
  }
}

int main() {
  Product products[100];
  int numProducts = 0;

  char input;
  do {
    printf("Welcome to the inventory system!\n");
    printf("a) Add a product\n");
    printf("r) Remove a product\n");
    printf("v) View the inventory\n");
    printf("q) Quit\n");
    printf("Please enter your choice: ");
    scanf(" %c", &input);

    switch (input) {
      case 'a':
        addProduct(products, &numProducts);
        break;
      case 'r':
        removeProduct(products, &numProducts);
        break;
      case 'v':
        viewInventory(products, numProducts);
        break;
      case 'q':
        break;
      default:
        printf("Invalid input.\n");
        break;
    }
  } while (input != 'q');

  return 0;
}