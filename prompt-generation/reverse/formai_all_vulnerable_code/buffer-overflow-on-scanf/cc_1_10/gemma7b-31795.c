//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STOCK_NUM 10

typedef struct Stock {
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
    double changePercentage;
} Stock;

void calculateStockChangePercentage(Stock *stock) {
    if (stock->previousPrice != 0) {
        stock->changePercentage = (stock->currentPrice - stock->previousPrice) / stock->previousPrice * 100;
    } else {
        stock->changePercentage = 0;
    }
}

int main() {
    Stock stocks[MAX_STOCK_NUM];

    // Initialize stocks
    for (int i = 0; i < MAX_STOCK_NUM; i++) {
        strcpy(stocks[i].name, "");
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
        stocks[i].changePercentage = 0.0;
    }

    // Get stock data
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[0].name);

    printf("Enter the current price of the stock: ");
    scanf("%lf", &stocks[0].currentPrice);

    // Calculate stock change percentage
    calculateStockChangePercentage(&stocks[0]);

    // Display stock information
    printf("Stock Name: %s\n", stocks[0].name);
    printf("Current Price: %.2lf\n", stocks[0].currentPrice);
    printf("Previous Price: %.2lf\n", stocks[0].previousPrice);
    printf("Change: %.2lf\n", stocks[0].change);
    printf("Change Percentage: %.2lf%\n", stocks[0].changePercentage);

    return 0;
}