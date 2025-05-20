//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct Product {
  int id;
  char name[256];
  int quantity;
  double price;
} Product;

// Array of products
Product products[] = {
  {1, "Apple", 10, 1.0},
  {2, "Orange", 5, 1.2},
  {3, "Banana", 15, 1.5},
  {4, "Grape", 8, 1.8},
  {5, "Strawberry", 12, 2.0},
};

// Number of products
int num_products = sizeof(products) / sizeof(Product);

// Function to add a new product
void add_product() {
  // Get product details from user
  Product new_product;
  printf("Enter product ID: ");
  scanf("%d", &new_product.id);
  printf("Enter product name: ");
  scanf(" %s", new_product.name);
  printf("Enter product quantity: ");
  scanf("%d", &new_product.quantity);
  printf("Enter product price: ");
  scanf("%lf", &new_product.price);

  // Add new product to array
  products[num_products++] = new_product;
  printf("Product added successfully!\n");
}

// Function to delete a product
void delete_product() {
  // Get product ID from user
  int product_id;
  printf("Enter product ID to delete: ");
  scanf("%d", &product_id);

  // Find product by ID
  int index = -1;
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == product_id) {
      index = i;
      break;
    }
  }

  // Delete product if found
  if (index != -1) {
    for (int i = index; i < num_products - 1; i++) {
      products[i] = products[i + 1];
    }
    num_products--;
    printf("Product deleted successfully!\n");
  } else {
    printf("Product not found!\n");
  }
}

// Function to update a product
void update_product() {
  // Get product ID from user
  int product_id;
  printf("Enter product ID to update: ");
  scanf("%d", &product_id);

  // Find product by ID
  int index = -1;
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == product_id) {
      index = i;
      break;
    }
  }

  // Update product if found
  if (index != -1) {
    // Get updated product details from user
    printf("Enter new product name (leave blank to keep same): ");
    scanf(" %s", products[index].name);
    printf("Enter new product quantity (leave blank to keep same): ");
    scanf("%d", &products[index].quantity);
    printf("Enter new product price (leave blank to keep same): ");
    scanf("%lf", &products[index].price);
    printf("Product updated successfully!\n");
  } else {
    printf("Product not found!\n");
  }
}

// Function to display all products
void display_products() {
  // Print header
  printf("==================================================================\n");
  printf("| ID | Name | Quantity | Price |\n");
  printf("==================================================================\n");

  // Print each product
  for (int i = 0; i < num_products; i++) {
    printf("| %d | %s | %d | %.2lf |\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
  }

  // Print footer
  printf("==================================================================\n");
}

// Main function
int main() {
  // Display welcome message
  printf("Welcome to the Warehouse Management System!\n");

  // Display menu
  int choice;
  do {
    printf("\nChoose an option:\n");
    printf("1. Add a new product\n");
    printf("2. Delete a product\n");
    printf("3. Update a product\n");
    printf("4. Display all products\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Call appropriate function based on user's choice
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
        display_products();
        break;
      case 5:
        printf("Thank you for using the Warehouse Management System!\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 5);

  return 0;
}