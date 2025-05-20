//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 20
#define MAX_VOLUME_LEN 20
#define MAX_CHANGE_LEN 20

typedef struct {
  char name[MAX_NAME_LEN];
  float price;
  int volume;
  float change;
} Stock;

void printStock(Stock stock) {
  printf("%-20s %-20.2f %-20d %+.2f\n", stock.name, stock.price, stock.volume, stock.change);
}

void updateStock(Stock *stock, float newPrice, int newVolume) {
  stock->price = newPrice;
  stock->volume = newVolume;
  stock->change = (newPrice - stock->price) / stock->price * 100;
}

int main() {
  Stock stocks[MAX_STOCKS];
  int numStocks = 0;
  char input[MAX_NAME_LEN];
  float price;
  int volume;

  while (1) {
    printf("Enter stock name (or 'quit' to exit): ");
    scanf("%s", input);

    if (strcmp(input, "quit") == 0) {
      break;
    }

    printf("Enter stock price: ");
    scanf("%f", &price);

    printf("Enter stock volume: ");
    scanf("%d", &volume);

    Stock stock;
    strcpy(stock.name, input);
    stock.price = price;
    stock.volume = volume;
    stock.change = 0;

    updateStock(&stock, price, volume);

    stocks[numStocks++] = stock;
  }

  printf("Stock Market Tracker\n");
  printf("-------------------\n");
  printf("%-20s %-20s %-20s %-20s\n", "Name", "Price", "Volume", "Change");

  for (int i = 0; i < numStocks; i++) {
    printStock(stocks[i]);
  }

  return 0;
}