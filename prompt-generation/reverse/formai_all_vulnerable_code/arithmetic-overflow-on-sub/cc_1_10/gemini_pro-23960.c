//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menu_items[10][20] = {"Coffee", "Tea", "Soda", "Sandwich", "Salad", "Soup", "Cookie", "Brownie", "Muffin", "Fruit"};
double menu_prices[10] = {1.99, 1.50, 1.25, 4.99, 5.99, 3.99, 1.00, 2.00, 1.50, 2.50};

// Define the tax rate
double tax_rate = 0.08;

// Get the number of customers
int get_num_customers() {
  int num_customers;
  printf("Enter the number of customers: ");
  scanf("%d", &num_customers);
  return num_customers;
}

// Get the order for a customer
void get_order(int customer_num, double *subtotal, double *tax, double *total) {
  int num_items;
  printf("Enter the number of items for customer %d: ", customer_num);
  scanf("%d", &num_items);

  // Get the items and quantities ordered
  int quantities[10] = {0};
  for (int i = 0; i < num_items; i++) {
    int item_num;
    int quantity;
    printf("Enter the item number and quantity for item %d: ", i + 1);
    scanf("%d %d", &item_num, &quantity);
    quantities[item_num - 1] = quantity;
  }

  // Calculate the subtotal
  *subtotal = 0.0;
  for (int i = 0; i < 10; i++) {
    *subtotal += menu_prices[i] * quantities[i];
  }

  // Calculate the tax
  *tax = *subtotal * tax_rate;

  // Calculate the total
  *total = *subtotal + *tax;
}

// Print the bill
void print_bill(int customer_num, double subtotal, double tax, double total) {
  printf("Customer %d\n", customer_num);
  printf("Subtotal: $%.2f\n", subtotal);
  printf("Tax: $%.2f\n", tax);
  printf("Total: $%.2f\n\n", total);
}

// Main function
int main() {
  // Get the number of customers
  int num_customers = get_num_customers();

  // Get the order for each customer
  double subtotals[num_customers];
  double taxes[num_customers];
  double totals[num_customers];
  for (int i = 0; i < num_customers; i++) {
    get_order(i + 1, &subtotals[i], &taxes[i], &totals[i]);
  }

  // Print the bill for each customer
  for (int i = 0; i < num_customers; i++) {
    print_bill(i + 1, subtotals[i], taxes[i], totals[i]);
  }

  return 0;
}