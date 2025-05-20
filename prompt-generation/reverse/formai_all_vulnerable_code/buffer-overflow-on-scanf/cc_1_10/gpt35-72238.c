//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
  char name[20];
  int price;
  int quantity;
} Product;

void display_menu(void) {
  printf("===== CYBERPUNK PRODUCT INVENTORY SYSTEM =====\n");
  printf("1. Add a new product\n");
  printf("2. Remove an existing product\n");
  printf("3. Display all products\n");
  printf("4. Update product quantity\n");
  printf("5. Update product price\n");
  printf("6. Exit the program\n\n");
}

void add_product(Product* products, int* product_count) {
  if (*product_count == MAX_PRODUCTS) {
    printf("Maximum product limit reached\n");
    return;
  }

  Product new_product;

  printf("Enter the product name: ");
  scanf("%s", new_product.name);

  printf("Enter the price: ");
  scanf("%d", &new_product.price);

  printf("Enter the quantity: ");
  scanf("%d", &new_product.quantity);

  products[*product_count] = new_product;
  (*product_count)++;
}

void remove_product(Product* products, int* product_count) {
  char product_name[20];

  printf("Enter the name of the product to remove: ");
  scanf("%s", product_name);

  for (int i = 0; i < *product_count; i++) {
    if (strcmp(products[i].name, product_name) == 0) {
      for (int j = i; j < *product_count - 1; j++) {
        products[j] = products[j + 1];
      }
      (*product_count)--;
      return;
    }
  }

  printf("Product not found\n");
}

void display_products(Product* products, int* product_count) {
  printf("Product Name\tPrice\tQuantity\n");
  printf("-----------------------------------\n");
  for (int i = 0; i < *product_count; i++) {
    printf("%s\t\t%d\t%d\n", products[i].name, products[i].price, products[i].quantity);
  }
}

void update_product_quantity(Product* products, int* product_count) {
  char product_name[20];
  int new_quantity;

  printf("Enter the name of the product: ");
  scanf("%s", product_name);

  for (int i = 0; i < *product_count; i++) {
    if (strcmp(products[i].name, product_name) == 0) {
      printf("Enter the new quantity: ");
      scanf("%d", &new_quantity);

      products[i].quantity = new_quantity;
      return;
    }
  }

  printf("Product not found\n");
}

void update_product_price(Product* products, int* product_count) {
  char product_name[20];
  int new_price;

  printf("Enter the name of the product: ");
  scanf("%s", product_name);

  for (int i = 0; i < *product_count; i++) {
    if (strcmp(products[i].name, product_name) == 0) {
      printf("Enter the new price: ");
      scanf("%d", &new_price);

      products[i].price = new_price;
      return;
    }
  }

  printf("Product not found\n");
}

int main() {
  Product products[MAX_PRODUCTS];
  int product_count = 0;
  int choice;

  do {
    display_menu();

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_product(products, &product_count);
        break;
      case 2:
        remove_product(products, &product_count);
        break;
      case 3:
        display_products(products, &product_count);
        break;
      case 4:
        update_product_quantity(products, &product_count);
        break;
      case 5:
        update_product_price(products, &product_count);
        break;
      case 6:
        printf("Exiting the program\n");
        break;
      default:
        printf("Invalid choice\n");
        break;
    }

    printf("\n");

  } while (choice != 6);

  return 0;
}