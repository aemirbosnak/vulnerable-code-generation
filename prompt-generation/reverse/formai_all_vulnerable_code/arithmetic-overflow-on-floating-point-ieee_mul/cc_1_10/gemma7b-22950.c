//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_Stocks 10

typedef struct Stock {
  char name[20];
  double current_price;
  double previous_price;
  double change;
  double change_percentage;
} Stock;

void initialize_stocks(Stock *stocks) {
  for (int i = 0; i < MAX_Stocks; i++) {
    stocks[i].name[0] = '\0';
    stocks[i].current_price = 0.0;
    stocks[i].previous_price = 0.0;
    stocks[i].change = 0.0;
    stocks[i].change_percentage = 0.0;
  }
}

void update_stocks(Stock *stocks) {
  for (int i = 0; i < MAX_Stocks; i++) {
    printf("Enter the current price for %s: ", stocks[i].name);
    scanf("%lf", &stocks[i].current_price);

    if (stocks[i].previous_price == 0.0) {
      stocks[i].previous_price = stocks[i].current_price;
    }

    stocks[i].change = stocks[i].current_price - stocks[i].previous_price;
    stocks[i].change_percentage = (stocks[i].change / stocks[i].previous_price) * 100.0;
  }
}

void display_stocks(Stock *stocks) {
  for (int i = 0; i < MAX_Stocks; i++) {
    printf("%s: $%.2lf, Change: $%.2lf, Change Percentage: %.2lf%%\n", stocks[i].name, stocks[i].current_price, stocks[i].change, stocks[i].change_percentage);
  }
}

int main() {
  Stock stocks[MAX_Stocks];
  initialize_stocks(stocks);

  update_stocks(stocks);

  display_stocks(stocks);

  return 0;
}