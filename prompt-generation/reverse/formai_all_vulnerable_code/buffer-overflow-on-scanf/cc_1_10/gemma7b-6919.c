//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCK_NUM 10

typedef struct Stock
{
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
} Stock;

void updateStock(Stock *stock)
{
    printf("Enter the current price of %s: ", stock->name);
    scanf("%lf", &stock->currentPrice);

    if (stock->currentPrice > stock->previousPrice)
    {
        stock->change = (stock->currentPrice - stock->previousPrice) / stock->previousPrice * 100;
        printf("%s is up %f%.2f%%.\n", stock->name, stock->change);
    }
    else if (stock->currentPrice < stock->previousPrice)
    {
        stock->change = (stock->previousPrice - stock->currentPrice) / stock->previousPrice * 100;
        printf("%s is down %f%.2f%%.\n", stock->name, stock->change);
    }
    else
    {
        printf("%s is unchanged.\n", stock->name);
    }

    stock->previousPrice = stock->currentPrice;
}

int main()
{
    Stock stocks[MAX_STOCK_NUM];

    for (int i = 0; i < MAX_STOCK_NUM; i++)
    {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
    }

    int numStocks = 0;

    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &numStocks);

    for (int i = 0; i < numStocks; i++)
    {
        printf("Enter the name of the stock: ");
        scanf("%s", stocks[i].name);

        updateStock(&stocks[i]);
    }

    return 0;
}