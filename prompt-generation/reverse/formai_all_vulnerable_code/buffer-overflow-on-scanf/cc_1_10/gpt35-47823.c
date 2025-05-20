//FormAI DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
  char name[50];
  double price;
  int quantity;
};

struct Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
  if (num_products == MAX_PRODUCTS) {
    printf("Error: Max number of products reached\n");
    return;
  }

  struct Product p;
  printf("Enter product name: ");
  scanf("%s", p.name);
  printf("Enter price: ");
  scanf("%lf", &p.price);
  printf("Enter quantity: ");
  scanf("%d", &p.quantity);

  products[num_products] = p;
  num_products++;

  printf("Product added successfully\n\n");
}

void update_product() {
  char name[50];
  printf("Enter name of product to update: ");
  scanf("%s", name);

  int found = 0;
  for (int i = 0; i < num_products; i++) {
    if (strcmp(products[i].name, name) == 0) {
      printf("Enter new price: ");
      scanf("%lf", &products[i].price);
      printf("Enter new quantity: ");
      scanf("%d", &products[i].quantity);
      found = 1;
      break;
    }
  }

  if (found) {
    printf("Product updated successfully\n\n");
  } else {
    printf("Error: Product not found\n\n");
  }
}

void view_inventory() {
  printf("\n\n======= INVENTORY =======\n\n");
  printf("%-30s%-10s%-10s\n", "Name", "Price", "Quantity");
  for (int i = 0; i < num_products; i++) {
    printf("%-30s%-10.2lf%-10d\n", products[i].name, products[i].price, products[i].quantity);
  }
  printf("\n");
}

int main() {
  int choice;

  do {
    printf("Enter 1 to add product\n");
    printf("Enter 2 to update product\n");
    printf("Enter 3 to view inventory\n");
    printf("Enter 4 to exit\n");

    scanf("%d", &choice);
    printf("\n");

    switch(choice) {
        case 1:
            add_product();
            break;
        case 2:
            update_product();
            break;
        case 3:
            view_inventory();
            break;
        case 4:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Error: Invalid Input\n\n");
            break;
    }
  } while (1);

  return 0;
}