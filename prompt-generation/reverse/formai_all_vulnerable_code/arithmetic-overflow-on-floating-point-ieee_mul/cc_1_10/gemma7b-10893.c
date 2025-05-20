//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Stocks 10

typedef struct Stock {
    char name[50];
    double currentPrice;
    double previousPrice;
    double change;
    double changePercentage;
} Stock;

void calculateStockChanges(Stock *stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        stocks[i].change = stocks[i].currentPrice - stocks[i].previousPrice;
        stocks[i].changePercentage = (stocks[i].change / stocks[i].previousPrice) * 100;
    }
}

int main() {
    Stock stocks[MAX_Stocks];

    // Create and initialize stocks
    for (int i = 0; i < MAX_Stocks; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
        stocks[i].changePercentage = 0.0;
    }

    // Get stock data from user
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[0].name);

    printf("Enter the current price of the stock: ");
    scanf("%lf", &stocks[0].currentPrice);

    printf("Enter the previous price of the stock: ");
    scanf("%lf", &stocks[0].previousPrice);

    // Calculate stock changes
    calculateStockChanges(stocks, 1);

    // Display stock changes
    printf("The change in the stock price is: $%.2lf", stocks[0].change);

    printf("The change percentage in the stock price is: %.2lf%%", stocks[0].changePercentage);

    return 0;
}