//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_Stocks 10

typedef struct Stock
{
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
    double changePercentage;
} Stock;

Stock stocks[MAX_Stocks];

void initializeStocks()
{
    for (int i = 0; i < MAX_Stocks; i++)
    {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
        stocks[i].changePercentage = 0.0;
    }
}

void updateStockPrices()
{
    // Replace this with actual code to get stock prices
    for (int i = 0; i < MAX_Stocks; i++)
    {
        stocks[i].currentPrice = rand() % 1000;
    }
}

void calculateStockChanges()
{
    for (int i = 0; i < MAX_Stocks; i++)
    {
        stocks[i].change = stocks[i].currentPrice - stocks[i].previousPrice;
        stocks[i].changePercentage = (stocks[i].change / stocks[i].previousPrice) * 100.0;
    }
}

void displayStockSummary()
{
    printf("\nStock Summary:");
    for (int i = 0; i < MAX_Stocks; i++)
    {
        printf("\nName: %s", stocks[i].name);
        printf("\nCurrent Price: $%.2lf", stocks[i].currentPrice);
        printf("\nPrevious Price: $%.2lf", stocks[i].previousPrice);
        printf("\nChange: $%.2lf", stocks[i].change);
        printf("\nChange Percentage: %.2f%%", stocks[i].changePercentage);
    }
}

int main()
{
    initializeStocks();
    updateStockPrices();
    calculateStockChanges();
    displayStockSummary();

    return 0;
}