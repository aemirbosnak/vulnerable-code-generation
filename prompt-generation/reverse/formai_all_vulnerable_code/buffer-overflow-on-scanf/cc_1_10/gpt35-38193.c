//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME 50
#define MAX_QUANTITY 10
#define MAX_PRICE 10

struct product {
  char name[MAX_NAME];
  int quantity;
  float price;
};

struct product inventory[MAX_PRODUCTS];
int num_products = 0;

void clear_input_buff(void) {
  char c = getchar();
  while (c != '\n' && c != EOF) {
    c = getchar();
  }
}

void add_product(void) {
  char name[MAX_NAME];
  int quantity;
  float price;

  if (num_products == MAX_PRODUCTS) {
    printf("Inventory is full!\n");
    return;
  }

  printf("Enter product name: ");
  scanf("%[^\n]", name);
  clear_input_buff();

  if (strlen(name) > MAX_NAME) {
    printf("Product name is too long!\n");
    return;
  }

  printf("Enter product quantity: ");
  if (scanf("%d", &quantity) != 1) {
    printf("Invalid input!\n");
    clear_input_buff();
    return;
  }
  if (quantity > MAX_QUANTITY) {
    printf("Quantity is too large!\n");
    return;
  }

  printf("Enter product price: ");
  if (scanf("%f", &price) != 1) {
    printf("Invalid input!\n");
    clear_input_buff();
    return;
  }
  if (price > MAX_PRICE) {
    printf("Price is too high!\n");
    return;
  }

  struct product new_product;
  strcpy(new_product.name, name);
  new_product.quantity = quantity;
  new_product.price = price;

  inventory[num_products++] = new_product;

  printf("Product added to inventory!\n");
}

void remove_product(void) {
  char name[MAX_NAME];

  if (num_products == 0) {
    printf("Inventory is empty!\n");
    return;
  }

  printf("Enter name of product to remove: ");
  scanf("%[^\n]", name);
  clear_input_buff();

  for (int i = 0; i < num_products; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      for (int j = i + 1; j < num_products; j++) {
        inventory[j-1] = inventory[j];
      }
      num_products--;
      printf("Product removed from inventory!\n");
      return;
    }
  }

  printf("Product was not found!\n");
}

void display_inventory(void) {
  if (num_products == 0) {
    printf("Inventory is empty!\n");
    return;
  }

  printf("%-50s %-20s %-20s\n", "Product Name", "Quantity", "Price");

  for (int i = 0; i < num_products; i++) {
    printf("%-50s %-20d $%-19.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
  }
}

void display_menu(void) {
  printf("Product Inventory System\n");
  printf("1. Add Product\n");
  printf("2. Remove Product\n");
  printf("3. Display Inventory\n");
  printf("4. Quit\n");
}

int main(void) {
  int choice;

  do {
    display_menu();
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) {
      printf("Invalid input!\n");
      clear_input_buff();
      continue;
    }
    clear_input_buff();

    switch (choice) {
      case 1:
        add_product();
        printf("\n");
        break;
      case 2:
        remove_product();
        printf("\n");
        break;
      case 3:
        display_inventory();
        printf("\n");
        break;
      case 4:
        printf("Exiting...\n");
        printf("\n");
        break;
      default:
        printf("Invalid choice!\n");
        printf("\n");
        break;
    }
  } while (choice != 4);

  return EXIT_SUCCESS;
}