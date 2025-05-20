//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the maximum size and number of products in the warehouse
#define MAX_NAME_SIZE 50
#define MAX_PROD_SIZE 100

// Define the product struct
typedef struct {
  char name[MAX_NAME_SIZE];
  int quantity;
  float price;
} Product;

// Define the functions for adding and removing products from the warehouse
void addProduct(Product *products, int *numProducts) {
  // Check if we have room for another product
  if (*numProducts >= MAX_PROD_SIZE) {
    printf("Sorry, the warehouse is full!\n");
    return;
  }

  // Get the name of the product
  char name[MAX_NAME_SIZE];
  printf("Enter name of product: ");
  scanf("%s", name);

  // Check if the product already exists
  for (int i = 0; i < *numProducts; i++) {
    if (strcmp(products[i].name, name) == 0) {
      printf("Sorry, that product already exists in the warehouse!\n");
      return;
    }
  }

  // Get the quantity and price of the product
  int quantity;
  float price;
  printf("Enter quantity of product: ");
  scanf("%d", &quantity);
  printf("Enter price of product: ");
  scanf("%f", &price);

  // Add the product to the warehouse
  strcpy(products[*numProducts].name, name);
  products[*numProducts].quantity = quantity;
  products[*numProducts].price = price;

  // Increment the number of products in the warehouse
  (*numProducts)++;

  printf("Product successfully added to warehouse!\n");
}

void removeProduct(Product *products, int *numProducts) {
  // Get the name of the product to remove
  char name[MAX_NAME_SIZE];
  printf("Enter name of product to remove: ");
  scanf("%s", name);

  // Find the product and remove it
  for (int i = 0; i < *numProducts; i++) {
    if (strcmp(products[i].name, name) == 0) {
      printf("Product successfully removed from warehouse!\n");

      // Shift the remaining products down one index in the array
      for (int j = i + 1; j < *numProducts; j++) {
        products[j - 1] = products[j];
      }

      // Decrement the number of products in the warehouse
      (*numProducts)--;
      return;
    }
  }

  printf("Sorry, that product does not exist in the warehouse!\n");
}

int main() {
  // Initialize an empty array of products
  Product products[MAX_PROD_SIZE];
  int numProducts = 0;

  // Display the menu and process user input
  int choice;
  do {
    printf("\nWarehouse Management System\n");
    printf("----------------------------\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addProduct(products, &numProducts);
        break;
      case 2:
        removeProduct(products, &numProducts);
        break;
      case 3:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 3);

  return 0;
}