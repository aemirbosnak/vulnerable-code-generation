//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Constant definitions for menu items
#define ITEM_1_PRICE 10.99
#define ITEM_2_PRICE 8.50
#define ITEM_3_PRICE 6.25
#define ITEM_4_PRICE 13.75
#define ITEM_5_PRICE 9.99

// Function to display menu
void displayMenu()
{
  printf("Welcome to Paranoid Cafe!\n");
  printf("----------------------------\n");
  printf("1. Croissant - $%.2f\n", ITEM_1_PRICE);
  printf("2. Coffee - $%.2f\n", ITEM_2_PRICE);
  printf("3. Tea - $%.2f\n", ITEM_3_PRICE);
  printf("4. Omelette - $%.2f\n", ITEM_4_PRICE);
  printf("5. Pancakes - $%.2f\n", ITEM_5_PRICE);
}

// Function to calculate total bill amount
float calculateTotal(int item, int quantity)
{
  float price;
  switch (item)
  {
    case 1:
      price = ITEM_1_PRICE;
      break;
    case 2:
      price = ITEM_2_PRICE;
      break;
    case 3:
      price = ITEM_3_PRICE;
      break;
    case 4:
      price = ITEM_4_PRICE;
      break;
    case 5:
      price = ITEM_5_PRICE;
      break;
    default:
      printf("Invalid item number!\n");
      return -1.0;
  }
  float total = price * quantity;
  return total;
}

// Main function
int main()
{
  // Declare variables
  int choice, quantity;
  float total, subtotal, tax, tip, grandTotal;
  
  // Greet the customer and display menu
  printf("Hello! Welcome to Paranoid Cafe.\n");
  displayMenu();
  
  // Get order details from customer
  printf("Please enter the item number you want to order: ");
  scanf("%d", &choice);
  printf("Please enter the quantity: ");
  scanf("%d", &quantity);
  
  // Calculate subtotal, tax, and tip
  subtotal = calculateTotal(choice, quantity);
  if (subtotal == -1.0)
  {
    printf("Exiting...\n");
    exit(0);
  }
  tax = subtotal * 0.06;
  printf("Do you want to add a tip? (Y/N) ");
  char response;
  scanf(" %c", &response);
  if (response == 'Y' || response == 'y')
  {
    printf("Enter tip amount (in percentage): ");
    int tipPercent;
    scanf("%d", &tipPercent);
    tip = subtotal * (tipPercent / 100.0);
  }
  else
  {
    tip = 0.0;
  }
  
  // Calculate grand total
  grandTotal = subtotal + tax + tip;
  
  // Display bill summary
  printf("\n\n");
  printf("Bill Summary\n");
  printf("------------\n");
  printf("Item ordered: %d\n", choice);
  printf("Quantity: %d\n", quantity);
  printf("Subtotal: $%.2f\n", subtotal);
  printf("Tax (6%%): $%.2f\n", tax);
  printf("Tip: $%.2f\n", tip);
  printf("Grand Total: $%.2f\n", grandTotal);
  printf("Thank you for your order. Please come again soon!\n");
  
  return 0;
}