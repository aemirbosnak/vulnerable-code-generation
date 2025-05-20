//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the menu items
#define ITEM_COFFEE 1
#define ITEM_LATTE 2
#define ITEM_CAPPUCCINO 3
#define ITEM_ESPRESSO 4

// Define the prices of the menu items
#define PRICE_COFFEE 2.5
#define PRICE_LATTE 3.5
#define PRICE_CAPPUCCINO 4.5
#define PRICE_ESPRESSO 3.0

// Define the tax rate
#define TAX_RATE 0.07

// Define the name of the cafe
#define CAFE_NAME "Cafe Java"

// Define the format of the receipt
#define RECEIPT_FORMAT "%-15s%-15s%-15s%-15s\n"

int main() {
  // Initialize the total cost of the order
  double total_cost = 0.0;

  // Print the header of the receipt
  printf("============================\n");
  printf("%-15s%-15s%-15s%-15s\n", "ITEM", "PRICE", "TAX", "TOTAL");
  printf("============================\n");

  // Take the order from the customer
  printf("Enter the item code: ");
  int item_code;
  scanf("%d", &item_code);

  // Calculate the price of the item
  double price;
  switch (item_code) {
    case ITEM_COFFEE:
      price = PRICE_COFFEE;
      break;
    case ITEM_LATTE:
      price = PRICE_LATTE;
      break;
    case ITEM_CAPPUCCINO:
      price = PRICE_CAPPUCCINO;
      break;
    case ITEM_ESPRESSO:
      price = PRICE_ESPRESSO;
      break;
    default:
      printf("Invalid item code\n");
      return 1;
  }

  // Calculate the tax
  double tax = price * TAX_RATE;

  // Calculate the total cost of the item
  double total_item_cost = price + tax;

  // Add the cost of the item to the total cost of the order
  total_cost += total_item_cost;

  // Print the receipt for the item
  printf(RECEIPT_FORMAT, CAFE_NAME, price, tax, total_item_cost);

  // Take another order from the customer
  printf("Enter another item code (0 to stop): ");
  scanf("%d", &item_code);

  // If the customer wants to order more items, calculate the price, tax, and total cost of the item and add it to the total cost of the order
  while (item_code != 0) {
    switch (item_code) {
      case ITEM_COFFEE:
        price = PRICE_COFFEE;
        break;
      case ITEM_LATTE:
        price = PRICE_LATTE;
        break;
      case ITEM_CAPPUCCINO:
        price = PRICE_CAPPUCCINO;
        break;
      case ITEM_ESPRESSO:
        price = PRICE_ESPRESSO;
        break;
      default:
        printf("Invalid item code\n");
        return 1;
    }

    tax = price * TAX_RATE;
    total_item_cost = price + tax;
    total_cost += total_item_cost;

    printf(RECEIPT_FORMAT, CAFE_NAME, price, tax, total_item_cost);

    printf("Enter another item code (0 to stop): ");
    scanf("%d", &item_code);
  }

  // Print the total cost of the order
  printf("============================\n");
  printf("%-15s%-15.2f\n", "Total:", total_cost);

  return 0;
}