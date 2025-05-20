//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menu[][20] = {"Coffee", "Tea", "Cake", "Sandwich", "Juice"};
float prices[] = {1.50, 1.20, 2.00, 3.00, 1.80};

// Print the menu
void print_menu() {
  printf("Welcome to our cafe!\n\n");
  for (int i = 0; i < 5; i++) {
    printf("%d. %s - $%.2f\n", i + 1, menu[i], prices[i]);
  }
  printf("\n");
}

// Get the customer's order
void get_order(int *order, int *quantity) {
  int choice;
  int qty;

  printf("Enter your choices (1-5): ");
  for (int i = 0; i < 5; i++) {
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 5) {
      printf("Quantity: ");
      scanf("%d", &qty);
      order[i] = choice;
      quantity[i] = qty;
    }
  }
}

// Calculate the total bill
float calculate_bill(int *order, int *quantity) {
  float total = 0.0;

  for (int i = 0; i < 5; i++) {
    total += prices[order[i] - 1] * quantity[i];
  }

  return total;
}

// Print the receipt
void print_receipt(int *order, int *quantity, float total) {
  printf("\nYour receipt:\n");
  for (int i = 0; i < 5; i++) {
    if (quantity[i] > 0) {
      printf("%d. %s - %d x $%.2f = $%.2f\n", i + 1, menu[order[i] - 1], quantity[i], prices[order[i] - 1], prices[order[i] - 1] * quantity[i]);
    }
  }
  printf("\nTotal: $%.2f\n", total);
}

int main() {
  int order[5] = {0};
  int quantity[5] = {0};
  float total;

  // Print the menu
  print_menu();

  // Get the customer's order
  get_order(order, quantity);

  // Calculate the total bill
  total = calculate_bill(order, quantity);

  // Print the receipt
  print_receipt(order, quantity, total);

  return 0;
}