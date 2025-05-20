//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_Stocks 10

typedef struct Stock {
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
    double volatility;
} Stock;

Stock stocks[MAX_Stocks];

void initializeStocks() {
    for (int i = 0; i < MAX_Stocks; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
        stocks[i].volatility = 0.0;
    }
}

void updateStockPrices() {
    for (int i = 0; i < MAX_Stocks; i++) {
        stocks[i].previousPrice = stocks[i].currentPrice;
        stocks[i].currentPrice = rand() % 1000;
        stocks[i].change = (stocks[i].currentPrice - stocks[i].previousPrice) / stocks[i].previousPrice * 100.0;
        stocks[i].volatility = abs(stocks[i].change) / 10.0;
    }
}

void displayStockSummary() {
    for (int i = 0; i < MAX_Stocks; i++) {
        printf("%s: ", stocks[i].name);
        printf("Current Price: %.2lf, ", stocks[i].currentPrice);
        printf("Previous Price: %.2lf, ", stocks[i].previousPrice);
        printf("Change: %.2lf%, ", stocks[i].change);
        printf("Volatility: %.2lf%, ", stocks[i].volatility);
        printf("\n");
    }
}

int main() {
    initializeStocks();
    updateStockPrices();
    displayStockSummary();

    return 0;
}