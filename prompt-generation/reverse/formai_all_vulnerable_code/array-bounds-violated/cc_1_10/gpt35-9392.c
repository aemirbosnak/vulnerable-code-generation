//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000

typedef struct product {
  int id;
  char name[50];
  float price;
  int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;

void add_product() {
  if (product_count < MAX_PRODUCTS) {
    printf("Enter product name: ");
    fgets(inventory[product_count].name, 50, stdin);
    printf("Enter product price: ");
    scanf("%f", &inventory[product_count].price);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[product_count].quantity);
    inventory[product_count].id = product_count + 1;
    printf("Product added successfully with ID: %d\n", inventory[product_count].id);
    product_count++;
  } else {
    printf("Inventory is full. Unable to add product.\n");
  }
}

void remove_product() {
  int id, index;
  printf("Enter product ID to remove: ");
  scanf("%d", &id);
  
  for (int i = 0; i < product_count; i++) {
    if (inventory[i].id == id) {
      index = i;
      break;
    }
  }
  
  if (inventory[index].id == id) {
    for (int i = index; i < product_count - 1; i++) {
      inventory[i] = inventory[i + 1];
    }
    
    memset(&inventory[product_count - 1], 0, sizeof(Product));
    product_count--;
    printf("Product with ID %d removed successfully.\n", id);
  } else {
    printf("Product with ID %d not found.\n", id);
  }
}

void display_products() {
  printf("| %-10s | %-20s | %-10s | %-10s |\n", "ID", "Product Name", "Price", "Quantity");
  printf("|------------|---------------------|------------|------------|\n");
  
  for (int i = 0; i < product_count; i++) {
    printf("| %-10d | %-20s | %-10.2f | %-10d |\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
  }
}

int main() {
  int choice;
  
  do {
    printf("\n1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Display products\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar(); // To clear the input buffer
    
    switch (choice) {
      case 1:
        add_product();
        break;
      case 2:
        remove_product();
        break;
      case 3:
        display_products();
        break;
      case 4:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != 4);
  
  return 0;
}