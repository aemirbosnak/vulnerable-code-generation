//FormAI DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum number of products that can be added */
#define MAX_PRODUCTS 100

/* Structure to hold information about a product */
typedef struct {
  char name[50];
  char code[10];
  int quantity;
  float price;
} Product;

/* Function to display a single product */
void display_product(Product p) {
  printf("Name: %s\nCode: %s\nQuantity: %d\nPrice: %.2f\n", p.name, p.code, p.quantity, p.price);
}

/* Function to add a product */
void add_product(Product products[], int *count) {
  Product p;

  /* Get user input for product details */
  printf("Enter product name: ");
  scanf("%s", p.name);
  printf("Enter product code: ");
  scanf("%s", p.code);
  printf("Enter product quantity: ");
  scanf("%d", &p.quantity);
  printf("Enter product price: ");
  scanf("%f", &p.price);

  /* Add product to array */
  products[*count] = p;
  (*count)++;

  /* Display success message */
  printf("Product added successfully.\n");
}

/* Function to remove a product */
void remove_product(Product products[], int *count) {
  char code[10];
  int i, j;

  /* Get user input for product code */
  printf("Enter product code: ");
  scanf("%s", code);

  /* Search for product with matching code and remove it */
  for (i = 0; i < *count; i++) {
    if (strcmp(products[i].code, code) == 0) {
      for (j = i; j < *count - 1; j++) {
        products[j] = products[j+1];
      }
      (*count)--;
      printf("Product removed successfully.\n");
      return;
    }
  }

  /* If product not found, display error message */
  printf("Product not found.\n");
}

/* Function to search for a product */
void search_product(Product products[], int count) {
  char code[10];
  int i;

  /* Get user input for product code */
  printf("Enter product code: ");
  scanf("%s", code);

  /* Search for product with matching code and display it */
  for (i = 0; i < count; i++) {
    if (strcmp(products[i].code, code) == 0) {
      display_product(products[i]);
      return;
    }
  }

  /* If product not found, display error message */
  printf("Product not found.\n");
}

/* Function to display all products */
void display_all_products(Product products[], int count) {
  int i;
  for (i = 0; i < count; i++) {
    display_product(products[i]);
    printf("\n");
  }
}

/* Main function */
int main() {
  Product products[MAX_PRODUCTS];
  int count = 0;
  int choice;

  /* Display menu and get user input */
  do {
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Search product\n");
    printf("4. Display all products\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    /* Call appropriate function based on user input */
    switch (choice) {
      case 1:
        add_product(products, &count);
        break;
      case 2:
        remove_product(products, &count);
        break;
      case 3:
        search_product(products, count);
        break;
      case 4:
        display_all_products(products, count);
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }

    /* Display divider */
    printf("\n--------------------------------------------------\n\n");

  } while (choice != 5);

  return 0;
}