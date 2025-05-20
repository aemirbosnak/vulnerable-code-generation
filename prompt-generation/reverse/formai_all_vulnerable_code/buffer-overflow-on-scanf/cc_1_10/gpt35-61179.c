//FormAI DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20

typedef struct {
  char name[MAX_NAME_LENGTH];
  float price;
  float change;
} Stock;

Stock portfolio[MAX_STOCKS];
int num_stocks;

void display_portfolio() {
  printf("\n\n");
  printf("| %-20s | %-10s | %-10s |\n", "Name", "Price", "Change");
  printf("+----------------------+------------+------------+\n");
  for (int i = 0; i < num_stocks; i++) {
    printf("| %-20s | %-10.2f | ", portfolio[i].name, portfolio[i].price);
    if (portfolio[i].change >= 0) {
      printf("+%-9.2f |\n", portfolio[i].change);
    } else {
      printf(" %-9.2f |\n", portfolio[i].change);
    }
  }
}

void update_stocks() {
  for (int i = 0; i < num_stocks; i++) {
    float prev_price = portfolio[i].price;
    portfolio[i].price += (rand() % 201 - 100) / 100.0; // simulate price change
    portfolio[i].change = (portfolio[i].price - prev_price) / prev_price * 100;
  }
}

int main() {
  // initialize stocks
  strcpy(portfolio[0].name, "AAPL");
  portfolio[0].price = 148.48;
  strcpy(portfolio[1].name, "GOOG");
  portfolio[1].price = 2746.01;
  strcpy(portfolio[2].name, "TSLA");
  portfolio[2].price = 709.67;
  num_stocks = 3;

  // main loop
  char input[MAX_NAME_LENGTH];
  while (1) {
    update_stocks();
    display_portfolio();
    printf("\nEnter a stock name to add to portfolio, or QUIT to exit: ");
    scanf("%s", input);
    if (strcmp(input, "QUIT") == 0) {
      break;
    }
    if (num_stocks >= MAX_STOCKS) {
      printf("Portfolio is full!\n");
      continue;
    }
    // check if the stock is already in the portfolio
    for (int i = 0; i < num_stocks; i++) {
      if (strcmp(portfolio[i].name, input) == 0) {
        printf("%s is already in the portfolio!\n", input);
        break;
      }
    }
    // add the new stock
    strcpy(portfolio[num_stocks].name, input);
    portfolio[num_stocks].price = (rand() % 501 + 500) / 100.0; // random price between 5 and 10
    portfolio[num_stocks].change = 0;
    num_stocks++;
  }

  return 0;
}