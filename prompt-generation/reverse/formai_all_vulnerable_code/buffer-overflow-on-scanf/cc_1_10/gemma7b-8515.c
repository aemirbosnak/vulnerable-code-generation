//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STOCK_NUM 10

typedef struct Stock
{
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
    double volatility;
} Stock;

int main()
{
    Stock stocks[MAX_STOCK_NUM];
    int i, j;

    // Initialize stocks
    for (i = 0; i < MAX_STOCK_NUM; i++)
    {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
        stocks[i].volatility = 0.0;
    }

    // Get stock data
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[0].name);

    printf("Enter the current price of the stock: ");
    scanf("%lf", &stocks[0].currentPrice);

    printf("Enter the previous price of the stock: ");
    scanf("%lf", &stocks[0].previousPrice);

    // Calculate change and volatility
    stocks[0].change = (stocks[0].currentPrice - stocks[0].previousPrice) / stocks[0].previousPrice * 100.0;
    stocks[0].volatility = abs(stocks[0].change) / 100.0;

    // Display results
    printf("Stock name: %s\n", stocks[0].name);
    printf("Current price: %.2lf\n", stocks[0].currentPrice);
    printf("Previous price: %.2lf\n", stocks[0].previousPrice);
    printf("Change: %.2lf%\n", stocks[0].change);
    printf("Volatility: %.2lf%\n", stocks[0].volatility);

    return 0;
}