//FormAI DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
  char name[50];
  int quantity;
  float price;
};

void addProduct(struct product products[], int *product_count) {
  struct product new_product;

  printf("Enter the product name: ");
  scanf("%s", new_product.name);

  printf("Enter the quantity: ");
  scanf("%d", &new_product.quantity);

  printf("Enter the price per item: ");
  scanf("%f", &new_product.price);

  products[*product_count] = new_product;
  *product_count += 1;
}

void displayProduct(struct product p) {
  printf("%-50s %10d %10.2f\n", p.name, p.quantity, p.price);
}

void displayInventory(struct product products[], int product_count) {
  printf("%-50s %10s %10s\n", "Product Name", "Quantity", "Price");

  for (int i = 0; i < product_count; i++) {
    displayProduct(products[i]);
  }
}

void searchProduct(struct product products[], int product_count) {
  char search_term[50];

  printf("Enter the name of product to search for: ");
  scanf("%s", search_term);

  for (int i = 0; i < product_count; i++) {
    if (strcmp(products[i].name, search_term) == 0) {
      printf("Product found: \n");
      displayProduct(products[i]);
      return;
    }
  }

  printf("Product not found.\n");
}

void updateProduct(struct product products[], int product_count) {
  char search_term[50];

  printf("Enter the name of product to update: ");
  scanf("%s", search_term);

  for (int i = 0; i < product_count; i++) {
    if (strcmp(products[i].name, search_term) == 0) {
      printf("Enter the new quantity: ");
      scanf("%d", &products[i].quantity);

      printf("Enter the new price per item: ");
      scanf("%f", &products[i].price);

      printf("Product updated: \n");
      displayProduct(products[i]);
      return;
    }
  }

  printf("Product not found.\n");
}

int main() {
  int option, product_count = 0;
  struct product products[100];

  do {
    printf("\n");
    printf("1. Add a product to the inventory\n");
    printf("2. Search for a product\n");
    printf("3. Update a product\n");
    printf("4. Display the inventory\n");
    printf("5. Exit\n");

    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        addProduct(products, &product_count);
        break;

      case 2:
        searchProduct(products, product_count);
        break;

      case 3:
        updateProduct(products, product_count);
        break;

      case 4:
        displayInventory(products, product_count);
        break;

      case 5:
        printf("Goodbye!\n");
        exit(0);

      default:
        printf("Invalid option.\n");
    }
  } while (option != 5);

  return 0;
}