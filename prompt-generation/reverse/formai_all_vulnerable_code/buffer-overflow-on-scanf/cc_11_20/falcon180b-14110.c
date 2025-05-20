//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
#include <stdio.h>

// Define the price of each item on the menu
#define COFFEE_PRICE 2.50
#define TEA_PRICE 1.75
#define PASTRIES_PRICE 3.00

// Define the tax rate
#define TAX_RATE 0.08

// Define the maximum number of items a customer can order
#define MAX_ITEMS 10

int main() {
   // Initialize variables
   double subtotal = 0.00;
   double tax = 0.00;
   double total = 0.00;
   int numItems = 0;

   // Display the menu
   printf("Welcome to the Ada Lovelace Cafe!\n");
   printf("Our menu includes:\n");
   printf("- Coffee: $%.2f\n", COFFEE_PRICE);
   printf("- Tea: $%.2f\n", TEA_PRICE);
   printf("- Pastries: $%.2f\n", PASTRIES_PRICE);

   // Take the customer's order
   printf("What would you like to order?\n");
   scanf("%d", &numItems);

   // Calculate the subtotal
   for (int i = 0; i < numItems; i++) {
      if (i == 0) {
         subtotal += COFFEE_PRICE;
      } else if (i == 1) {
         subtotal += TEA_PRICE;
      } else if (i >= 2 && i <= 5) {
         subtotal += PASTRIES_PRICE;
      } else {
         printf("Invalid item number.\n");
         return 1;
      }
   }

   // Calculate the tax
   tax = subtotal * TAX_RATE;

   // Calculate the total
   total = subtotal + tax;

   // Display the receipt
   printf("\nYour order:\n");
   for (int i = 0; i < numItems; i++) {
      if (i == 0) {
         printf("- Coffee: $%.2f\n", COFFEE_PRICE);
      } else if (i == 1) {
         printf("- Tea: $%.2f\n", TEA_PRICE);
      } else if (i >= 2 && i <= 5) {
         printf("- Pastries: $%.2f\n", PASTRIES_PRICE);
      }
   }
   printf("\nSubtotal: $%.2f\n", subtotal);
   printf("Tax: $%.2f\n", tax);
   printf("Total: $%.2f\n", total);

   return 0;
}