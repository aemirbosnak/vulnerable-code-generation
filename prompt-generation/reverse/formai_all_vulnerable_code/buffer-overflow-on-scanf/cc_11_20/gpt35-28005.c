//FormAI DATASET v1.0 Category: Stock market tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int c_stock = 2000;
    printf("Welcome to the C Stock Market Tracker!\n");
    printf("You currently have %d stocks in C Corporation.\n", c_stock);
    printf("Let's see how your stocks are doing today...\n");

    int day = 1;

    while (c_stock > 0)
    {
        printf("\n\nDay %d:\n", day);

        int fluctuation = rand() % 401 - 200;  // The stock price could go up or down by up to $2 per share.
        int change = fluctuation * c_stock / 10000;
        printf("The stock price has fluctuated by $%d per share.\n", fluctuation);
        printf("Your portfolio has changed by %d stocks.\n", change);

        c_stock += change;
        printf("You now have %d stocks in C Corporation.\n", c_stock);

        if (c_stock <= 0)
        {
            printf("You are now bankrupt. Better luck next time!\n");
            return 0;
        }

        printf("Would you like to buy, sell, or hold onto your stocks? (b/s/h)\n");
        char input;
        while (1)
        {
            scanf(" %c", &input);
            if (input == 'b' || input == 's' || input == 'h')
            {
                break;
            }
            printf("Invalid input. Please enter 'b', 's', or 'h'.\n");
        }

        int trade_amount;
        switch (input)
        {
            case 'b':
                printf("How many stocks would you like to purchase?\n");
                scanf("%d", &trade_amount);
                if (trade_amount * 5 > c_stock)
                {
                    printf("You can't afford to purchase that many stocks.\n");
                }
                else
                {
                    c_stock -= trade_amount * 5;
                    printf("You've purchased %d stocks for $%d.\n", trade_amount, trade_amount * 5);
                }
                break;
            case 's':
                printf("How many stocks would you like to sell?\n");
                scanf("%d", &trade_amount);
                if (trade_amount > c_stock)
                {
                    printf("You don't have that many stocks to sell.\n");
                }
                else
                {
                    c_stock -= trade_amount;
                    printf("You've sold %d stocks for $%d.\n", trade_amount, trade_amount * 5);
                }
                break;
            case 'h':
                printf("You've decided to hold onto your stocks.\n");
                break;
        }

        day++;
    }

    return 0;
}