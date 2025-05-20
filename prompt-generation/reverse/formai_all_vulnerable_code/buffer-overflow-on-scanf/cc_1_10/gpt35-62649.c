//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants
#define MAX_PRODUCTS 100
#define MAX_STOCK 1000

// Define structs
typedef struct Product {
  int id;
  char name[50];
  float price;
} Product;

typedef struct StockItem {
  Product product;
  int quantity;
} StockItem;

// Define global variables
Product products[MAX_PRODUCTS];
StockItem stock[MAX_STOCK];
int numProducts = 0;
int numItems = 0;

// Function declarations
void addProduct();
void addStock();
void viewStock();
void updatePrice();

int main() {
  int choice;
  do {
    // Display menu
    printf("Warehouse Management System\n");
    printf("1. Add new product\n");
    printf("2. Add stock\n");
    printf("3. View stock\n");
    printf("4. Update product price\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    printf("\n");

    // Perform actions based on menu choice
    switch (choice) {
      case 1: addProduct(); break;
      case 2: addStock(); break;
      case 3: viewStock(); break;
      case 4: updatePrice(); break;
      case 5: exit(0);
      default: printf("Invalid choice, please try again.\n\n");
    }
  } while (true);

  return 0;
}

void addProduct() {
  // Check if maximum number of products has been reached
  if (numProducts == MAX_PRODUCTS) {
    printf("Maximum number of products reached.\n\n");
    return;
  }

  // Ask for product details
  Product product;
  printf("Enter product name: ");
  scanf("%s", product.name);
  printf("Enter product price: ");
  scanf("%f", &product.price);

  // Assign product ID
  product.id = numProducts + 1;

  // Add product to products array
  products[numProducts++] = product;

  printf("Product added successfully.\n\n");
}

void addStock() {
  // Check if there are any products to add stock to
  if (numProducts == 0) {
    printf("No products found.\n\n");
    return;
  }

  // Check if maximum number of stock items has been reached
  if (numItems == MAX_STOCK) {
    printf("Maximum number of stock items reached.\n\n");
    return;
  }

  // Ask for product ID and quantity
  int productId, quantity;
  printf("Enter product ID: ");
  scanf("%d", &productId);
  printf("Enter quantity: ");
  scanf("%d", &quantity);

  // Find product with matching ID
  int i;
  for (i = 0; i < numProducts; i++) {
    if (products[i].id == productId) {
      break;
    }
  }

  // If product was not found, display error message
  if (i == numProducts) {
    printf("Product not found.\n\n");
    return;
  }

  // Update stock quantity for product
  stock[numItems].product = products[i];
  stock[numItems].quantity = quantity;
  numItems++;

  printf("Stock added successfully.\n\n");
}

void viewStock() {
  // Check if there is any stock to view
  if (numItems == 0) {
    printf("No stock found.\n\n");
    return;
  }

  // Display header row for stock table
  printf("%-20s %-10s %-10s\n", "Product Name", "Price", "Quantity");

  // Loop through stock and display each item
  int i;
  for (i = 0; i < numItems; i++) {
    printf("%-20s $%.2f %-10d\n", 
      stock[i].product.name, 
      stock[i].product.price, 
      stock[i].quantity);
  }

  printf("\n");
}

void updatePrice() {
  // Check if there are any products to update
  if (numProducts == 0) {
    printf("No products found.\n\n");
    return;
  }

  // Ask for product ID and new price
  int productId;
  float price;
  printf("Enter product ID: ");
  scanf("%d", &productId);
  printf("Enter new price: ");
  scanf("%f", &price);

  // Find product with matching ID
  int i;
  for (i = 0; i < numProducts; i++) {
    if (products[i].id == productId) {
      break;
    }
  }

  // If product was not found, display error message
  if (i == numProducts) {
    printf("Product not found.\n\n");
    return;
  }

  // Update product price
  products[i].price = price;

  printf("Price updated successfully.\n\n");
}