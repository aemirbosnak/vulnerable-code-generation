//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Market data
    int stock_prices[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int num_stocks = sizeof(stock_prices) / sizeof(int);

    // User input
    char input;
    printf("Enter 'a' to view all stocks, 's' to select a stock, or 'q' to quit: ");
    scanf("%c", &input);

    // Display all stocks
    if (input == 'a')
    {
        for (int i = 0; i < num_stocks; i++)
        {
            printf("Stock %d: $%d\n", i + 1, stock_prices[i]);
        }
    }

    // Select a stock
    else if (input == 's')
    {
        int stock_num;
        printf("Enter the number of the stock you want to select: ");
        scanf("%d", &stock_num);

        if (stock_num > num_stocks || stock_num < 1)
        {
            printf("Invalid stock number.\n");
        }
        else
        {
            printf("Stock %d: $%d\n", stock_num, stock_prices[stock_num - 1]);
        }
    }

    // Quit
    else if (input == 'q')
    {
        printf("Thank you for using the stock market tracker.\n");
    }
    else
    {
        printf("Invalid input.\n");
    }

    return 0;
}