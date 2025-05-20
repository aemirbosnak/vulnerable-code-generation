//FormAI DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the ultimate mind-bending C Stock Market Tracker!\n\n");

  srand(time(NULL));
  
  int stockPrice = rand() % 101 + 50;
  int dayCount = 1;
  
  printf("On day %d, the stock opened at $%d. Let's see what happens...\n\n", dayCount, stockPrice);
  
  while (1) {
    int change = rand() % 21 - 10;
    stockPrice += change;

    if (stockPrice <= 0) {
      printf("The stock has gone bankrupt! You lost all your money.\n");
      break;
    }
    
    if (change >= 0) {
      printf("On day %d, the stock opened at $%d, a change of +$%d from the previous day.\n", dayCount+1, stockPrice, change);
    } else {
      printf("On day %d, the stock opened at $%d, a change of -$%d from the previous day.\n", dayCount+1, stockPrice, abs(change));
    }
    
    int decision = 0;
    printf("\nWhat would you like to do? Enter 1 to buy, 2 to sell, or 3 to hold: ");
    scanf("%d", &decision);
    
    if (decision == 1) {
      int buyAmount;
      printf("\nHow much would you like to invest? Enter an amount: ");
      scanf("%d", &buyAmount);
      
      if (buyAmount > 0 && buyAmount <= stockPrice) {
        printf("\nYou have purchased %d shares for $%d each, totaling $%d.\n\n", buyAmount/stockPrice, stockPrice, buyAmount);
      } else {
        printf("\nInvalid investment amount. You must enter an amount between 1 and the current stock price.\n\n");
      }
    } else if (decision == 2) {
      int sellAmount;
      printf("\nHow many shares would you like to sell? Enter an amount: ");
      scanf("%d", &sellAmount);
      
      if (sellAmount > 0 && sellAmount/stockPrice > 0) {
        printf("\nYou have sold %d shares for $%d each, totaling $%d.\n\n", sellAmount/stockPrice, stockPrice, sellAmount);
      } else {
        printf("\nInvalid sell amount. You must enter an amount greater than 0 and that can be sold for at least $1.\n\n");
      }
    } else if (decision == 3) {
      printf("\nYou have decided to hold and do nothing.\n\n");
    } else {
      printf("\nInvalid decision. You must enter 1, 2, or 3.\n\n");
    }
    
    dayCount++;    
  }

  return 0;
}