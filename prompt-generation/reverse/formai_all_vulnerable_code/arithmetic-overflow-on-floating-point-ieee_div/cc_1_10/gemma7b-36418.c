//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCK_NUMBER 10

typedef struct Stock {
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
    double changePercentage;
} Stock;

Stock stocks[MAX_STOCK_NUMBER];

void initializeStocks() {
    for (int i = 0; i < MAX_STOCK_NUMBER; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
        stocks[i].changePercentage = 0.0;
    }
}

void updateStockPrices() {
    // Simulate fetching stock prices from a real-world source
    for (int i = 0; i < MAX_STOCK_NUMBER; i++) {
        stocks[i].currentPrice = rand() % 1000;
        stocks[i].previousPrice = rand() % 1000;
        stocks[i].change = stocks[i].currentPrice - stocks[i].previousPrice;
        stocks[i].changePercentage = (stocks[i].change / stocks[i].previousPrice) * 100;
    }
}

void displayStockList() {
    printf("\n");
    printf("---------------------------------------------------------\n");
    printf("Stock List\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < MAX_STOCK_NUMBER; i++) {
        printf("%s: %.2f (%.2f%%)\n", stocks[i].name, stocks[i].currentPrice, stocks[i].changePercentage);
    }
    printf("\n");
}

int main() {
    initializeStocks();
    updateStockPrices();
    displayStockList();

    return 0;
}