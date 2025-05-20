//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
  int id;
  char name[50];
  int quantity;
  float price;
} product_t;

product_t products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
  if (num_products == MAX_PRODUCTS) {
    printf("Product inventory is full!\n");
    return;
  }

  product_t *product = &products[num_products];

  printf("Enter product ID: ");
  scanf("%d", &product->id);

  printf("Enter product name: ");
  scanf("%s", product->name);

  printf("Enter product quantity: ");
  scanf("%d", &product->quantity);

  printf("Enter product price: ");
  scanf("%f", &product->price);

  num_products++;
}

void remove_product() {
  int id;

  printf("Enter product ID to remove: ");
  scanf("%d", &id);

  for (int i = 0; i < num_products; i++) {
    if (products[i].id == id) {
      for (int j = i; j < num_products - 1; j++) {
        products[j] = products[j + 1];
      }

      num_products--;

      printf("Product removed successfully!\n");
      return;
    }
  }

  printf("Product not found!\n");
}

void update_product() {
  int id;

  printf("Enter product ID to update: ");
  scanf("%d", &id);

  for (int i = 0; i < num_products; i++) {
    if (products[i].id == id) {
      printf("Enter new product name: ");
      scanf("%s", products[i].name);

      printf("Enter new product quantity: ");
      scanf("%d", &products[i].quantity);

      printf("Enter new product price: ");
      scanf("%f", &products[i].price);

      printf("Product updated successfully!\n");
      return;
    }
  }

  printf("Product not found!\n");
}

void print_products() {
  printf("Product Inventory:\n");

  for (int i = 0; i < num_products; i++) {
    printf("Product ID: %d\n", products[i].id);
    printf("Product Name: %s\n", products[i].name);
    printf("Product Quantity: %d\n", products[i].quantity);
    printf("Product Price: %.2f\n", products[i].price);
    printf("\n");
  }
}

int main() {
  int choice;

  while (1) {
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Update Product\n");
    printf("4. Print Products\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_product();
        break;
      case 2:
        remove_product();
        break;
      case 3:
        update_product();
        break;
      case 4:
        print_products();
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}