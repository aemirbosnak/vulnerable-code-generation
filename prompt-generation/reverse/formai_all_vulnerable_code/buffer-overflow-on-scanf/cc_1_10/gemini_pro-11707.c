//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct Product {
  char name[50];
  int quantity;
  float price;
} Product;

// Function to add a product to the inventory
void addProduct(Product *inventory, int *numProducts) {
  // Get the product details from the user
  printf("Enter the product name: ");
  scanf(" %[^\n]s", inventory[*numProducts].name);
  printf("Enter the product quantity: ");
  scanf(" %d", &inventory[*numProducts].quantity);
  printf("Enter the product price: ");
  scanf(" %f", &inventory[*numProducts].price);

  // Increment the number of products in the inventory
  (*numProducts)++;
}

// Function to remove a product from the inventory
void removeProduct(Product *inventory, int *numProducts) {
  // Get the name of the product to remove
  char productName[50];
  printf("Enter the product name to remove: ");
  scanf(" %[^\n]s", productName);

  // Find the product in the inventory
  int productIndex = -1;
  for (int i = 0; i < *numProducts; i++) {
    if (strcmp(inventory[i].name, productName) == 0) {
      productIndex = i;
      break;
    }
  }

  // If the product was found, remove it from the inventory
  if (productIndex != -1) {
    for (int i = productIndex; i < *numProducts - 1; i++) {
      inventory[i] = inventory[i + 1];
    }
    (*numProducts)--;
    printf("Product removed successfully!\n");
  } else {
    printf("Product not found!\n");
  }
}

// Function to display the inventory
void displayInventory(Product *inventory, int numProducts) {
  if (numProducts == 0) {
    printf("Inventory is empty!\n");
  } else {
    printf("Inventory:\n");
    for (int i = 0; i < numProducts; i++) {
      printf("Product Name: %s\n", inventory[i].name);
      printf("Product Quantity: %d\n", inventory[i].quantity);
      printf("Product Price: %.2f\n\n", inventory[i].price);
    }
  }
}

// Function to search for a product in the inventory
void searchProduct(Product *inventory, int numProducts) {
  // Get the name of the product to search for
  char productName[50];
  printf("Enter the product name to search for: ");
  scanf(" %[^\n]s", productName);

  // Find the product in the inventory
  int productIndex = -1;
  for (int i = 0; i < numProducts; i++) {
    if (strcmp(inventory[i].name, productName) == 0) {
      productIndex = i;
      break;
    }
  }

  // If the product was found, display its details
  if (productIndex != -1) {
    printf("Product found!\n");
    printf("Product Name: %s\n", inventory[productIndex].name);
    printf("Product Quantity: %d\n", inventory[productIndex].quantity);
    printf("Product Price: %.2f\n", inventory[productIndex].price);
  } else {
    printf("Product not found!\n");
  }
}

// Main function
int main() {
  // Create an array of products
  Product inventory[100];

  // Initialize the number of products in the inventory to 0
  int numProducts = 0;

  // Get the user's choice
  int choice;
  do {
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. Display the inventory\n");
    printf("4. Search for a product\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf(" %d", &choice);

    // Call the appropriate function based on the user's choice
    switch (choice) {
      case 1:
        addProduct(inventory, &numProducts);
        break;
      case 2:
        removeProduct(inventory, &numProducts);
        break;
      case 3:
        displayInventory(inventory, numProducts);
        break;
      case 4:
        searchProduct(inventory, numProducts);
        break;
      case 5:
        printf("Exiting the program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 5);

  return 0;
}