//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_STOCK_NUM 10
#define UPDATE_INTERVAL 5

struct Stock {
  char name[20];
  double currentPrice;
  double previousPrice;
  double change;
  double changePercent;
};

void updateStock(struct Stock *stock) {
  // Simulate getting the latest price
  stock->currentPrice = rand() % 1000;

  // Calculate the change and change percent
  stock->change = stock->currentPrice - stock->previousPrice;
  stock->changePercent = (stock->change / stock->previousPrice) * 100;

  // Update the previous price
  stock->previousPrice = stock->currentPrice;
}

int main() {
  struct Stock stocks[MAX_STOCK_NUM];

  // Initialize the stocks
  for (int i = 0; i < MAX_STOCK_NUM; i++) {
    stocks[i].name[0] = '\0';
    stocks[i].currentPrice = 0.0;
    stocks[i].previousPrice = 0.0;
    stocks[i].change = 0.0;
    stocks[i].changePercent = 0.0;
  }

  // Update the stock prices
  updateStock(stocks);

  // Print the stock information
  for (int i = 0; i < MAX_STOCK_NUM; i++) {
    printf("%s: %f, %f, %f, %f%% \n", stocks[i].name, stocks[i].currentPrice, stocks[i].previousPrice, stocks[i].change, stocks[i].changePercent);
  }

  // Sleep for a while
  sleep(UPDATE_INTERVAL);

  return 0;
}