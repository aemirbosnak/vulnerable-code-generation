//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  float cappuccino_price = 2.50;
  float latte_price = 3.00;
  float iced_coffee_price = 2.75;
  float espresso_price = 2.00;
  int cappuccino_amount;
  int latte_amount;
  int iced_coffee_amount;
  int espresso_amount;
  float subtotal = 0.00;
  float tax = 0.00;
  float total = 0.00;

  // Welcome message
  printf("Welcome to the C Cafe!\n");
  
  // Ask for order
  printf("How many cappuccinos would you like?\n");
  scanf("%d", &cappuccino_amount);

  printf("How many lattes would you like?\n");
  scanf("%d", &latte_amount);

  printf("How many iced coffees would you like?\n");
  scanf("%d", &iced_coffee_amount);

  printf("How many espressos would you like?\n");
  scanf("%d", &espresso_amount);

  // Calculate subtotal
  subtotal += cappuccino_price * cappuccino_amount;
  subtotal += latte_price * latte_amount;
  subtotal += iced_coffee_price * iced_coffee_amount;
  subtotal += espresso_price * espresso_amount;

  // Calculate tax
  tax = subtotal * 0.07;

  // Calculate total
  total = subtotal + tax;

  // Print receipt
  printf("\n\nThank you for your order!\n");
  printf("Here is your receipt:\n");
  printf("Cappuccinos: %d x $%.2f = $%.2f\n", cappuccino_amount, cappuccino_price, cappuccino_price * cappuccino_amount);
  printf("Lattes: %d x $%.2f = $%.2f\n", latte_amount, latte_price, latte_price * latte_amount);
  printf("Iced Coffees: %d x $%.2f = $%.2f\n", iced_coffee_amount, iced_coffee_price, iced_coffee_price * iced_coffee_amount);
  printf("Espressos: %d x $%.2f = $%.2f\n", espresso_amount, espresso_price, espresso_price * espresso_amount);
  printf("\nSubtotal: $%.2f\n", subtotal);
  printf("Tax: $%.2f\n", tax);
  printf("Total: $%.2f\n", total);

  return 0;
}