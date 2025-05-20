//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: multivariable
// Product Inventory System

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a product
struct Product {
  int id;
  char name[50];
  float price;
  int quantity;
};

// Function to add a new product to the inventory
void addProduct(struct Product* inventory, int size, int* numProducts) {
  if (*numProducts == size) {
    printf("Inventory is full. Cannot add more products.\n");
    return;
  }

  // Prompt the user for product details
  printf("Enter product details:\n");
  printf("ID: ");
  scanf("%d", &inventory[*numProducts].id);
  printf("Name: ");
  scanf("%s", &inventory[*numProducts].name);
  printf("Price: ");
  scanf("%f", &inventory[*numProducts].price);
  printf("Quantity: ");
  scanf("%d", &inventory[*numProducts].quantity);

  // Increment the number of products in the inventory
  (*numProducts)++;
}

// Function to update the quantity of a product in the inventory
void updateQuantity(struct Product* inventory, int size, int numProducts, int id, int quantity) {
  // Find the product with the given ID
  for (int i = 0; i < numProducts; i++) {
    if (inventory[i].id == id) {
      // Update the product quantity
      inventory[i].quantity = quantity;
      break;
    }
  }
}

// Function to print the inventory
void printInventory(struct Product* inventory, int size, int numProducts) {
  // Print the header
  printf("Product ID\tName\t\tPrice\t\tQuantity\n");
  printf("----------------------------------------------\n");

  // Print each product in the inventory
  for (int i = 0; i < numProducts; i++) {
    printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
  }
}

int main() {
  // Initialize the inventory array
  struct Product inventory[10];
  int numProducts = 0;

  // Add products to the inventory
  addProduct(inventory, 10, &numProducts);
  addProduct(inventory, 10, &numProducts);
  addProduct(inventory, 10, &numProducts);

  // Update the quantity of a product
  updateQuantity(inventory, 10, numProducts, 1, 5);

  // Print the inventory
  printInventory(inventory, 10, numProducts);

  return 0;
}