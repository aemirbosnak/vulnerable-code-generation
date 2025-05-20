//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int choice, item_no, quantity, total_amount = 0, i;

  // Menu Display
  printf("Welcome to the Coffee Cafe!\n");
  printf("Please select an item:\n");
  printf("1. Espresso\t\tPrice: $5.00\n");
  printf("2. Cappuccino\t\tPrice: $6.00\n");
  printf("3. Latte\t\tPrice: $7.00\n");
  printf("4. Mocha\t\tPrice: $8.00\n");

  // Item Selection
  scanf("Enter item number: ", &item_no);

  // Quantity Selection
  printf("Enter the quantity: ");
  scanf("%d", &quantity);

  // Item Cost Calculation
  switch (item_no)
  {
    case 1:
      total_amount += quantity * 5.00;
      break;
    case 2:
      total_amount += quantity * 6.00;
      break;
    case 3:
      total_amount += quantity * 7.00;
      break;
    case 4:
      total_amount += quantity * 8.00;
      break;
  }

  // Order Summary
  printf("Your order:\n");
  printf("Item: %d, Quantity: %d, Price: $%.2f\n", item_no, quantity, total_amount / quantity);

  // Total Cost Calculation
  total_amount = total_amount + total_amount * 10 / 100; // Tax

  // Payment and Receipt
  printf("Total amount: $%.2f\n", total_amount);
  printf("Please pay the amount.\n");
  printf("Thank you for your visit!\n");

  return 0;
}