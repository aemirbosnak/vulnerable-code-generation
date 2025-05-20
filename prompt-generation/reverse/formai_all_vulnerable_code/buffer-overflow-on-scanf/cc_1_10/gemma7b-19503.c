//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_Stocks 10

typedef struct Stock {
  char name[20];
  double price;
  int quantity;
} Stock;

void updateStock(Stock *stock) {
  printf("Enter the new price of %s: ", stock->name);
  scanf("%lf", &stock->price);
  printf("Enter the new quantity of %s: ", stock->name);
  scanf("%d", &stock->quantity);
}

int main() {
  Stock stocks[MAX_Stocks];
  for (int i = 0; i < MAX_Stocks; i++) {
    stocks[i].name[0] = '\0';
    stocks[i].price = 0.0;
    stocks[i].quantity = 0;
  }

  int numStocks = 0;

  while (1) {
    system("clear");
    printf("Stock Market Tracker\n");
    printf("------------------------\n");

    for (int i = 0; i < numStocks; i++) {
      if (stocks[i].name[0] != '\0') {
        printf("%s: $%.2lf, Quantity: %d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
      }
    }

    printf("\nEnter the name of the stock to update: ");
    char stockName[20];
    scanf("%s", stockName);

    for (int i = 0; i < numStocks; i++) {
      if (strcmp(stocks[i].name, stockName) == 0) {
        updateStock(&stocks[i]);
      }
    }

    printf("Press 'q' to quit: ");
    char quit;
    scanf("%c", &quit);

    if (quit == 'q') {
      break;
    }

    sleep(1);
  }

  return 0;
}