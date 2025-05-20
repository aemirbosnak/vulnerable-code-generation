//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: automated
// Inventory system program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 20
#define MAX_DESC_LENGTH 100

// Structure to store product information
typedef struct {
  char name[MAX_NAME_LENGTH];
  char description[MAX_DESC_LENGTH];
  int quantity;
} Product;

// Function to add a new product
void addProduct(Product* products, int* numProducts) {
  printf("Enter product name: ");
  scanf("%s", products[*numProducts].name);
  printf("Enter product description: ");
  scanf("%s", products[*numProducts].description);
  printf("Enter product quantity: ");
  scanf("%d", &products[*numProducts].quantity);
  (*numProducts)++;
}

// Function to search for a product by name
int searchProductByName(Product* products, int numProducts, char* name) {
  for (int i = 0; i < numProducts; i++) {
    if (strcmp(products[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to search for a product by description
int searchProductByDescription(Product* products, int numProducts, char* description) {
  for (int i = 0; i < numProducts; i++) {
    if (strstr(products[i].description, description) != NULL) {
      return i;
    }
  }
  return -1;
}

// Function to print all products
void printAllProducts(Product* products, int numProducts) {
  printf("--------------------------------------------------\n");
  for (int i = 0; i < numProducts; i++) {
    printf("%s: %s\n", products[i].name, products[i].description);
  }
  printf("--------------------------------------------------\n");
}

// Function to print a single product
void printProduct(Product* products, int index) {
  printf("Product: %s\n", products[index].name);
  printf("Description: %s\n", products[index].description);
  printf("Quantity: %d\n", products[index].quantity);
  printf("--------------------------------------------------\n");
}

int main() {
  Product products[MAX_PRODUCTS];
  int numProducts = 0;

  while (1) {
    printf("Enter a command: ");
    char command[100];
    scanf("%s", command);

    if (strcmp(command, "add") == 0) {
      addProduct(products, &numProducts);
    } else if (strcmp(command, "search") == 0) {
      char searchTerm[100];
      scanf("%s", searchTerm);
      int index = searchProductByName(products, numProducts, searchTerm);
      if (index != -1) {
        printProduct(products, index);
      } else {
        printf("Product not found.\n");
      }
    } else if (strcmp(command, "list") == 0) {
      printAllProducts(products, numProducts);
    } else if (strcmp(command, "exit") == 0) {
      break;
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}