//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK_NUM 10

typedef struct Stock {
  char name[20];
  double currentPrice;
  double previousPrice;
  double change;
  double changePercentage;
} Stock;

Stock stocks[MAX_STOCK_NUM];

void initializeStocks() {
  for (int i = 0; i < MAX_STOCK_NUM; i++) {
    stocks[i].name[0] = '\0';
    stocks[i].currentPrice = 0.0;
    stocks[i].previousPrice = 0.0;
    stocks[i].change = 0.0;
    stocks[i].changePercentage = 0.0;
  }
}

void updateStockPrices() {
  // Simulate fetching stock prices
  for (int i = 0; i < MAX_STOCK_NUM; i++) {
    stocks[i].currentPrice = rand() % 1000;
  }
}

void calculateStockChanges() {
  for (int i = 0; i < MAX_STOCK_NUM; i++) {
    stocks[i].change = stocks[i].currentPrice - stocks[i].previousPrice;
    stocks[i].changePercentage = (stocks[i].change / stocks[i].previousPrice) * 100;
  }
}

void displayStockSummary() {
  for (int i = 0; i < MAX_STOCK_NUM; i++) {
    printf("%s: $%.2lf, %.2lf, %.2lf%% \n", stocks[i].name, stocks[i].currentPrice, stocks[i].previousPrice, stocks[i].changePercentage);
  }
}

int main() {
  initializeStocks();
  updateStockPrices();
  calculateStockChanges();
  displayStockSummary();

  return 0;
}