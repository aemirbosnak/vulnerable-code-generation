//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct product {
  int id;
  char name[50];
  int quantity;
  float price;
} product;

product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
  if (num_products >= MAX_PRODUCTS) {
    printf("Inventory is full!\n");
    return;
  }

  product new_product;

  printf("Enter product ID: ");
  scanf("%d", &new_product.id);

  printf("Enter product name: ");
  scanf("%s", new_product.name);

  printf("Enter product quantity: ");
  scanf("%d", &new_product.quantity);

  printf("Enter product price: ");
  scanf("%f", &new_product.price);

  inventory[num_products++] = new_product;
}

void remove_product() {
  int id;

  printf("Enter product ID to remove: ");
  scanf("%d", &id);

  int found = 0;

  for (int i = 0; i < num_products; i++) {
    if (inventory[i].id == id) {
      found = 1;

      for (int j = i; j < num_products - 1; j++) {
        inventory[j] = inventory[j + 1];
      }

      num_products--;
      break;
    }
  }

  if (!found) {
    printf("Product not found!\n");
  }
}

void update_product() {
  int id;

  printf("Enter product ID to update: ");
  scanf("%d", &id);

  int found = 0;

  for (int i = 0; i < num_products; i++) {
    if (inventory[i].id == id) {
      found = 1;

      char choice;

      printf("Update product name (y/n)? ");
      scanf(" %c", &choice);
      if (choice == 'y') {
        printf("Enter new product name: ");
        scanf("%s", inventory[i].name);
      }

      printf("Update product quantity (y/n)? ");
      scanf(" %c", &choice);
      if (choice == 'y') {
        printf("Enter new product quantity: ");
        scanf("%d", &inventory[i].quantity);
      }

      printf("Update product price (y/n)? ");
      scanf(" %c", &choice);
      if (choice == 'y') {
        printf("Enter new product price: ");
        scanf("%f", &inventory[i].price);
      }

      break;
    }
  }

  if (!found) {
    printf("Product not found!\n");
  }
}

void search_product() {
  int id;

  printf("Enter product ID to search: ");
  scanf("%d", &id);

  int found = 0;

  for (int i = 0; i < num_products; i++) {
    if (inventory[i].id == id) {
      found = 1;

      printf("Product found:\n");
      printf("ID: %d\n", inventory[i].id);
      printf("Name: %s\n", inventory[i].name);
      printf("Quantity: %d\n", inventory[i].quantity);
      printf("Price: %.2f\n", inventory[i].price);

      break;
    }
  }

  if (!found) {
    printf("Product not found!\n");
  }
}

void display_inventory() {
  printf("Product Inventory:\n");
  for (int i = 0; i < num_products; i++) {
    printf("ID: %d\n", inventory[i].id);
    printf("Name: %s\n", inventory[i].name);
    printf("Quantity: %d\n", inventory[i].quantity);
    printf("Price: %.2f\n\n", inventory[i].price);
  }
}

int main() {
  int choice;

  do {
    printf("\nProduct Inventory System\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update product\n");
    printf("4. Search product\n");
    printf("5. Display inventory\n");
    printf("6. Exit\n");
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
        search_product();
        break;
      case 5:
        display_inventory();
        break;
      case 6:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 6);

  return 0;
}