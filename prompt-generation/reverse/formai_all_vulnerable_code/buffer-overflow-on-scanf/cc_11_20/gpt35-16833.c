//FormAI DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 100 // Maximum number of stocks to track
#define MAX_NAME_LENGTH 20 // Maximum length for stock name
#define MAX_HISTORY_DAYS 30 // Maximum number of days to keep track of history

typedef struct {
  char name[MAX_NAME_LENGTH];
  float price;
} Stock;

typedef struct {
  float prices[MAX_HISTORY_DAYS];
  int count;
} PriceHistory;

int main() {
  Stock stocks[MAX_STOCKS];
  PriceHistory histories[MAX_STOCKS];
  int stock_count = 0;

  printf("Welcome to the Stock Market Tracker!\n\n");

  // Loop to add stocks
  char answer = 'y';
  while (answer == 'y') {
    if (stock_count >= MAX_STOCKS) {
      printf("Maximum number of stocks reached (%d)\n", MAX_STOCKS);
      break;
    }

    Stock new_stock;
    printf("Enter the name of the stock: ");
    scanf("%s", new_stock.name);
    printf("Enter the current price of the stock: ");
    scanf("%f", &new_stock.price);

    stocks[stock_count] = new_stock;
    histories[stock_count].count = 0; // Initialize history for new stock
    stock_count++;

    printf("Do you want to add another stock? (y/n): ");
    scanf(" %c", &answer);
  }

  // Loop to show stock prices and track history
  while (1) {
    printf("\nCurrent stock prices:\n");

    for (int i = 0; i < stock_count; i++) {
      printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);

      // Add current price to history for this stock
      PriceHistory *history = &histories[i];
      if (history->count < MAX_HISTORY_DAYS) {
        history->prices[history->count] = stocks[i].price;
        history->count++;
      }
      else {
        // Shift all prices to the left and add new price at the end
        for (int j = 1; j < MAX_HISTORY_DAYS; j++) {
          history->prices[j - 1] = history->prices[j];
        }
        history->prices[MAX_HISTORY_DAYS - 1] = stocks[i].price;
      }
    }

    // Ask user if they want to quit or continue
    printf("\nDo you want to exit? (y/n): ");
    scanf(" %c", &answer);
    if (answer == 'y') {
      break;
    }
    else if (answer != 'n') {
      printf("Invalid input. Continuing...\n");
    }
  }

  // Show history for each stock
  printf("\nStock price history:\n");
  for (int i = 0; i < stock_count; i++) {
    printf("%s:\n", stocks[i].name);
    for (int j = 0; j < histories[i].count; j++) {
      printf("$%.2f ", histories[i].prices[j]);
    }
    printf("\n");
  }

  return 0;
}