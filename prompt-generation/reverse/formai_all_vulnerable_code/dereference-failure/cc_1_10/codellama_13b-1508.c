//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[20];
  int quantity;
  float price;
} Product;

void print_menu() {
  printf("Welcome to the Medical Store Management System\n");
  printf("Please select an option:\n");
  printf("1. Add a new product\n");
  printf("2. Update an existing product\n");
  printf("3. Delete a product\n");
  printf("4. View all products\n");
  printf("5. Exit\n");
}

void add_product(Product *products, int *num_products) {
  printf("Enter the name of the product: ");
  scanf("%s", products[*num_products].name);
  printf("Enter the quantity of the product: ");
  scanf("%d", &products[*num_products].quantity);
  printf("Enter the price of the product: ");
  scanf("%f", &products[*num_products].price);
  (*num_products)++;
}

void update_product(Product *products, int num_products) {
  int product_index;
  printf("Enter the index of the product to update: ");
  scanf("%d", &product_index);
  printf("Enter the new quantity of the product: ");
  scanf("%d", &products[product_index].quantity);
  printf("Enter the new price of the product: ");
  scanf("%f", &products[product_index].price);
}

void delete_product(Product *products, int *num_products) {
  int product_index;
  printf("Enter the index of the product to delete: ");
  scanf("%d", &product_index);
  for (int i = product_index; i < *num_products - 1; i++) {
    products[i] = products[i + 1];
  }
  (*num_products)--;
}

void view_products(Product *products, int num_products) {
  printf("Here are the current products:\n");
  for (int i = 0; i < num_products; i++) {
    printf("%s: %d, %f\n", products[i].name, products[i].quantity, products[i].price);
  }
}

int main() {
  Product products[100];
  int num_products = 0;
  int menu_option;
  while (1) {
    print_menu();
    scanf("%d", &menu_option);
    switch (menu_option) {
      case 1:
        add_product(products, &num_products);
        break;
      case 2:
        update_product(products, num_products);
        break;
      case 3:
        delete_product(products, &num_products);
        break;
      case 4:
        view_products(products, num_products);
        break;
      case 5:
        return 0;
      default:
        printf("Invalid option\n");
        break;
    }
  }
}