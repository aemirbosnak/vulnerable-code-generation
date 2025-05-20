//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
  char name[MAX_NAME_LENGTH];
  char description[MAX_DESCRIPTION_LENGTH];
  int price;
  int quantity;
} Product;

void print_menu() {
  printf("Inventory Management System\n");
  printf("1. Add product\n");
  printf("2. Update product\n");
  printf("3. Remove product\n");
  printf("4. Print inventory\n");
  printf("5. Exit\n");
  printf("Enter your choice: ");
}

int add_product(Product* products, int* num_products) {
  printf("Enter product name: ");
  scanf("%s", products[*num_products].name);
  printf("Enter product description: ");
  scanf("%s", products[*num_products].description);
  printf("Enter product price: ");
  scanf("%d", &products[*num_products].price);
  printf("Enter product quantity: ");
  scanf("%d", &products[*num_products].quantity);
  *num_products += 1;
  return 1;
}

int update_product(Product* products, int* num_products) {
  int index;
  printf("Enter product index: ");
  scanf("%d", &index);
  if (index >= *num_products) {
    printf("Invalid index\n");
    return 0;
  }
  printf("Enter product name: ");
  scanf("%s", products[index].name);
  printf("Enter product description: ");
  scanf("%s", products[index].description);
  printf("Enter product price: ");
  scanf("%d", &products[index].price);
  printf("Enter product quantity: ");
  scanf("%d", &products[index].quantity);
  return 1;
}

int remove_product(Product* products, int* num_products) {
  int index;
  printf("Enter product index: ");
  scanf("%d", &index);
  if (index >= *num_products) {
    printf("Invalid index\n");
    return 0;
  }
  memmove(products + index, products + index + 1, (*num_products - index - 1) * sizeof(Product));
  *num_products -= 1;
  return 1;
}

void print_inventory(Product* products, int num_products) {
  printf("Inventory:\n");
  for (int i = 0; i < num_products; i++) {
    printf("%d. %s (%s) - $%d (%d in stock)\n", i + 1, products[i].name, products[i].description, products[i].price, products[i].quantity);
  }
}

int main() {
  Product products[MAX_PRODUCTS];
  int num_products = 0;
  int choice;
  while (1) {
    print_menu();
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_product(products, &num_products);
        break;
      case 2:
        update_product(products, &num_products);
        break;
      case 3:
        remove_product(products, &num_products);
        break;
      case 4:
        print_inventory(products, num_products);
        break;
      case 5:
        return 0;
      default:
        printf("Invalid choice\n");
        break;
    }
  }
  return 0;
}