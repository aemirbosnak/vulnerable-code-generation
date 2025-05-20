//FormAI DATASET v1.0 Category: Stock market tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 10

typedef struct {
  char name[MAX_NAME_LENGTH];
  float price;
  float change;
} stock;

void printStocks(stock stocks[], int numStocks) {
  printf("Stocks Available:\n");
  printf("-----------------\n");
  for(int i = 0; i < numStocks; i++) {
    printf("%s\tPrice: $%.2f\tChange: %.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
  }
}

int main() {
  stock stocks[MAX_STOCKS];
  int numStocks = 0;
  char name[MAX_NAME_LENGTH];
  float price = 0;
  float change = 0;

  printf("Welcome to the Stock Market Tracker!\n\n");

  while(numStocks < MAX_STOCKS) {
    printf("Enter the name of a stock (or 'done' to finish): ");
    scanf("%s", name);

    if(strcmp(name, "done") == 0) {
      break;
    }

    printf("Enter the current price of %s: $", name);
    scanf("%f", &price);

    printf("Enter the percent change of %s (e.g. 5.2 or -2.5): ", name);
    scanf("%f", &change);

    strcpy(stocks[numStocks].name, name);
    stocks[numStocks].price = price;
    stocks[numStocks].change = change;
    numStocks++;

    printf("\n");
  }

  printf("\n");
  printStocks(stocks, numStocks);
  
  return 0;
}