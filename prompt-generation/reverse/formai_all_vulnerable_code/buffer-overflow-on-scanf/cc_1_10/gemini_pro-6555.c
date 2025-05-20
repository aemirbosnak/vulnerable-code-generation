//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the menu items
#define COFFEE 1
#define TEA 2
#define CAKE 3

// Define the prices
#define COFFEE_PRICE 10
#define TEA_PRICE 5
#define CAKE_PRICE 15

// Function to display the menu
void displayMenu() {
  printf("Welcome to the Cafe!\n");
  printf("---------------------\n");
  printf("1. Coffee - $10\n");
  printf("2. Tea - $5\n");
  printf("3. Cake - $15\n");
  printf("---------------------\n");
}

// Function to get the user's order
int getOrder() {
  int order;
  printf("What would you like to order? (1-3): ");
  scanf("%d", &order);
  return order;
}

// Function to calculate the total bill
float calculateBill(int order) {
  float total = 0;
  switch (order) {
    case COFFEE:
      total = COFFEE_PRICE;
      break;
    case TEA:
      total = TEA_PRICE;
      break;
    case CAKE:
      total = CAKE_PRICE;
      break;
    default:
      printf("Invalid order! Please try again.\n");
      break;
  }
  return total;
}

// Function to print the bill
void printBill(float total) {
  printf("Your total bill is: $%.2f\n", total);
  printf("---------------------\n");
  printf("Thank you for coming!\n");
}

// Main function
int main() {
  // Display the menu
  displayMenu();

  // Get the user's order
  int order = getOrder();

  // Calculate the total bill
  float total = calculateBill(order);

  // Print the bill
  printBill(total);

  return 0;
}