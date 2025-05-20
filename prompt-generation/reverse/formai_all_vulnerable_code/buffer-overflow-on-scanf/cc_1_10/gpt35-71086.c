//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
/*
 * C Product Inventory System
 * Written by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
  char name[30];
  float price;
  int quantity;
};

int num_products = 0;
struct product inventory[MAX_PRODUCTS];

void add_product() {
  if (num_products < MAX_PRODUCTS) {
    struct product p;
    printf("Name: ");
    scanf("%s", p.name);
    printf("Price: ");
    scanf("%f", &p.price);
    printf("Quantity: ");
    scanf("%d", &p.quantity);
    inventory[num_products] = p;
    num_products++;
    printf("Product added successfully!\n");
  } else {
    printf("Inventory is full!\n");
  }
}

void display_inventory() {
  printf("Inventory:\n");
  printf("%-30s%10s%10s\n", "Name", "Price", "Quantity");
  for (int i = 0; i < num_products; i++) {
    printf("%-30s%10.2f%10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
  }
}

void sell_product() {
  char name[30];
  printf("Name of product to sell: ");
  scanf("%s", name);
  for (int i = 0; i < num_products; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      int quantity;
      printf("Quantity to sell: ");
      scanf("%d", &quantity);
      if (quantity > 0 && quantity <= inventory[i].quantity) {
        inventory[i].quantity -= quantity;
        printf("Sold successfully!\n");
        return;
      } else {
        printf("Invalid quantity!\n");
        return;
      }
    }
  }
  printf("Product not found!\n");
}

int main() {
  int choice;
  do {
    printf("1. Add product\n");
    printf("2. Display inventory\n");
    printf("3. Sell product\n");
    printf("4. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_product();
        break;
      case 2:
        display_inventory();
        break;
      case 3:
        sell_product();
        break;
      case 4:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
  } while (choice != 4);
  return 0;
}