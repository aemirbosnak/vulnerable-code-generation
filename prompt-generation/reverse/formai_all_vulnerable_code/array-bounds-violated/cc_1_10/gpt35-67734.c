//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define STOCK_NAME_LENGTH 10

typedef struct stock {
  char name[STOCK_NAME_LENGTH];
  float price;
  float change;
} Stock;

int main() {
  Stock stocks[MAX_STOCKS];
  int num_stocks = 0;
  
  // Prompt user to enter stocks
  printf("Enter up to %d stock names and prices, separated by a space. Type 'done' to finish.\n", MAX_STOCKS);
  printf("Format: 'stock_name price'\n");

  char input[40];
  while (num_stocks < MAX_STOCKS) {
    // Get user input for stock name and price
    fgets(input, 40, stdin);
    input[strlen(input) - 1] = '\0'; // Remove new line character

    // Check if user is done entering stocks
    if (strcmp(input, "done") == 0) {
      break;
    }

    // Parse stock name and price
    char *token = strtok(input, " ");
    strncpy(stocks[num_stocks].name, token, STOCK_NAME_LENGTH);
    stocks[num_stocks].name[STOCK_NAME_LENGTH - 1] = '\0'; // Ensure null-terminated
    token = strtok(NULL, " ");
    stocks[num_stocks].price = strtof(token, NULL);
    
    num_stocks++;
  }

  printf("\n");

  // Print stock table header
  printf("%10s %10s %10s\n", "Name", "Price", "Change");

  // Print stock table
  for (int i = 0; i < num_stocks; i++) {
    printf("%10s %10.2f %10s\n", stocks[i].name, stocks[i].price, "N/A");
  }

  return 0;
}