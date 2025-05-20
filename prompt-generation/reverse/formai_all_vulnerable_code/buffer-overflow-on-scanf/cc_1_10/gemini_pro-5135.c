//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
  int id;
  char name[50];
  int quantity;
  float price;
};

struct product inventory[MAX_PRODUCTS];

// Function to add a new product to the inventory
void add_product() {
  int id;
  char name[50];
  int quantity;
  float price;

  printf("Enter product ID: ");
  scanf("%d", &id);

  printf("Enter product name: ");
  scanf("%s", name);

  printf("Enter product quantity: ");
  scanf("%d", &quantity);

  printf("Enter product price: ");
  scanf("%f", &price);

  // Check if the product ID already exists in the inventory
  for (int i = 0; i < MAX_PRODUCTS; i++) {
    if (inventory[i].id == id) {
      printf("Product ID already exists!\n");
      return;
    }
  }

  // Add the new product to the inventory
  struct product new_product = {id, name, quantity, price};
  inventory[MAX_PRODUCTS - 1] = new_product;
  printf("Product added successfully!\n");
}

// Function to delete a product from the inventory
void delete_product() {
  int id;

  printf("Enter product ID to delete: ");
  scanf("%d", &id);

  // Find the product in the inventory
  int index = -1;
  for (int i = 0; i < MAX_PRODUCTS; i++) {
    if (inventory[i].id == id) {
      index = i;
      break;
    }
  }

  // If the product is not found, print an error message
  if (index == -1) {
    printf("Product not found!\n");
    return;
  }

  // Delete the product from the inventory
  for (int i = index; i < MAX_PRODUCTS - 1; i++) {
    inventory[i] = inventory[i + 1];
  }
  printf("Product deleted successfully!\n");
}

// Function to update a product in the inventory
void update_product() {
  int id;
  int choice;

  printf("Enter product ID to update: ");
  scanf("%d", &id);

  // Find the product in the inventory
  int index = -1;
  for (int i = 0; i < MAX_PRODUCTS; i++) {
    if (inventory[i].id == id) {
      index = i;
      break;
    }
  }

  // If the product is not found, print an error message
  if (index == -1) {
    printf("Product not found!\n");
    return;
  }

  // Get the user's choice of what to update
  printf("What do you want to update?\n");
  printf("1. Name\n");
  printf("2. Quantity\n");
  printf("3. Price\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Update the product according to the user's choice
  switch (choice) {
    case 1:
      printf("Enter new product name: ");
      scanf("%s", inventory[index].name);
      break;
    case 2:
      printf("Enter new product quantity: ");
      scanf("%d", &inventory[index].quantity);
      break;
    case 3:
      printf("Enter new product price: ");
      scanf("%f", &inventory[index].price);
      break;
    default:
      printf("Invalid choice!\n");
  }

  printf("Product updated successfully!\n");
}

// Function to print the inventory
void print_inventory() {
  printf("Product Inventory\n");
  printf("---------------------------------------------------------\n");
  printf("ID | Name | Quantity | Price\n");
  for (int i = 0; i < MAX_PRODUCTS; i++) {
    printf("%d | %s | %d | %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
  }
  printf("---------------------------------------------------------\n");
}

int main() {
  int choice;

  // Initialize the inventory with some sample products
  struct product product1 = {1, "Apple", 10, 1.00};
  struct product product2 = {2, "Orange", 15, 1.50};
  struct product product3 = {3, "Banana", 20, 2.00};
  inventory[0] = product1;
  inventory[1] = product2;
  inventory[2] = product3;

  do {
    // Display the menu
    printf("\nProduct Inventory System\n");
    printf("---------------------------------------------------------\n");
    printf("1. Add a new product\n");
    printf("2. Delete a product\n");
    printf("3. Update a product\n");
    printf("4. Print the inventory\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Call the appropriate function based on the user's choice
    switch (choice) {
      case 1:
        add_product();
        break;
      case 2:
        delete_product();
        break;
      case 3:
        update_product();
        break;
      case 4:
        print_inventory();
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