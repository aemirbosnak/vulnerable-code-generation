//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menu[][20] = {"Coffee", "Tea", "Soda", "Water", "Muffin", "Cookie"};
float prices[] = {1.50, 1.00, 1.25, 0.75, 2.00, 1.00};

// Get the number of items ordered
int get_num_items() {
  int num_items;
  printf("How many items would you like to order? ");
  scanf("%d", &num_items);
  return num_items;
}

// Get the order from the customer
void get_order(int num_items, int order[]) {
  int i;
  printf("Please enter the numbers of the items you would like to order:\n");
  for (i = 0; i < num_items; i++) {
    printf("%d. %s: $%.2f\n", i + 1, menu[i], prices[i]);
    scanf("%d", &order[i]);
  }
}

// Calculate the total cost of the order
float calculate_total(int num_items, int order[]) {
  int i;
  float total = 0.0;
  for (i = 0; i < num_items; i++) {
    total += prices[order[i] - 1];
  }
  return total;
}

// Print the receipt
void print_receipt(int num_items, int order[], float total) {
  int i;
  printf("\nYour receipt:\n");
  for (i = 0; i < num_items; i++) {
    printf("%d. %s: $%.2f\n", i + 1, menu[order[i] - 1], prices[order[i] - 1]);
  }
  printf("Total: $%.2f\n", total);
}

// Main function
int main() {
  int num_items;
  int order[10];
  float total;

  // Get the number of items ordered
  num_items = get_num_items();

  // Get the order from the customer
  get_order(num_items, order);

  // Calculate the total cost of the order
  total = calculate_total(num_items, order);

  // Print the receipt
  print_receipt(num_items, order, total);

  return 0;
}