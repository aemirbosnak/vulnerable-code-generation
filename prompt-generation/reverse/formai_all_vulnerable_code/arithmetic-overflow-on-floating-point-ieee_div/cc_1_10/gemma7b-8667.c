//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK_NUM 10

typedef struct Stock
{
    char name[20];
    int current_price;
    int previous_price;
    double change_percentage;
} Stock;

Stock stocks[MAX_STOCK_NUM];

void initialize_stocks()
{
    for (int i = 0; i < MAX_STOCK_NUM; i++)
    {
        stocks[i].name[0] = '\0';
        stocks[i].current_price = 0;
        stocks[i].previous_price = 0;
        stocks[i].change_percentage = 0.0;
    }
}

void update_stock_prices()
{
    for (int i = 0; i < MAX_STOCK_NUM; i++)
    {
        stocks[i].previous_price = stocks[i].current_price;
        stocks[i].current_price = rand() % 1000;
        stocks[i].change_percentage = (double)(stocks[i].current_price - stocks[i].previous_price) / stocks[i].previous_price * 100.0;
    }
}

void display_stocks()
{
    for (int i = 0; i < MAX_STOCK_NUM; i++)
    {
        printf("%s: $%d, Change: %.2f%% \n", stocks[i].name, stocks[i].current_price, stocks[i].change_percentage);
    }
}

int main()
{
    initialize_stocks();
    update_stock_prices();
    display_stocks();

    return 0;
}