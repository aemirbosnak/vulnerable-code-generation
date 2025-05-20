//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 10

// Define the structure of a stock
typedef struct {
  char symbol[10];
  double price;
  double change;
} Stock;

// Define the array of stocks
Stock stocks[MAX_STOCKS];

// Get the stock data from a file
void getStockData(char *filename) {
  FILE *fp;
  int i;

  // Open the file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read the stock data from the file
  for (i = 0; i < MAX_STOCKS; i++) {
    fscanf(fp, "%s %lf %lf", stocks[i].symbol, &stocks[i].price, &stocks[i].change);
  }

  // Close the file
  fclose(fp);
}

// Print the stock data to the console
void printStockData() {
  int i;

  // Print the header
  printf("%-10s %-10s %-10s\n", "Symbol", "Price", "Change");

  // Print the stock data
  for (i = 0; i < MAX_STOCKS; i++) {
    printf("%-10s $%-10.2f %-10.2f\n", stocks[i].symbol, stocks[i].price, stocks[i].change);
  }
}

// Get the user input
void getUserInput(char *input) {
  printf("Enter a stock symbol: ");
  scanf("%s", input);
}

// Find the stock by symbol
Stock *findStockBySymbol(char *symbol) {
  int i;

  // Search for the stock by symbol
  for (i = 0; i < MAX_STOCKS; i++) {
    if (strcmp(stocks[i].symbol, symbol) == 0) {
      return &stocks[i];
    }
  }

  // Stock not found
  return NULL;
}

// Update the stock price
void updateStockPrice(Stock *stock, double price) {
  stock->price = price;
}

// Update the stock change
void updateStockChange(Stock *stock, double change) {
  stock->change = change;
}

// Main function
int main() {
  char input[10];
  Stock *stock;
  double price, change;

  // Get the stock data from a file
  getStockData("stocks.txt");

  // Print the stock data to the console
  printStockData();

  // Get the user input
  getUserInput(input);

  // Find the stock by symbol
  stock = findStockBySymbol(input);

  // If the stock was found, update the price and change
  if (stock != NULL) {
    printf("Enter the new price: ");
    scanf("%lf", &price);
    updateStockPrice(stock, price);

    printf("Enter the new change: ");
    scanf("%lf", &change);
    updateStockChange(stock, change);

    // Print the updated stock data
    printf("\nUpdated stock data:\n");
    printStockData();
  } else {
    printf("Stock not found.\n");
  }

  return 0;
}