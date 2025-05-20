//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Structure to store the order details
struct order {
  char item_name[50];
  int quantity;
  float price;
};

// Function to calculate the total bill amount
float calculate_bill(struct order *orders, int num_orders) {
  float total_amount = 0.0;
  for (int i = 0; i < num_orders; i++) {
    total_amount += orders[i].quantity * orders[i].price;
  }
  return total_amount;
}

// Function to print the bill
void print_bill(struct order *orders, int num_orders, float total_amount) {
  printf("\n\n=====================================");
  printf("\n             Cafe Billing System        ");
  printf("\n=====================================");
  printf("\n\nItem Name\tQuantity\tPrice");
  for (int i = 0; i < num_orders; i++) {
    printf("\n%-15s\t%-8d\t%-6.2f", orders[i].item_name, orders[i].quantity,
           orders[i].price);
  }
  printf("\n-------------------------------------");
  printf("\nTotal Amount:\t\t%-6.2f", total_amount);
  printf("\n\nThank you for your patronage!");
  printf("\n=====================================");
}

// Main function
int main() {
  // Declare the array of orders
  struct order orders[10];

  // Get the number of orders from the user
  int num_orders;
  printf("\nEnter the number of orders: ");
  scanf("%d", &num_orders);

  // Get the details of each order from the user
  for (int i = 0; i < num_orders; i++) {
    printf("\nEnter the item name for order %d: ", i + 1);
    scanf("%s", orders[i].item_name);
    printf("Enter the quantity for order %d: ", i + 1);
    scanf("%d", &orders[i].quantity);
    printf("Enter the price for order %d: ", i + 1);
    scanf("%f", &orders[i].price);
  }

  // Calculate the total bill amount
  float total_amount = calculate_bill(orders, num_orders);

  // Print the bill
  print_bill(orders, num_orders, total_amount);

  return 0;
}