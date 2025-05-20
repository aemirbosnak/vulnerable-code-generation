//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STOCK_NUM 10

typedef struct Stock {
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
} Stock;

void updateStock(Stock *stock) {
    // Simulate fetching stock price from an API
    stock->currentPrice = rand() % 1000;
    stock->previousPrice = rand() % 1000;
    stock->change = (stock->currentPrice - stock->previousPrice) / stock->previousPrice * 100;
}

int main() {

    Stock stocks[MAX_STOCK_NUM];

    for (int i = 0; i < MAX_STOCK_NUM; i++) {
        stocks[i].name[0] = 'A' + i;
        stocks[i].currentPrice = rand() % 1000;
        stocks[i].previousPrice = rand() % 1000;
        stocks[i].change = (stocks[i].currentPrice - stocks[i].previousPrice) / stocks[i].previousPrice * 100;
    }

    system("clear");

    printf("Stock Market Tracker (Shifting Shape)\n");
    printf("------------------------\n");

    for (int i = 0; i < MAX_STOCK_NUM; i++) {
        printf("%s: ", stocks[i].name);
        printf("$%.2lf ", stocks[i].currentPrice);
        printf(" (%.2lf%%)", stocks[i].change);
        printf("\n");
    }

    sleep(1);

    system("clear");

    printf("Market Fluctuations (Shifting Shape)\n");
    printf("------------------------\n");

    for (int i = 0; i < MAX_STOCK_NUM; i++) {
        printf("%s: ", stocks[i].name);
        printf("Previous Price: $%.2lf", stocks[i].previousPrice);
        printf("\n");
    }

    sleep(1);

    return 0;
}