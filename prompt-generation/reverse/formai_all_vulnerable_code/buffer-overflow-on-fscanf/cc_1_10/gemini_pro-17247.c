//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: excited
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
  double percent_change;
} stock_t;

// Define the function to get the stock data from a file
void get_stock_data(stock_t *stocks, int *num_stocks) {
  // Open the stock data file
  FILE *fp = fopen("stock_data.csv", "r");
  if (fp == NULL) {
    perror("Error opening stock data file");
    exit(EXIT_FAILURE);
  }

  // Read the number of stocks from the file
  fscanf(fp, "%d\n", num_stocks);

  // Read the stock data from the file
  for (int i = 0; i < *num_stocks; i++) {
    fscanf(fp, "%s,%lf,%lf,%lf\n", stocks[i].symbol, &stocks[i].price, &stocks[i].change, &stocks[i].percent_change);
  }

  // Close the stock data file
  fclose(fp);
}

// Define the function to print the stock data
void print_stock_data(stock_t *stocks, int num_stocks) {
  // Print the header
  printf("Symbol\tPrice\tChange\tPercent Change\n");

  // Print the stock data
  for (int i = 0; i < num_stocks; i++) {
    printf("%s\t%.2lf\t%.2lf\t%.2lf%%\n", stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percent_change);
  }
}

// Define the function to main
int main() {
  // Declare the array of stocks
  stock_t stocks[MAX_STOCKS];

  // Get the number of stocks
  int num_stocks;

  // Get the stock data
  get_stock_data(stocks, &num_stocks);

  // Print the stock data
  print_stock_data(stocks, num_stocks);

  return 0;
}