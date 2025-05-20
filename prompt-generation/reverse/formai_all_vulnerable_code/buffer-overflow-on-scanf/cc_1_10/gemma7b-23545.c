//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_Stocks 10

typedef struct Stock
{
    char name[20];
    int currentPrice;
    int previousPrice;
    int change;
} Stock;

void calculateChange(Stock *stock)
{
    stock->change = stock->currentPrice - stock->previousPrice;
}

int main()
{
    Stock stocks[MAX_Stocks];
    int i;

    // Initialize stocks
    for (i = 0; i < MAX_Stocks; i++)
    {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0;
        stocks[i].previousPrice = 0;
        stocks[i].change = 0;
    }

    // Get stock data
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[0].name);
    printf("Enter the current price of the stock: ");
    scanf("%d", &stocks[0].currentPrice);
    printf("Enter the previous price of the stock: ");
    scanf("%d", &stocks[0].previousPrice);

    // Calculate change
    calculateChange(&stocks[0]);

    // Display results
    printf("The name of the stock is: %s\n", stocks[0].name);
    printf("The current price of the stock is: %d\n", stocks[0].currentPrice);
    printf("The previous price of the stock is: %d\n", stocks[0].previousPrice);
    printf("The change in the price of the stock is: %d\n", stocks[0].change);

    return 0;
}