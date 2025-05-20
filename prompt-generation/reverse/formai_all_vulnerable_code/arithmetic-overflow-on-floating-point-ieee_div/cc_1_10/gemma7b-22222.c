//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_Stocks 10

typedef struct Stock {
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
    double percentChange;
} Stock;

Stock stocks[MAX_Stocks];

void updateStockPrices() {
    for (int i = 0; i < MAX_Stocks; i++) {
        stocks[i].previousPrice = stocks[i].currentPrice;
        stocks[i].currentPrice = rand() % 1000;
        stocks[i].change = stocks[i].currentPrice - stocks[i].previousPrice;
        stocks[i].percentChange = (stocks[i].change / stocks[i].previousPrice) * 100;
    }
}

void displayStockList() {
    printf("\n");
    printf("--------------------------------------------------------\n");
    printf("   Stock Name | Current Price | Previous Price | Change | Percent Change |\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < MAX_Stocks; i++) {
        printf("   %-20s | %.2lf | %.2lf | %.2lf | %.2lf %%\n", stocks[i].name, stocks[i].currentPrice, stocks[i].previousPrice, stocks[i].change, stocks[i].percentChange);
    }
    printf("\n");
}

int main() {

    // Initialize the stock list
    for (int i = 0; i < MAX_Stocks; i++) {
        strcpy(stocks[i].name, "");
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
        stocks[i].percentChange = 0.0;
    }

    // Update the stock prices
    updateStockPrices();

    // Display the stock list
    displayStockList();

    // Sleep for a while
    sleep(2);

    // Update the stock prices again
    updateStockPrices();

    // Display the stock list again
    displayStockList();

    return 0;
}