//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int i, j, k, stock_price[MAX], total_investment = 0, total_profit = 0;
    char stock_name[MAX][20];

    // Allocate memory for stock name and price
    for (i = 0; i < MAX; i++)
    {
        stock_name[i][0] = '\0';
        stock_price[i] = 0;
    }

    // Get the stock name and price
    printf("Enter the name of the stock: ");
    scanf("%s", stock_name[0]);

    printf("Enter the price of the stock: ");
    scanf("%d", &stock_price[0]);

    // Repeat the above steps for the remaining stocks
    for (i = 1; i < MAX; i++)
    {
        printf("Enter the name of the stock: ");
        scanf("%s", stock_name[i]);

        printf("Enter the price of the stock: ");
        scanf("%d", &stock_price[i]);
    }

    // Calculate the total investment
    for (i = 0; i < MAX; i++)
    {
        total_investment += stock_price[i] * 100;
    }

    // Calculate the total profit
    for (i = 0; i < MAX; i++)
    {
        total_profit += (stock_price[i] - stock_price[0]) * 100;
    }

    // Print the results
    printf("\nTotal investment: $%d", total_investment);

    printf("\nTotal profit: $%d", total_profit);

    return 0;
}