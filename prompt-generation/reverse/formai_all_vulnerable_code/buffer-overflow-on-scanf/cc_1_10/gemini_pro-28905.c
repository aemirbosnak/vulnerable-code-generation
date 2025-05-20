//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stock {
  char *name;
  double price;
  double change;
} stock;

int main() {
  // Initialize the stock tracker
  int num_stocks = 0;
  stock *stocks = NULL;

  // Get the number of stocks to track
  printf("How many stocks do you want to track? ");
  scanf("%d", &num_stocks);

  // Allocate memory for the stocks
  stocks = malloc(sizeof(stock) * num_stocks);

  // Get the details of each stock
  for (int i = 0; i < num_stocks; i++) {
    printf("Enter the name of stock %d: ", i + 1);
    stocks[i].name = malloc(sizeof(char) * 256);
    scanf("%s", stocks[i].name);

    printf("Enter the price of stock %d: ", i + 1);
    scanf("%lf", &stocks[i].price);

    printf("Enter the change in stock %d: ", i + 1);
    scanf("%lf", &stocks[i].change);
  }

  // Print the stock tracker
  printf("\nStock Tracker\n");
  printf("===================\n");
  printf("Name\tPrice\tChange\n");
  for (int i = 0; i < num_stocks; i++) {
    printf("%s\t%.2f\t%.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
  }

  // Free the memory allocated for the stocks
  for (int i = 0; i < num_stocks; i++) {
    free(stocks[i].name);
  }
  free(stocks);

  return 0;
}