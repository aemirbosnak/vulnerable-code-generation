//FormAI DATASET v1.0 Category: Product Inventory System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void add_product();
void display_products();
void search_product();
void update_product();
void delete_product();

// Struct to hold product information
struct Product {
  char name[50];
  int quantity;
  float price;
};

// Global variables
struct Product* inventory; // Pointer to dynamic array of products
int num_products = 0; // Number of products in inventory

int main() {
  int choice = 0;

  // Main menu
  while (choice != 6) {
    printf("\n------- Product Inventory System -------\n");
    printf("1. Add a product\n");
    printf("2. Display all products\n");
    printf("3. Search for a product\n");
    printf("4. Update a product\n");
    printf("5. Delete a product\n");
    printf("6. Quit\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_product();
        break;
      case 2:
        display_products();
        break;
      case 3:
        search_product();
        break;
      case 4:
        update_product();
        break;
      case 5:
        delete_product();
        break;
      case 6:
        printf("\nExiting program...\n");
        break;
      default:
        printf("\nInvalid choice. Please try again.\n");
    }
  }

  free(inventory); // Free memory allocated to inventory array

  return 0;
}

// Function to add a product to inventory
void add_product() {
  // Increase size of inventory array
  num_products++;
  inventory = (struct Product*)realloc(inventory, num_products * sizeof(struct Product));

  // Get product information from user input
  printf("\nEnter product name: ");
  scanf("%s", inventory[num_products-1].name);
  printf("Enter product quantity: ");
  scanf("%d", &inventory[num_products-1].quantity);
  printf("Enter product price: ");
  scanf("%f", &inventory[num_products-1].price);

  printf("\nProduct successfully added to inventory.\n");
}

// Function to display all products in inventory
void display_products() {
  printf("\nCurrent products in inventory:\n");
  for (int i = 0; i < num_products; i++) {
    printf("Product #%d:\n", i+1);
    printf("  Name: %s\n", inventory[i].name);
    printf("  Quantity: %d\n", inventory[i].quantity);
    printf("  Price: $%.2f\n\n", inventory[i].price);
  }
}

// Function to search for a product in inventory by name
void search_product() {
  char search_term[50];
  int found = 0;

  printf("\nEnter product name to search: ");
  scanf("%s", search_term);

  for (int i = 0; i < num_products; i++) {
    if (strcmp(inventory[i].name, search_term) == 0) {
      printf("\nProduct found:\n");
      printf("  Name: %s\n", inventory[i].name);
      printf("  Quantity: %d\n", inventory[i].quantity);
      printf("  Price: $%.2f\n", inventory[i].price);
      found = 1;
      break;
    }
  }

  if (found == 0) {
    printf("\nProduct not found.\n");
  }
}

// Function to update a product in inventory
void update_product() {
  int product_num;
  char new_name[50];
  int new_quantity;
  float new_price;

  printf("\nEnter product number to update (1-%d): ", num_products);
  scanf("%d", &product_num);

  if (product_num >= 1 && product_num <= num_products) {
    printf("\nEnter updated product name: ");
    scanf("%s", new_name);
    printf("Enter updated product quantity: ");
    scanf("%d", &new_quantity);
    printf("Enter updated product price: ");
    scanf("%f", &new_price);

    // Update product information in inventory
    strcpy(inventory[product_num-1].name, new_name);
    inventory[product_num-1].quantity = new_quantity;
    inventory[product_num-1].price = new_price;

    printf("\nProduct successfully updated.\n");
  } else {
    printf("\nInvalid product number. Please try again.\n");
  }
}

// Function to delete a product from inventory
void delete_product() {
  int product_num;

  printf("\nEnter product number to delete (1-%d): ", num_products);
  scanf("%d", &product_num);

  if (product_num >= 1 && product_num <= num_products) {
    // Shift elements in inventory array to remove product at specified index
    for (int i = product_num-1; i < num_products-1; i++) {
      strcpy(inventory[i].name, inventory[i+1].name);
      inventory[i].quantity = inventory[i+1].quantity;
      inventory[i].price = inventory[i+1].price;
    }

    // Decrease size of inventory array
    num_products--;
    inventory = (struct Product*)realloc(inventory, num_products * sizeof(struct Product));

    printf("\nProduct successfully deleted.\n");
  } else {
    printf("\nInvalid product number. Please try again.\n");
  }
}