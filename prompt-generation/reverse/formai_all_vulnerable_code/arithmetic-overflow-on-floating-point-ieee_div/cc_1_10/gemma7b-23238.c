//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Stocks 10

typedef struct Stock {
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
} Stock;

Stock stocks[MAX_Stocks];

void initializeStocks() {
    for (int i = 0; i < MAX_Stocks; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
    }
}

void updateStockPrices() {
    // Stub function to update stock prices
    for (int i = 0; i < MAX_Stocks; i++) {
        stocks[i].previousPrice = stocks[i].currentPrice;
        stocks[i].currentPrice = rand() % 1000;
        stocks[i].change = (stocks[i].currentPrice - stocks[i].previousPrice) / stocks[i].previousPrice * 100;
    }
}

void displayStocks() {
    printf("------------------------\n");
    printf("Stock List\n");
    printf("------------------------\n");
    for (int i = 0; i < MAX_Stocks; i++) {
        printf("%s: %.2f (%d%%)\n", stocks[i].name, stocks[i].currentPrice, (int)stocks[i].change);
    }
    printf("\n");
}

int main() {
    initializeStocks();
    updateStockPrices();
    displayStocks();

    return 0;
}