//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STOCK_NUM 10
#define MAX_STOCK_NAME_LEN 20
#define MAX_PRICE_DIGITS 7

typedef struct Stock
{
    char name[MAX_STOCK_NAME_LEN];
    double price;
    double previous_price;
    double change;
    double change_percentage;
} Stock;

void calculate_stock_changes(Stock *stocks, int num_stocks)
{
    for (int i = 0; i < num_stocks; i++)
    {
        stocks[i].change = stocks[i].price - stocks[i].previous_price;
        stocks[i].change_percentage = (stocks[i].change / stocks[i].previous_price) * 100.0;
    }
}

int main()
{
    // Create an array of stocks
    Stock stocks[MAX_STOCK_NUM];

    // Initialize the stocks
    for (int i = 0; i < MAX_STOCK_NUM; i++)
    {
        stocks[i].name[0] = '\0';
        stocks[i].price = 0.0;
        stocks[i].previous_price = 0.0;
        stocks[i].change = 0.0;
        stocks[i].change_percentage = 0.0;
    }

    // Get the number of stocks
    int num_stocks = 0;

    // Add stocks to the array
    while (num_stocks < MAX_STOCK_NUM)
    {
        printf("Enter the name of the stock: ");
        scanf("%s", stocks[num_stocks].name);

        printf("Enter the current price of the stock: ");
        scanf("%lf", &stocks[num_stocks].price);

        printf("Enter the previous price of the stock: ");
        scanf("%lf", &stocks[num_stocks].previous_price);

        num_stocks++;
    }

    // Calculate the stock changes
    calculate_stock_changes(stocks, num_stocks);

    // Print the stock changes
    for (int i = 0; i < num_stocks; i++)
    {
        printf("%s: ", stocks[i].name);
        printf("Change: %.2lf (%%.2lf%%)\n", stocks[i].change, stocks[i].change_percentage);
    }

    return 0;
}