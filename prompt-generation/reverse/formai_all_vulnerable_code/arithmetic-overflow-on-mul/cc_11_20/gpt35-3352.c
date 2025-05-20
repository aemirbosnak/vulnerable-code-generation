//FormAI DATASET v1.0 Category: Stock market tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int stocks[5] = {200, 300, 150, 250, 350}; // initial prices of 5 stocks
  int choice, quantity, invested = 0;
  float invested_amt = 0, current_val = 0, profit_loss = 0;
  srand(time(0));                           // seed for random numbers

  printf("Welcome to the C Stock Market Tracker!\n");
  
  while(1)         // runs forever until user chooses to exit
  {
    printf("\nChoose an option:\n");
    printf("1. Buy stocks\n");
    printf("2. Sell stocks\n");
    printf("3. Check current value\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1)    // Buy stocks
    {
        int stock_num;
        printf("\nEnter stock number to purchase (1-5): ");
        scanf("%d", &stock_num);
        if(stock_num<1 || stock_num>5)
        {
            printf("\nInvalid option. Please try again.");
            continue;
        }
        printf("Enter quantity to purchase: ");
        scanf("%d", &quantity);
        if(stocks[stock_num-1]*quantity > invested - invested_amt)
        {
            printf("\nInsufficient funds. Please try again.");
            continue;
        }
        invested_amt += stocks[stock_num-1]*quantity;
        printf("\nTransaction complete!\n");
    }
    else if(choice == 2)    // Sell stocks
    {
        int stock_num, sold_quantity;
        printf("\nEnter stock number to sell (1-5): ");
        scanf("%d", &stock_num);
        if(stock_num<1 || stock_num>5)
        {
            printf("\nInvalid option. Please try again.");
            continue;
        }
        printf("Enter quantity to sell: ");
        scanf("%d", &sold_quantity);
        if(stocks[stock_num-1] < sold_quantity)
        {
            printf("\nInsufficient stocks. Please try again.");
            continue;
        }
        invested_amt -= stocks[stock_num-1]*sold_quantity;
        printf("\nTransaction complete!\n");
    }
    else if(choice == 3)    // Check current value
    {
        current_val = 0;
        for(int i=0;i<5;i++)
        {
            float rand_val = rand()%50;   // generates random number between 0-49
            float rand_pct = rand_val/100;  // generates random percentage between 0-0.49
            current_val += stocks[i]*(1+rand_pct);  // updates current value
        }
        printf("\nCurrent value of portfolio: %0.2f\n", current_val);
        profit_loss = (current_val - invested_amt)/invested_amt * 100;
        if(profit_loss > 0)
            printf("Profit of %0.2f%%\n", profit_loss);
        else
            printf("Loss of %0.2f%%\n", -profit_loss);
    }
    else if(choice == 4)    // Exit
    {
        printf("\nThank you for using C Stock Market Tracker!\n");
        break;
    }
    else     // Invalid option
    {
        printf("\nInvalid option. Please try again.");
        continue;
    }
  }
  return 0;
}