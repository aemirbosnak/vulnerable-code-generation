//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK_NUM 10

typedef struct Stock
{
    char name[20];
    double price;
    double change;
    double previous_price;
} Stock;

void initialize_stocks(Stock *stocks, int num_stocks)
{
    for (int i = 0; i < num_stocks; i++)
    {
        stocks[i].name[0] = '\0';
        stocks[i].price = 0.0;
        stocks[i].change = 0.0;
        stocks[i].previous_price = 0.0;
    }
}

void update_stock_prices(Stock *stocks, int num_stocks)
{
    for (int i = 0; i < num_stocks; i++)
    {
        stocks[i].previous_price = stocks[i].price;
        stocks[i].price = rand() % 100;
        stocks[i].change = (stocks[i].price - stocks[i].previous_price) / stocks[i].previous_price * 100.0;
    }
}

void display_stocks(Stock *stocks, int num_stocks)
{
    for (int i = 0; i < num_stocks; i++)
    {
        printf("%s: $%.2lf, Change: %.2lf%%", stocks[i].name, stocks[i].price, stocks[i].change);
        printf("\n");
    }
}

int main()
{
    Stock stocks[MAX_STOCK_NUM];
    initialize_stocks(stocks, MAX_STOCK_NUM);
    update_stock_prices(stocks, MAX_STOCK_NUM);
    display_stocks(stocks, MAX_STOCK_NUM);

    return 0;
}