//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char *menu_items[] = {"Espresso", "Americano", "Cappuccino", "Latte", "Mocha"};
float menu_prices[] = {2.50, 3.00, 3.50, 4.00, 4.50};

// Function to display the menu
void display_menu() {
  printf("Welcome to the C Cafe!\n\n");
  printf("Here's our menu:\n\n");
  for (int i = 0; i < 5; i++) {
    printf("%d. %s - $%.2f\n", i + 1, menu_items[i], menu_prices[i]);
  }
  printf("\n");
}

// Function to get the user's order
int get_order() {
  int order;
  printf("What would you like to order? (Enter the number of the item): ");
  scanf("%d", &order);
  return order;
}

// Function to calculate the total price of the order
float calculate_total(int order) {
  float total = menu_prices[order - 1];
  return total;
}

// Function to print the receipt
void print_receipt(int order, float total) {
  printf("\nYour order:\n\n");
  printf("%s - $%.2f\n", menu_items[order - 1], menu_prices[order - 1]);
  printf("\nTotal: $%.2f\n", total);
  printf("\nThank you for your order! Come again soon!\n");
}

// Main function
int main() {
  // Display the menu
  display_menu();

  // Get the user's order
  int order = get_order();

  // Calculate the total price of the order
  float total = calculate_total(order);

  // Print the receipt
  print_receipt(order, total);

  return 0;
}