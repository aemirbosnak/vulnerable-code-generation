//FormAI DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
  char name[50];
  int id;
  int quantity;
};

struct product products[MAX_PRODUCTS];
int num_of_products = 0;

// Function to add a new product to the inventory
void add_product() {
  struct product p;
  printf("Enter product name:\n");
  scanf("%s", p.name);
  printf("Enter product ID:\n");
  scanf("%d", &p.id);
  printf("Enter product quantity:\n");
  scanf("%d", &p.quantity);

  products[num_of_products] = p;
  num_of_products++;

  printf("Product added successfully!\n");
}

// Function to search a product by ID
void search_product() {
  int id;
  printf("Enter product ID:\n");
  scanf("%d", &id);

  for (int i = 0; i < num_of_products; i++) {
    if (products[i].id == id) {
      printf("Name: %s\n", products[i].name);
      printf("ID: %d\n", products[i].id);
      printf("Quantity: %d\n", products[i].quantity);
      return;
    }
  }

  printf("Product not found.\n");
}

// Function to remove a product by ID
void remove_product() {
  int id;
  printf("Enter product ID:\n");
  scanf("%d", &id);

  for (int i = 0; i < num_of_products; i++) {
    if (products[i].id == id) {
      for (int j = i; j < num_of_products - 1; j++) {
        products[j] = products[j + 1];
      }
      num_of_products--;
      printf("Product removed successfully!\n");
      return;
    }
  }

  printf("Product not found.\n");
}

// Function to display all products in the inventory
void display_products() {
  printf("Inventory:\n");
  for (int i = 0; i < num_of_products; i++) {
    struct product p = products[i];
    printf("Name: %s\n", p.name);
    printf("ID: %d\n", p.id);
    printf("Quantity: %d\n", p.quantity);
  }
}

int main() {
  int option;
  printf("Welcome to the Product Inventory System!\n");

  do {
    printf("\nChoose an option:\n");
    printf("1. Add a product\n");
    printf("2. Search for a product\n");
    printf("3. Remove a product\n");
    printf("4. Display all products\n");
    printf("0. Exit\n");
    scanf("%d", &option);

    switch (option) {
      case 1:
        add_product();
        break;
      case 2:
        search_product();
        break;
      case 3:
        remove_product();
        break;
      case 4:
        display_products();
        break;
      case 0:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid option.\n");
        break;
    }
  } while (option != 0);

  return 0;
}