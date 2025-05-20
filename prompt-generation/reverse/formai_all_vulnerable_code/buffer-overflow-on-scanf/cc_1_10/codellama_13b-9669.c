//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: real-life
// C Cafe Billing System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for storing customer information
typedef struct {
  char name[50];
  char address[100];
  char phone[15];
  int table_no;
  float total_cost;
} Customer;

// Function to print the menu
void print_menu(void) {
  printf("Welcome to our cafe!\n");
  printf("Here is our menu:\n");
  printf("1. Coffee - $2.50\n");
  printf("2. Tea - $2.00\n");
  printf("3. Sandwich - $5.00\n");
  printf("4. Soup - $3.50\n");
  printf("5. Dessert - $4.00\n");
}

// Function to calculate the total cost
float calculate_total_cost(float cost, int quantity) {
  return cost * quantity;
}

// Function to process the customer's order
void process_order(Customer *customer, int table_no) {
  // Print the menu
  print_menu();

  // Get the customer's order
  char order[100];
  printf("What would you like to order? ");
  scanf("%s", order);

  // Calculate the total cost
  float total_cost = 0.0;
  if (strcmp(order, "coffee") == 0) {
    total_cost = calculate_total_cost(2.50, 1);
  } else if (strcmp(order, "tea") == 0) {
    total_cost = calculate_total_cost(2.00, 1);
  } else if (strcmp(order, "sandwich") == 0) {
    total_cost = calculate_total_cost(5.00, 1);
  } else if (strcmp(order, "soup") == 0) {
    total_cost = calculate_total_cost(3.50, 1);
  } else if (strcmp(order, "dessert") == 0) {
    total_cost = calculate_total_cost(4.00, 1);
  }

  // Update the customer's information
  customer->table_no = table_no;
  customer->total_cost = total_cost;
}

// Function to print the bill
void print_bill(Customer *customer) {
  printf("Table #%d\n", customer->table_no);
  printf("Name: %s\n", customer->name);
  printf("Address: %s\n", customer->address);
  printf("Phone: %s\n", customer->phone);
  printf("Total cost: $%.2f\n", customer->total_cost);
}

// Function to take payments
void take_payment(Customer *customer) {
  float payment;
  printf("Please enter the payment: ");
  scanf("%f", &payment);

  // Update the customer's information
  customer->total_cost -= payment;
}

int main(void) {
  // Initialize the customer's information
  Customer customer = {"John Doe", "123 Main St", "555-555-5555", 1, 0.0};

  // Process the customer's order
  process_order(&customer, 1);

  // Print the bill
  print_bill(&customer);

  // Take payments
  take_payment(&customer);

  // Print the bill again
  print_bill(&customer);

  return 0;
}