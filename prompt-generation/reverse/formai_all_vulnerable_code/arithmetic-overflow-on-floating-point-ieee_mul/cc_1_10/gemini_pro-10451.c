//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declare the main function
int main() {
  // Declare the variables
  int num_stocks, i;
  float stock_price, total_investment, total_value, profit;

  // Get the number of stocks from the user
  printf("Enter the number of stocks: ");
  scanf("%d", &num_stocks);

  // Get the stock price from the user
  printf("Enter the stock price: ");
  scanf("%f", &stock_price);

  // Calculate the total investment
  total_investment = num_stocks * stock_price;

  // Get the stock prices for each stock
  float stock_prices[num_stocks];
  for (i = 0; i < num_stocks; i++) {
    printf("Enter the stock price for stock %d: ", i + 1);
    scanf("%f", &stock_prices[i]);
  }

  // Calculate the total value of the stocks
  total_value = 0;
  for (i = 0; i < num_stocks; i++) {
    total_value += stock_prices[i];
  }

  // Calculate the profit
  profit = total_value - total_investment;

  // Print the results
  printf("Total investment: $%.2f\n", total_investment);
  printf("Total value: $%.2f\n", total_value);
  printf("Profit: $%.2f\n", profit);

  // Check if the user made a profit or loss
  if (profit > 0) {
    printf("Congratulations! You made a profit.\n");
  } else if (profit < 0) {
    printf("Sorry, you made a loss.\n");
  } else {
    printf("You broke even.\n");
  }

  return 0;
}