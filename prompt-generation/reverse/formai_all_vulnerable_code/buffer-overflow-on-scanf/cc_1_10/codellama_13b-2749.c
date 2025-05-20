//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
/*
 * Product Inventory System Example Program
 *
 * This program demonstrates a simple inventory system for a retail store.
 * It allows the user to add, remove, and print a list of products.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
  char name[50];
  int quantity;
  float price;
} Product;

void print_menu();
void add_product(Product* products, int* num_products);
void remove_product(Product* products, int* num_products);
void print_products(Product* products, int num_products);

int main() {
  Product products[MAX_PRODUCTS];
  int num_products = 0;
  char input[100];

  print_menu();

  while (1) {
    printf("Enter an option: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "1") == 0) {
      add_product(products, &num_products);
    } else if (strcmp(input, "2") == 0) {
      remove_product(products, &num_products);
    } else if (strcmp(input, "3") == 0) {
      print_products(products, num_products);
    } else if (strcmp(input, "4") == 0) {
      break;
    } else {
      printf("Invalid option\n");
    }
  }

  return 0;
}

void print_menu() {
  printf("---------------------------------\n");
  printf("Product Inventory System\n");
  printf("---------------------------------\n");
  printf("1. Add a product\n");
  printf("2. Remove a product\n");
  printf("3. Print products\n");
  printf("4. Quit\n");
  printf("---------------------------------\n");
}

void add_product(Product* products, int* num_products) {
  if (*num_products >= MAX_PRODUCTS) {
    printf("Inventory is full\n");
    return;
  }

  printf("Enter product name: ");
  fgets(products[*num_products].name, sizeof(products[*num_products].name), stdin);
  products[*num_products].name[strcspn(products[*num_products].name, "\n")] = '\0';

  printf("Enter product quantity: ");
  scanf("%d", &products[*num_products].quantity);

  printf("Enter product price: ");
  scanf("%f", &products[*num_products].price);

  *num_products += 1;
}

void remove_product(Product* products, int* num_products) {
  if (*num_products <= 0) {
    printf("Inventory is empty\n");
    return;
  }

  printf("Enter product name: ");
  fgets(products[*num_products - 1].name, sizeof(products[*num_products - 1].name), stdin);
  products[*num_products - 1].name[strcspn(products[*num_products - 1].name, "\n")] = '\0';

  for (int i = *num_products - 1; i < *num_products - 1; i++) {
    products[i] = products[i + 1];
  }

  *num_products -= 1;
}

void print_products(Product* products, int num_products) {
  for (int i = 0; i < num_products; i++) {
    printf("Product %d: %s (%d, $%.2f)\n", i + 1, products[i].name, products[i].quantity, products[i].price);
  }
}