//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCK_NUM 10

typedef struct Stock
{
    char name[20];
    double price;
    double change;
    double prev_price;
} Stock;

Stock stocks[MAX_STOCK_NUM];

void initializeStocks()
{
    for (int i = 0; i < MAX_STOCK_NUM; i++)
    {
        stocks[i].name[0] = '\0';
        stocks[i].price = 0.0;
        stocks[i].change = 0.0;
        stocks[i].prev_price = 0.0;
    }
}

void updateStockPrices()
{
    // Simulated data update
    for (int i = 0; i < MAX_STOCK_NUM; i++)
    {
        stocks[i].prev_price = stocks[i].price;
        stocks[i].price = rand() % 100 + 100.0;
        stocks[i].change = (stocks[i].price - stocks[i].prev_price) / stocks[i].prev_price * 100.0;
    }
}

void displayStockList()
{
    printf("-------------------------\n");
    printf("Stock List:\n");
    printf("-------------------------\n");
    for (int i = 0; i < MAX_STOCK_NUM; i++)
    {
        printf("%s: %.2lf (%s)\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

int main()
{
    initializeStocks();
    updateStockPrices();
    displayStockList();

    return 0;
}