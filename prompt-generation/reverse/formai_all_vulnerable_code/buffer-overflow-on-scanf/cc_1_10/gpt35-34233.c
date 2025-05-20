//FormAI DATASET v1.0 Category: Stock market tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20

struct Stock {
  char name[MAX_NAME_LENGTH];
  float price;
};

void printStock(struct Stock s) {
  printf("%s: $%.2f\n", s.name, s.price);
}

int main() {
  int numStocks = 0;
  struct Stock stocks[MAX_STOCKS];

  while(numStocks < MAX_STOCKS) {
    char name[MAX_NAME_LENGTH];
    float price;

    printf("Enter stock name (or 'quit' to exit): ");
    scanf("%s", name);

    if(strcmp(name, "quit") == 0) {
      break;
    }

    printf("Enter stock price: ");
    scanf("%f", &price);

    struct Stock s;
    strcpy(s.name, name);
    s.price = price;

    stocks[numStocks] = s;
    numStocks++;
  }

  if(numStocks == 0) {
    printf("No stocks entered\n");
    return 0;
  }

  printf("\nCurrent Stock Prices:\n");
  for(int i = 0; i < numStocks; i++) {
    printStock(stocks[i]);
  }

  return 0;
}