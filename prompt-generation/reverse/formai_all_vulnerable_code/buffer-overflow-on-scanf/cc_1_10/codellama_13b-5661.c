//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: random
// Database Simulation Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 100
#define MAX_CREDIT_CARDS 5

// Structures
typedef struct {
  char name[MAX_NAME_LENGTH];
  int age;
  int credit_cards[MAX_CREDIT_CARDS];
} Customer;

typedef struct {
  char name[MAX_NAME_LENGTH];
  int price;
  int quantity;
} Product;

// Functions
void add_customer(Customer *customers, int *num_customers) {
  // Ask for customer details
  printf("Enter customer name: ");
  scanf("%s", customers[*num_customers].name);
  printf("Enter customer age: ");
  scanf("%d", &customers[*num_customers].age);
  printf("Enter number of credit cards: ");
  scanf("%d", &customers[*num_customers].credit_cards);

  // Generate credit card numbers
  for (int i = 0; i < customers[*num_customers].credit_cards; i++) {
    customers[*num_customers].credit_cards[i] = rand() % 10000000000000000;
  }

  // Increment number of customers
  (*num_customers)++;
}

void add_product(Product *products, int *num_products) {
  // Ask for product details
  printf("Enter product name: ");
  scanf("%s", products[*num_products].name);
  printf("Enter product price: ");
  scanf("%d", &products[*num_products].price);
  printf("Enter product quantity: ");
  scanf("%d", &products[*num_products].quantity);

  // Increment number of products
  (*num_products)++;
}

void purchase_product(Customer *customers, int num_customers, Product *products, int num_products) {
  // Ask for customer and product details
  int customer_index, product_index;
  printf("Enter customer name: ");
  scanf("%s", customers[customer_index].name);
  printf("Enter product name: ");
  scanf("%s", products[product_index].name);

  // Check if customer has enough credit
  if (customers[customer_index].credit_cards[0] < products[product_index].price) {
    printf("Insufficient credit.\n");
    return;
  }

  // Decrement product quantity
  products[product_index].quantity--;

  // Deduct from customer credit
  customers[customer_index].credit_cards[0] -= products[product_index].price;

  // Print receipt
  printf("Customer %s purchased product %s for %d.\n", customers[customer_index].name, products[product_index].name, products[product_index].price);
}

// Main function
int main() {
  // Initialize customers and products
  Customer customers[100];
  int num_customers = 0;
  Product products[100];
  int num_products = 0;

  // Add customers and products
  for (int i = 0; i < 10; i++) {
    add_customer(customers, &num_customers);
    add_product(products, &num_products);
  }

  // Purchase products
  for (int i = 0; i < 10; i++) {
    purchase_product(customers, num_customers, products, num_products);
  }

  // Print customers and products
  printf("Customers:\n");
  for (int i = 0; i < num_customers; i++) {
    printf("%s (%d) - %d credit card(s)\n", customers[i].name, customers[i].age, customers[i].credit_cards);
  }
  printf("Products:\n");
  for (int i = 0; i < num_products; i++) {
    printf("%s - %d units available\n", products[i].name, products[i].quantity);
  }

  return 0;
}