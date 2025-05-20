//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
const float PRICE_TEA = 1.50;
const float PRICE_COFFEE = 2.00;
const float PRICE_SANDWICH = 3.50;
const float PRICE_CAKE = 2.50;

// Define the tax rate
const float TAX_RATE = 0.10;

int main() {
  // Declare variables
  int tea_qty = 0, coffee_qty = 0, sandwich_qty = 0, cake_qty = 0;
  float subtotal = 0.0, tax = 0.0, total = 0.0;

  // Display the menu
  printf("Welcome to our cafe! Here is our menu:\n");
  printf("1. Tea ($%.2f)\n", PRICE_TEA);
  printf("2. Coffee ($%.2f)\n", PRICE_COFFEE);
  printf("3. Sandwich ($%.2f)\n", PRICE_SANDWICH);
  printf("4. Cake ($%.2f)\n", PRICE_CAKE);

  // Get the quantity of each item from the user
  printf("How many teas would you like to order? ");
  scanf("%d", &tea_qty);

  printf("How many coffees would you like to order? ");
  scanf("%d", &coffee_qty);

  printf("How many sandwiches would you like to order? ");
  scanf("%d", &sandwich_qty);

  printf("How many cakes would you like to order? ");
  scanf("%d", &cake_qty);

  // Calculate the subtotal
  subtotal = tea_qty * PRICE_TEA + coffee_qty * PRICE_COFFEE +
             sandwich_qty * PRICE_SANDWICH + cake_qty * PRICE_CAKE;

  // Calculate the tax
  tax = subtotal * TAX_RATE;

  // Calculate the total
  total = subtotal + tax;

  // Display the receipt
  printf("\n\n");
  printf("========== RECEIPT ==========\n");
  printf("ITEM\t\tQUANTITY\tPRICE\n");
  printf("--------------------------------\n");
  if (tea_qty > 0) {
    printf("Tea\t\t%d\t\t$%.2f\n", tea_qty, tea_qty * PRICE_TEA);
  }
  if (coffee_qty > 0) {
    printf("Coffee\t\t%d\t\t$%.2f\n", coffee_qty, coffee_qty * PRICE_COFFEE);
  }
  if (sandwich_qty > 0) {
    printf("Sandwich\t%d\t\t$%.2f\n", sandwich_qty, sandwich_qty * PRICE_SANDWICH);
  }
  if (cake_qty > 0) {
    printf("Cake\t\t%d\t\t$%.2f\n", cake_qty, cake_qty * PRICE_CAKE);
  }
  printf("--------------------------------\n");
  printf("\t\t\tSUBTOTAL: $%.2f\n", subtotal);
  printf("\t\t\tTAX: $%.2f\n", tax);
  printf("\t\t\tTOTAL: $%.2f\n", total);

  return 0;
}