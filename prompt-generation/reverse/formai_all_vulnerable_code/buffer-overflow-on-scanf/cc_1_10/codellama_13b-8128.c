//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

struct Product {
  char name[MAX_NAME_LENGTH];
  int price;
};

void print_menu() {
  printf("--------------------------------------\n");
  printf("1. Add product\n");
  printf("2. Remove product\n");
  printf("3. View product\n");
  printf("4. Exit\n");
  printf("--------------------------------------\n");
}

int main() {
  struct Product products[MAX_PRODUCTS];
  int num_products = 0;

  while (1) {
    print_menu();
    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (num_products >= MAX_PRODUCTS) {
          printf("Inventory full, cannot add more products\n");
          break;
        }
        printf("Enter product name: ");
        scanf("%s", products[num_products].name);
        printf("Enter product price: ");
        scanf("%d", &products[num_products].price);
        num_products++;
        break;
      case 2:
        if (num_products <= 0) {
          printf("Inventory empty, cannot remove more products\n");
          break;
        }
        printf("Enter product name: ");
        scanf("%s", products[num_products - 1].name);
        num_products--;
        break;
      case 3:
        printf("Inventory:\n");
        for (int i = 0; i < num_products; i++) {
          printf("%s (%d)\n", products[i].name, products[i].price);
        }
        break;
      case 4:
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}