//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct stock {
  char name[MAX_NAME_LEN + 1];
  char price[MAX_PRICE_LEN + 1];
  time_t last_updated;
} stock_t;

void print_stock(stock_t *stock) {
  printf("%s: %s (%s)", stock->name, stock->price, ctime(&stock->last_updated));
}

int main() {
  stock_t stocks[MAX_STOCKS];
  int num_stocks = 0;

  FILE *fp = fopen("stocks.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  while (fscanf(fp, "%s %s\n", stocks[num_stocks].name, stocks[num_stocks].price) != EOF) {
    stocks[num_stocks].last_updated = time(NULL);
    num_stocks++;
  }

  fclose(fp);

  while (1) {
    system("clear");

    printf("Stock Market Tracker\n\n");
    for (int i = 0; i < num_stocks; i++) {
      print_stock(&stocks[i]);
    }

    printf("\nPress any key to refresh...");
    getchar();
  }

  return EXIT_SUCCESS;
}