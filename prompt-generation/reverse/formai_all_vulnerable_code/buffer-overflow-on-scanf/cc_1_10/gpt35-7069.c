//FormAI DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct {
  int id;
  char name[20];
  int quantity;
  float price;
} Product;

// Function prototypes
void addProduct();
void listProducts();
void searchProduct();
void updateProduct();
void deleteProduct();

// Global variables
Product inventory[1000];
int count = 0;

int main() {
  int choice;

  do {
    // Print menu
    printf("\n==== PRODUCT INVENTORY SYSTEM ====\n");
    printf("1. Add a product\n");
    printf("2. List all products\n");
    printf("3. Search for a product\n");
    printf("4. Update a product\n");
    printf("5. Delete a product\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");

    // Get user input
    scanf("%d", &choice);
    fflush(stdin);

    // Perform action based on user input
    switch (choice) {
      case 1:
        addProduct();
        break;
      case 2:
        listProducts();
        break;
      case 3:
        searchProduct();
        break;
      case 4:
        updateProduct();
        break;
      case 5:
        deleteProduct();
        break;
      case 0:
        printf("\nGoodbye!\n");
        break;
      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  } while (choice != 0);

  return 0;
}

// Function to add a new product
void addProduct() {
  Product product;

  // Get information from user
  printf("\nEnter the product ID: ");
  scanf("%d", &product.id);

  printf("Enter the product name: ");
  scanf("%s", product.name);

  printf("Enter the product quantity: ");
  scanf("%d", &product.quantity);

  printf("Enter the product price: ");
  scanf("%f", &product.price);

  // Add product to inventory
  inventory[count++] = product;

  printf("\nProduct added successfully!\n");
}

// Function to list all products
void listProducts() {
  // Check if inventory is empty
  if (count == 0) {
    printf("\nInventory is empty.\n");
    return;
  }

  // Print header
  printf("\n%-5s %-20s %-10s %-10s\n","ID","NAME","QUANTITY","PRICE");

  // Print each product
  for (int i = 0; i < count; i++) {
    Product product = inventory[i];
    printf("%-5d %-20s %-10d $%-9.2f\n",product.id,product.name,product.quantity,product.price);
  }
}

// Function to search for a product
void searchProduct() {
  int id;

  // Get product ID from user
  printf("\nEnter the product ID to search: ");
  scanf("%d", &id);

  // Search for product in inventory
  for (int i = 0; i < count; i++) {
    if (inventory[i].id == id) {
      // Print product information
      printf("\nProduct found!\n");
      printf("ID: %d\n", inventory[i].id);
      printf("Name: %s\n", inventory[i].name);
      printf("Quantity: %d\n", inventory[i].quantity);
      printf("Price: $%.2f\n", inventory[i].price);
      return;
    }
  }

  // Product not found
  printf("\nProduct not found.\n");
}

// Function to update a product
void updateProduct() {
  int id;

  // Get product ID from user
  printf("\nEnter the product ID to update: ");
  scanf("%d", &id);

  // Search for product in inventory
  for (int i = 0; i < count; i++) {
    if (inventory[i].id == id) {
      // Get updated information from user
      printf("Enter the new product name: ");
      scanf("%s", inventory[i].name);

      printf("Enter the new product quantity: ");
      scanf("%d", &inventory[i].quantity);

      printf("Enter the new product price: ");
      scanf("%f", &inventory[i].price);

      printf("\nProduct updated successfully!\n");
      return;
    }
  }

  // Product not found
  printf("\nProduct not found.\n");
}

// Function to delete a product
void deleteProduct() {
  int id;

  // Get product ID from user
  printf("\nEnter the product ID to delete: ");
  scanf("%d", &id);

  // Search for product in inventory
  for (int i = 0; i < count; i++) {
    if (inventory[i].id == id) {
      // Shift all products after the deleted product back one position
      for (int j = i; j < count - 1; j++) {
        inventory[j] = inventory[j+1];
      }

      // Decrement count to reflect deleted product
      count--;

      printf("\nProduct deleted successfully!\n");
      return;
    }
  }

  // Product not found
  printf("\nProduct not found.\n");
}