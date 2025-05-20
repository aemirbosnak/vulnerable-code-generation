//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate bill amount
float calculateBill(int quantity, float price) {
  return quantity * price;
}

int main() {
  // Initialize variables
  int choice, quantity, count;
  float price, total, discountAmount, discount, taxAmount, grandTotal;
  char itemName[20];

  // Display menu
  printf("Welcome to C Cafe\n");
  printf("----------------\n");
  printf("1. Tea - $1.50\n");
  printf("2. Coffee - $2.00\n");
  printf("3. Sandwich - $3.50\n");
  printf("4. Salad - $4.00\n");
  printf("5. Exit\n");

  // Get user's choice
  printf("\nEnter your choice: ");
  scanf("%d", &choice);

  // Initialize variables based on user's choice
  switch(choice) {
    case 1:
      strcpy(itemName, "Tea");
      price = 1.5;
      break;
    case 2:
      strcpy(itemName, "Coffee");
      price = 2;
      break;
    case 3:
      strcpy(itemName, "Sandwich");
      price = 3.5;
      break;
    case 4:
      strcpy(itemName, "Salad");
      price = 4;
      break;
    default:
      printf("Thank you for visiting C Cafe! Come back soon.\n");
      return 0;
  }

  // Get user's quantity
  printf("Enter the quantity: ");
  scanf("%d", &quantity);

  // Calculate bill amount
  total = calculateBill(quantity, price);

  // Determine if discount applies
  if (total >= 10 && total < 20) {
    discount = 0.05;
  } else if (total >= 20) {
    discount = 0.1;
  }

  // Calculate discount amount
  discountAmount = total * discount;

  // Calculate tax amount
  taxAmount = total * 0.1;

  // Calculate grand total
  grandTotal = total - discountAmount + taxAmount;

  // Print receipt
  printf("\n------------------------\n");
  printf("C Cafe Billing System\n");
  printf("------------------------\n");
  printf("Item: %s\n", itemName);
  printf("Quantity: %d\n", quantity);
  printf("Price: %.2f\n", price);
  printf("Total Amount: %.2f\n\n", total);
  printf("Discount: %.0f%%\n", discount * 100);
  printf("Discount Amount: %.2f\n\n", discountAmount);
  printf("Tax: 10%%\n");
  printf("Tax Amount: %.2f\n\n", taxAmount);
  printf("Grand Total: %.2f\n", grandTotal);
  printf("------------------------\n");
  printf("Thank you for visiting C Cafe! Come back soon.\n");

  return 0;
}