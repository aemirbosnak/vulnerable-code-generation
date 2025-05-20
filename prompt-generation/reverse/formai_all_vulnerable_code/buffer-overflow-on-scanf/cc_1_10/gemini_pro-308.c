//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 10

// Define the structure of a stock
typedef struct {
  char symbol[10];       // The stock symbol (e.g., "AAPL")
  double price;          // The current stock price
  double change;         // The change in stock price since the previous day
  double percent_change; // The percentage change in stock price since the previous day
} Stock;

// Define the function to print the stock information
void print_stock(Stock stock) {
  printf("%s: $%.2f (%.2f%%)\n", stock.symbol, stock.price, stock.percent_change);
}

// Define the function to track the stock market
void track_stock_market() {
  // Initialize the array of stocks
  Stock stocks[MAX_STOCKS];

  // Get the user input
  printf("Enter the stock symbol (or 'quit' to exit): ");
  scanf("%s", stocks[0].symbol);

  // Loop until the user enters 'quit'
  while (strcmp(stocks[0].symbol, "quit") != 0) {
    // Get the stock price
    printf("Enter the stock price: ");
    scanf("%lf", &stocks[0].price);

    // Calculate the change and percent change
    stocks[0].change = stocks[0].price - stocks[0].price;
    stocks[0].percent_change = (stocks[0].change / stocks[0].price) * 100.0;

    // Print the stock information
    print_stock(stocks[0]);

    // Get the next stock symbol
    printf("Enter the next stock symbol (or 'quit' to exit): ");
    scanf("%s", stocks[0].symbol);
  }
}

// This is the main function
int main() {
  // Track the stock market
  track_stock_market();

  return 0;
}