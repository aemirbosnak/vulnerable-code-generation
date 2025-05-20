//FormAI DATASET v1.0 Category: Stock market tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  float stock_price = 148.52;
  float previous_price = 145.67;
  float difference = (stock_price - previous_price) / previous_price * 100;

  if (difference > 0) {
    printf("Wow! The stock has gone up by %.2f%% since yesterday!", difference);
  } else if (difference < 0) {
    printf("Oh no! The stock has gone down by %.2f%% since yesterday...", difference);
  } else {
    printf("The stock price is the same as yesterday.");
  }

  printf("\n");

  float growth_rate = 0.035;
  int years = 10;
  float future_price = stock_price;

  for (int i = 0; i < years; i++) {
    future_price += future_price * growth_rate;
  }

  printf("In %d years, the stock price could be $%.2f!\n", years, future_price);

  printf("\n");

  printf("Enter the amount of shares you own: ");
  int shares;
  scanf("%d", &shares);

  float total_value = stock_price * shares;

  printf("Your shares are worth $%.2f!\n", total_value);

  printf("\n");

  int chart_width = 20;
  int current_price = stock_price;
  int chart_top = current_price + 2;
  int chart_bottom = current_price - 2;

  printf("Stock Chart\n");

  for (int i = 0; i < chart_width; i++) {
    printf("-");
  }

  printf("\n");

  for (int i = 0; i < chart_width; i++) {
    if (current_price >= chart_top) {
      printf("|");
    } else if (current_price <= chart_bottom) {
      printf("|");
    } else {
      printf(" ");
    }
    
    current_price += rand() % 3 - 1;
  }

  printf("\n");

  for (int i = 0; i < chart_width; i++) {
    printf("-");
  }

  printf("\n");

  return 0;
}