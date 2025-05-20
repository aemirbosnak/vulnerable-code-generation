//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
  int id;
  char name[20];
  int quantity;
  float price_per_unit;
};

void display_product(struct product p) {
  printf("ID: %d\nName: %s\nQuantity: %d\nPrice per unit: $%.2f\n", p.id, p.name, p.quantity, p.price_per_unit);
}

void display_all_products(struct product arr[], int size) {
  printf("\nAll Products:\n");
  for (int i = 0; i < size; i++) {
    display_product(arr[i]);
    printf("\n");
  }
}

void add_product(struct product arr[], int *size, struct product new_product) {
  arr[*size] = new_product;
  (*size)++;
  printf("Product added successfully!\n");
}

void remove_product(struct product arr[], int *size, int id) {
  int index = -1;
  for (int i = 0; i < *size; i++) {
    if (arr[i].id == id) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    printf("Product not found!\n");
  } else {
    for (int i = index; i < *size - 1; i++) {
      arr[i] = arr[i+1];
    }
    (*size)--;
    printf("Product removed successfully!\n");
  }
}

void update_product(struct product arr[], int size, int id, struct product new_product) {
  int index = -1;
  for (int i = 0; i < size; i++) {
    if (arr[i].id == id) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    printf("Product not found!\n");
  } else {
    arr[index] = new_product;
    printf("Product updated successfully!\n");
  }
}

int main() {
  struct product products[100];
  int num_products = 0;

  while (1) {
    printf("\n1. Display all products\n");
    printf("2. Add a product\n");
    printf("3. Remove a product\n");
    printf("4. Update a product\n");
    printf("5. Quit\n");

    int choice;
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        display_all_products(products, num_products);
        break;
      case 2: {
        struct product new_product;
        printf("Enter product ID: ");
        scanf("%d", &new_product.id);
        printf("Enter product name: ");
        scanf("%s", new_product.name);
        printf("Enter product quantity: ");
        scanf("%d", &new_product.quantity);
        printf("Enter product price per unit: ");
        scanf("%f", &new_product.price_per_unit);
        add_product(products, &num_products, new_product);
        break;
      }
      case 3: {
        int id;
        printf("Enter ID of product to remove: ");
        scanf("%d", &id);
        remove_product(products, &num_products, id);
        break;
      }
      case 4: {
        int id;
        printf("Enter ID of product to update: ");
        scanf("%d", &id);
        struct product new_product;
        printf("Enter new product ID: ");
        scanf("%d", &new_product.id);
        printf("Enter new product name: ");
        scanf("%s", new_product.name);
        printf("Enter new product quantity: ");
        scanf("%d", &new_product.quantity);
        printf("Enter new product price per unit: ");
        scanf("%f", &new_product.price_per_unit);
        update_product(products, num_products, id, new_product);
        break;
      }
      case 5:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}