//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the stock market data structure
typedef struct Stock
{
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
    double changePercentage;
} Stock;

// Function to get the current stock market data
void getStockData(Stock *stock)
{
    // Randomly generate the current price
    stock->currentPrice = rand() % 1000;

    // Calculate the change and change percentage
    stock->change = stock->currentPrice - stock->previousPrice;
    stock->changePercentage = (stock->change / stock->previousPrice) * 100;
}

// Function to display the stock market data
void displayStockData(Stock *stock)
{
    // Print the stock name, current price, previous price, and change
    printf("%s: %.2f, %.2f, %.2f%%", stock->name, stock->currentPrice, stock->previousPrice, stock->changePercentage);
    printf("\n");
}

int main()
{
    // Create an array of stocks
    Stock stocks[10];

    // Get the current stock market data for each stock
    for (int i = 0; i < 10; i++)
    {
        getStockData(&stocks[i]);
    }

    // Display the stock market data for each stock
    for (int i = 0; i < 10; i++)
    {
        displayStockData(&stocks[i]);
    }

    return 0;
}