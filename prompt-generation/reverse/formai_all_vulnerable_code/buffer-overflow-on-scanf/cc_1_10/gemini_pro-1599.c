//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define the stock structure
typedef struct {
  char *name;
  double price;
  double change;
} Stock;

// Print the stock information
void printStock(Stock stock) {
  printf("%s: $%.2f (%.2f%%)\n", stock.name, stock.price, stock.change);
}

// Get the stock data from the user
Stock getStockData(void) {
  Stock stock;
  printf("Enter the stock name: ");
  scanf(" %s", stock.name);
  printf("Enter the stock price: ");
  scanf(" %lf", &stock.price);
  printf("Enter the stock change: ");
  scanf(" %lf", &stock.change);
  return stock;
}

// Main function
int main(void) {
  // Welcome the user
  printf("Welcome to the Stock Market Tracker!\n");

  // Get the stock data from the user
  Stock stock = getStockData();

  // Print the stock information
  printf("\nHere is the stock information you entered:\n");
  printStock(stock);

  // Calculate the percentage change
  double percentageChange = stock.change / stock.price * 100;

  // Print the percentage change
  printf("\nThe percentage change is: %.2f%%\n", percentageChange);

  // Determine if the stock is up or down
  if (stock.change > 0) {
    printf("The stock is up!\n");
  } else if (stock.change < 0) {
    printf("The stock is down!\n");
  } else {
    printf("The stock is unchanged.\n");
  }

  // Thank the user
  printf("\nThank you for using the Stock Market Tracker!\n");

  return 0;
}