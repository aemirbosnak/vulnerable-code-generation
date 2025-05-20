//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct Product {
  int id;
  char name[50];
  float price;
  int quantity;
} Product;

// Customer structure
typedef struct Customer {
  int id;
  char name[50];
  char address[100];
  char phone[20];
  float balance;
} Customer;

// Order structure
typedef struct Order {
  int id;
  int customer_id;
  int product_id;
  int quantity;
  float total_price;
} Order;

// Global variables
Product products[100];
Customer customers[100];
Order orders[100];
int num_products = 0;
int num_customers = 0;
int num_orders = 0;

// Function to add a product
void add_product() {
  printf("Enter product ID: ");
  scanf("%d", &products[num_products].id);
  printf("Enter product name: ");
  scanf("%s", products[num_products].name);
  printf("Enter product price: ");
  scanf("%f", &products[num_products].price);
  printf("Enter product quantity: ");
  scanf("%d", &products[num_products].quantity);
  num_products++;
}

// Function to add a customer
void add_customer() {
  printf("Enter customer ID: ");
  scanf("%d", &customers[num_customers].id);
  printf("Enter customer name: ");
  scanf("%s", customers[num_customers].name);
  printf("Enter customer address: ");
  scanf("%s", customers[num_customers].address);
  printf("Enter customer phone: ");
  scanf("%s", customers[num_customers].phone);
  printf("Enter customer balance: ");
  scanf("%f", &customers[num_customers].balance);
  num_customers++;
}

// Function to place an order
void place_order() {
  int customer_id, product_id, quantity;
  float total_price;

  printf("Enter customer ID: ");
  scanf("%d", &customer_id);
  printf("Enter product ID: ");
  scanf("%d", &product_id);
  printf("Enter quantity: ");
  scanf("%d", &quantity);

  // Check if customer exists
  int customer_found = 0;
  for (int i = 0; i < num_customers; i++) {
    if (customers[i].id == customer_id) {
      customer_found = 1;
      break;
    }
  }

  // Check if product exists
  int product_found = 0;
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == product_id) {
      product_found = 1;
      break;
    }
  }

  // If both customer and product exist, place the order
  if (customer_found && product_found) {
    // Check if product has enough quantity
    if (products[product_id - 1].quantity >= quantity) {
      // Calculate total price
      total_price = products[product_id - 1].price * quantity;

      // Deduct quantity from product
      products[product_id - 1].quantity -= quantity;

      // Add order to orders array
      orders[num_orders].id = num_orders + 1;
      orders[num_orders].customer_id = customer_id;
      orders[num_orders].product_id = product_id;
      orders[num_orders].quantity = quantity;
      orders[num_orders].total_price = total_price;
      num_orders++;

      // Print order details
      printf("Order placed successfully!\n");
      printf("Order ID: %d\n", orders[num_orders - 1].id);
      printf("Customer ID: %d\n", orders[num_orders - 1].customer_id);
      printf("Product ID: %d\n", orders[num_orders - 1].product_id);
      printf("Quantity: %d\n", orders[num_orders - 1].quantity);
      printf("Total Price: %.2f\n", orders[num_orders - 1].total_price);
    } else {
      printf("Sorry, not enough quantity available!\n");
    }
  } else {
    printf("Sorry, customer or product not found!\n");
  }
}

// Function to display all products
void display_products() {
  printf("Products:\n");
  printf("| ID | Name | Price | Quantity |\n");
  for (int i = 0; i < num_products; i++) {
    printf("| %d | %s | %.2f | %d |\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
  }
}

// Function to display all customers
void display_customers() {
  printf("Customers:\n");
  printf("| ID | Name | Address | Phone | Balance |\n");
  for (int i = 0; i < num_customers; i++) {
    printf("| %d | %s | %s | %s | %.2f |\n", customers[i].id, customers[i].name, customers[i].address, customers[i].phone, customers[i].balance);
  }
}

// Function to display all orders
void display_orders() {
  printf("Orders:\n");
  printf("| ID | Customer ID | Product ID | Quantity | Total Price |\n");
  for (int i = 0; i < num_orders; i++) {
    printf("| %d | %d | %d | %d | %.2f |\n", orders[i].id, orders[i].customer_id, orders[i].product_id, orders[i].quantity, orders[i].total_price);
  }
}

// Main function
int main() {
  // Add some sample data
  add_product();
  add_product();
  add_product();
  add_customer();
  add_customer();

  // Place an order
  place_order();

  // Display all products
  display_products();

  // Display all customers
  display_customers();

  // Display all orders
  display_orders();

  return 0;
}