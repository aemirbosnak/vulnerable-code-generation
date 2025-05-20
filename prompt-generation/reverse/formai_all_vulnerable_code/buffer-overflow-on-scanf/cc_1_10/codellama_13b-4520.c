//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: Cryptic
// Product Inventory System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_QTY_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
  char name[MAX_NAME_LEN];
  int quantity;
  double price;
} Product;

void print_menu(void) {
  printf("Welcome to the Product Inventory System\n");
  printf("Please select an option:\n");
  printf("1. Add product\n");
  printf("2. Update product quantity\n");
  printf("3. Update product price\n");
  printf("4. View inventory\n");
  printf("5. Exit\n");
}

void add_product(Product *products, int *num_products) {
  printf("Enter product name: ");
  fgets(products[*num_products].name, MAX_NAME_LEN, stdin);
  printf("Enter quantity: ");
  scanf("%d", &products[*num_products].quantity);
  printf("Enter price: ");
  scanf("%lf", &products[*num_products].price);
  (*num_products)++;
}

void update_product_quantity(Product *products, int *num_products) {
  int index;
  printf("Enter product index: ");
  scanf("%d", &index);
  if (index >= 0 && index < *num_products) {
    printf("Enter new quantity: ");
    scanf("%d", &products[index].quantity);
  } else {
    printf("Invalid index\n");
  }
}

void update_product_price(Product *products, int *num_products) {
  int index;
  printf("Enter product index: ");
  scanf("%d", &index);
  if (index >= 0 && index < *num_products) {
    printf("Enter new price: ");
    scanf("%lf", &products[index].price);
  } else {
    printf("Invalid index\n");
  }
}

void view_inventory(Product *products, int num_products) {
  for (int i = 0; i < num_products; i++) {
    printf("Product %d: %s (%d units, %.2lf per unit)\n", i + 1, products[i].name, products[i].quantity, products[i].price);
  }
}

int main(void) {
  Product products[MAX_PRODUCTS];
  int num_products = 0;
  int option = 0;

  while (option != 5) {
    print_menu();
    scanf("%d", &option);

    switch (option) {
      case 1:
        add_product(products, &num_products);
        break;
      case 2:
        update_product_quantity(products, &num_products);
        break;
      case 3:
        update_product_price(products, &num_products);
        break;
      case 4:
        view_inventory(products, num_products);
        break;
      case 5:
        break;
      default:
        printf("Invalid option\n");
        break;
    }
  }

  return 0;
}