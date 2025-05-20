//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main()
{
    int i, j, k, stock_price[MAX], total_profit = 0, current_price, previous_price;

    // Initializing the stock price array
    for (i = 0; i < MAX; i++)
    {
        stock_price[i] = 0;
    }

    // Generating random stock prices
    for (i = 0; i < MAX; i++)
    {
        stock_price[i] = rand() % 1000;
    }

    // Displaying the stock prices
    printf("Current Stock Prices:\n");
    for (i = 0; i < MAX; i++)
    {
        printf("Stock %d: $%d\n", i + 1, stock_price[i]);
    }

    // Getting the current price
    printf("Enter the current price of the stock: ");
    scanf("%d", &current_price);

    // Calculating the previous price
    previous_price = stock_price[0];
    for (i = 0; i < MAX - 1; i++)
    {
        if (current_price > stock_price[i])
        {
            previous_price = stock_price[i];
        }
    }

    // Calculating the total profit
    total_profit = current_price - previous_price;

    // Displaying the total profit
    printf("Total Profit: $%d\n", total_profit);

    return 0;
}