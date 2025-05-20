//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
{
    int i, j, k, n = 0, m = 0, stock_price[MAX], total_investment = 0, current_investment = 0;
    char stock_name[MAX];

    // Initialize the stock price array
    for (i = 0; i < MAX; i++)
    {
        stock_price[i] = 0;
    }

    // Get the number of stocks
    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &n);

    // Get the stock names and prices
    for (i = 0; i < n; i++)
    {
        printf("Enter the name of the stock: ");
        scanf("%s", stock_name[i]);

        printf("Enter the price of the stock: ");
        scanf("%d", &stock_price[i]);

        current_investment += stock_price[i] * 100;
        total_investment += current_investment;
    }

    // Print the stock prices
    printf("Stock Prices:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s: %d\n", stock_name[i], stock_price[i]);
    }

    // Print the total investment
    printf("Total Investment: %d\n", total_investment);

    // Calculate the return on investment
    if (total_investment > 0)
    {
        float return_on_investment = (total_investment - current_investment) / current_investment * 100;
        printf("Return on Investment: %f%%", return_on_investment);
    }

    return 0;
}