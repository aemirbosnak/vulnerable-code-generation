//FormAI DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for products
struct product {
  char name[50];
  int quantity;
  float price;
};

// Function to display menu and get user input
void display_menu() {
  printf("\n---- Product Inventory System ----\n\n");
  printf("1. Add a new product\n");
  printf("2. View inventory\n");
  printf("3. Update product information\n");
  printf("4. Exit\n\n");
  printf("Enter your choice: ");
}

// Function to add a new product to inventory
void add_product(struct product inventory[], int *num_products) {
  // Check if inventory is full
  if (*num_products >= 50) {
    printf("\nSorry, inventory is full. Cannot add any more products.\n");
    return;
  }
  // Get user input
  printf("\nEnter product name: ");
  scanf("%s", inventory[*num_products].name);
  printf("Enter product quantity: ");
  scanf("%d", &inventory[*num_products].quantity);
  printf("Enter product price: ");
  scanf("%f", &inventory[*num_products].price);
  // Increment number of products
  (*num_products)++;
  printf("\nProduct added successfully!\n");
}

// Function to view inventory
void view_inventory(struct product inventory[], int num_products) {
  // Check if inventory is empty
  if (num_products == 0) {
    printf("\nInventory is empty.\n");
    return;
  }
  // Display header
  printf("\n%-30s %-15s %-15s\n", "Product Name", "Quantity", "Price");
  // Display each product
  for (int i = 0; i < num_products; i++) {
    printf("%-30s %-15d %-15.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
  }
}

// Function to update product information
void update_product(struct product inventory[], int num_products) {
  // Get user input
  printf("\nEnter product name: ");
  char name[50];
  scanf("%s", name);
  // Find product with matching name
  int index = -1;
  for (int i = 0; i < num_products; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      index = i;
      break;
    }
  }
  // Return if product not found
  if (index == -1) {
    printf("\nProduct not found.\n");
    return;
  }
  // Update product information
  printf("Enter new quantity: ");
  scanf("%d", &inventory[index].quantity);
  printf("Enter new price: ");
  scanf("%f", &inventory[index].price);
  printf("\nProduct information updated successfully!\n");
}

int main() {
  // Define inventory array
  struct product inventory[50];
  int num_products = 0;
  // Loop until user chooses to exit
  while (1) {
    display_menu();
    int choice;
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_product(inventory, &num_products);
        break;
      case 2:
        view_inventory(inventory, num_products);
        break;
      case 3:
        update_product(inventory, num_products);
        break;
      case 4:
        printf("\nThank you for using the Product Inventory System.\n");
        exit(0);
      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  }
  return 0;
}