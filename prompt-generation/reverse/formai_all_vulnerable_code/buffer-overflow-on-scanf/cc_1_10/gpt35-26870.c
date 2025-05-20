//FormAI DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>

// Define a struct for product information
struct Product {
  int id; // Product ID
  char name[50]; // Product name
  int quantity; // Quantity in stock
  float price; // Price of product
};

// Define function to add a new product to inventory
void add_product(struct Product* inventory, int* num_products) {
  // Get inputs from user
  printf("Enter product name: ");
  scanf("%s", inventory[*num_products].name);

  printf("Enter quantity: ");
  scanf("%d", &inventory[*num_products].quantity);

  printf("Enter price: ");
  scanf("%f", &inventory[*num_products].price);

  // Assign ID based on number of products already in inventory
  inventory[*num_products].id = *num_products + 1;

  // Increment number of products
  (*num_products)++;

  // Print confirmation message
  printf("Product added to inventory.\n");
}

// Define function to search for a product by name
void search_product(struct Product* inventory, int num_products) {
  // Get search query from user
  char search_query[50];
  printf("Enter product name to search: ");
  scanf("%s", search_query);

  // Search for product with matching name
  int found = 0; // Flag to indicate if a match was found
  for (int i = 0; i < num_products; i++) {
    if (strcmp(inventory[i].name, search_query) == 0) {
      // Print product information
      printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
             inventory[i].id, inventory[i].name, 
             inventory[i].quantity, inventory[i].price);
      found = 1; // Set flag to indicate match was found
    }
  }

  // Print message if no matching product was found
  if (!found) {
    printf("No matching products found.\n");
  }
}

// Define function to print all products in inventory
void print_inventory(struct Product* inventory, int num_products) {
  // Print header
  printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");

  // Loop through all products and print their information
  for (int i = 0; i < num_products; i++) {
    printf("%-5d %-20s %-10d $%-10.2f\n", inventory[i].id, inventory[i].name, 
           inventory[i].quantity, inventory[i].price);
  }
}

int main() {
  // Initialize an empty inventory and number of products
  struct Product inventory[100];
  int num_products = 0;

  // Welcome message
  printf("Welcome to the product inventory system!\n");

  // Loop to prompt user for actions until they choose to quit
  int quit = 0;
  while (!quit) {
    // Prompt user for action
    printf("Enter 'a' to add a new product, 's' to search for a product, 'p' to print the inventory, or 'q' to quit: ");
    char input;
    scanf(" %c", &input);

    // Switch based on user input
    switch (input) {
      case 'a':
        add_product(inventory, &num_products);
        break;
      case 's':
        search_product(inventory, num_products);
        break;
      case 'p':
        print_inventory(inventory, num_products);
        break;
      case 'q':
        quit = 1;
        break;
      default:
        printf("Invalid input, please try again.\n");
        break;
    }
  }

  // Exit message
  printf("Thank you for using the product inventory system!\n");

  return 0;
}