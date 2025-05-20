//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: rigorous
/*
 * stock_tracker.c
 *
 * A rigorous C program that tracks the stock market.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOLS 100
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10
#define MAX_CHANGE_LENGTH 10
#define MAX_PERCENT_CHANGE_LENGTH 10

typedef struct {
  char symbol[MAX_SYMBOLS];
  char name[MAX_NAME_LENGTH];
  float price;
  float change;
  float percent_change;
} Stock;

void read_stocks(Stock stocks[], int *num_stocks) {
  char line[256];
  int i = 0;
  while (fgets(line, sizeof(line), stdin)) {
    sscanf(line, "%s %s %f %f %f", stocks[i].symbol, stocks[i].name, &stocks[i].price, &stocks[i].change, &stocks[i].percent_change);
    i++;
  }
  *num_stocks = i;
}

void display_stocks(Stock stocks[], int num_stocks) {
  int i;
  printf("Symbol\tName\tPrice\tChange\tPercent Change\n");
  for (i = 0; i < num_stocks; i++) {
    printf("%s\t%s\t%f\t%f\t%f\n", stocks[i].symbol, stocks[i].name, stocks[i].price, stocks[i].change, stocks[i].percent_change);
  }
}

int main() {
  Stock stocks[MAX_SYMBOLS];
  int num_stocks;
  read_stocks(stocks, &num_stocks);
  display_stocks(stocks, num_stocks);
  return 0;
}