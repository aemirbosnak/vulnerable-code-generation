//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: imaginative
/*
 * C Product Inventory System
 *
 * An imaginative program to manage inventory for a fictional store.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct {
  char name[50];
  int price;
  int quantity;
} Product;

// Structure to represent a customer
typedef struct {
  char name[50];
  int age;
  char address[50];
} Customer;

// Function to add a new product
void addProduct(Product* products, int* numProducts) {
  // Prompt user for product details
  printf("Enter product name: ");
  scanf("%s", products[*numProducts].name);
  printf("Enter product price: ");
  scanf("%d", &products[*numProducts].price);
  printf("Enter product quantity: ");
  scanf("%d", &products[*numProducts].quantity);

  // Increment the number of products
  (*numProducts)++;
}

// Function to add a new customer
void addCustomer(Customer* customers, int* numCustomers) {
  // Prompt user for customer details
  printf("Enter customer name: ");
  scanf("%s", customers[*numCustomers].name);
  printf("Enter customer age: ");
  scanf("%d", &customers[*numCustomers].age);
  printf("Enter customer address: ");
  scanf("%s", customers[*numCustomers].address);

  // Increment the number of customers
  (*numCustomers)++;
}

// Function to process a customer order
void processOrder(Product* products, int numProducts, Customer* customers, int numCustomers) {
  // Prompt user for customer name
  printf("Enter customer name: ");
  char customerName[50];
  scanf("%s", customerName);

  // Find the customer index
  int customerIndex = -1;
  for (int i = 0; i < numCustomers; i++) {
    if (strcmp(customerName, customers[i].name) == 0) {
      customerIndex = i;
      break;
    }
  }

  // Check if customer was found
  if (customerIndex == -1) {
    printf("Customer not found.\n");
    return;
  }

  // Prompt user for product name
  printf("Enter product name: ");
  char productName[50];
  scanf("%s", productName);

  // Find the product index
  int productIndex = -1;
  for (int i = 0; i < numProducts; i++) {
    if (strcmp(productName, products[i].name) == 0) {
      productIndex = i;
      break;
    }
  }

  // Check if product was found
  if (productIndex == -1) {
    printf("Product not found.\n");
    return;
  }

  // Check if the customer can afford the product
  if (customers[customerIndex].age < 18 && products[productIndex].price > 10) {
    printf("Product cannot be purchased by customer.\n");
    return;
  }

  // Update the product quantity
  products[productIndex].quantity--;

  // Print the order details
  printf("Customer: %s\n", customers[customerIndex].name);
  printf("Product: %s\n", products[productIndex].name);
  printf("Price: %d\n", products[productIndex].price);
}

int main() {
  // Initialize the product array
  Product products[100];
  int numProducts = 0;

  // Initialize the customer array
  Customer customers[100];
  int numCustomers = 0;

  // Add some initial products
  addProduct(products, &numProducts);
  addProduct(products, &numProducts);
  addProduct(products, &numProducts);

  // Add some initial customers
  addCustomer(customers, &numCustomers);
  addCustomer(customers, &numCustomers);
  addCustomer(customers, &numCustomers);

  // Process some orders
  processOrder(products, numProducts, customers, numCustomers);
  processOrder(products, numProducts, customers, numCustomers);
  processOrder(products, numProducts, customers, numCustomers);

  // Print the final inventory
  printf("Final Inventory:\n");
  for (int i = 0; i < numProducts; i++) {
    printf("%s: %d\n", products[i].name, products[i].quantity);
  }

  return 0;
}