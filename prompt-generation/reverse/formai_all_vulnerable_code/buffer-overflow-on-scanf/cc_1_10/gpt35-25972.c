//FormAI DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
  char name[MAX_NAME_LENGTH];
  float price;
} Stock;

int main() {
  int numStocks;
  Stock stocks[MAX_STOCKS];

  printf("Enter the number of stocks you want to track (up to %d): ", MAX_STOCKS);
  scanf("%d", &numStocks);

  // Read in all stocks
  for (int i = 0; i < numStocks; i++) {
    printf("Enter the name of stock #%d: ", i+1);
    scanf(" %[^\n]", stocks[i].name);

    printf("Enter the current price per share: ");
    scanf("%f", &stocks[i].price);
  }

  printf("\n------------ STOCK TRACKER ------------\n");
  printf("   | %-20s | %-10s |\n", "NAME", "PRICE");
  printf("---|----------------------|------------|\n");

  // Print out all stocks
  for (int i = 0; i < numStocks; i++) {
    printf(" %d. | %-20s | $%-9.2f |\n", i+1, stocks[i].name, stocks[i].price);
  }

  // Calculate the highest and lowest-priced stocks
  float highestPrice = stocks[0].price;
  float lowestPrice = stocks[0].price;
  int highestIndex = 0, lowestIndex = 0;
  for (int i = 1; i < numStocks; i++) {
    if (stocks[i].price > highestPrice) {
      highestPrice = stocks[i].price;
      highestIndex = i;
    }
    if (stocks[i].price < lowestPrice) {
      lowestPrice = stocks[i].price;
      lowestIndex = i;
    }
  }

  printf("\nThe highest-priced stock is %s at $%.2f per share.\n", stocks[highestIndex].name, highestPrice);
  printf("The lowest-priced stock is %s at $%.2f per share.\n", stocks[lowestIndex].name, lowestPrice);

  return 0;
}