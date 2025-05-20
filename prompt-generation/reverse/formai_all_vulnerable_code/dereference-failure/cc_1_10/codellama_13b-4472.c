//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: detailed
/*
 * Product Inventory System
 *
 * This program demonstrates a simple inventory management system for a retailer.
 * It allows the user to add, remove, and display the current inventory of products.
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a product
typedef struct {
  int id;
  char name[256];
  int quantity;
  float price;
} Product;

// Function to add a product to the inventory
void addProduct(Product *products, int *numProducts) {
  printf("Enter the ID of the product: ");
  scanf("%d", &products[*numProducts].id);
  printf("Enter the name of the product: ");
  scanf("%s", products[*numProducts].name);
  printf("Enter the quantity of the product: ");
  scanf("%d", &products[*numProducts].quantity);
  printf("Enter the price of the product: ");
  scanf("%f", &products[*numProducts].price);
  (*numProducts)++;
}

// Function to remove a product from the inventory
void removeProduct(Product *products, int *numProducts) {
  int index;
  printf("Enter the ID of the product to remove: ");
  scanf("%d", &index);
  for (int i = index; i < *numProducts - 1; i++) {
    products[i] = products[i + 1];
  }
  (*numProducts)--;
}

// Function to display the current inventory
void displayInventory(Product *products, int numProducts) {
  printf("Inventory:\n");
  for (int i = 0; i < numProducts; i++) {
    printf("%d - %s (%d units at $%.2f each)\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
  }
}

int main() {
  int numProducts = 0;
  Product products[100];

  while (1) {
    int choice;
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Display Inventory\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addProduct(products, &numProducts);
        break;
      case 2:
        removeProduct(products, &numProducts);
        break;
      case 3:
        displayInventory(products, numProducts);
        break;
      case 4:
        return 0;
      default:
        printf("Invalid choice. Try again.\n");
        break;
    }
  }
}