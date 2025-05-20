//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Stocks 10
#define MAX_Quotes 100

typedef struct Stock {
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
    double changePercent;
} Stock;

void updateStock(Stock *stock) {
    printf("Updating stock: %s...\n", stock->name);

    // Simulate getting the latest quote
    stock->currentPrice = rand() % 1000;

    // Calculate the change and change percent
    stock->change = stock->currentPrice - stock->previousPrice;
    stock->changePercent = (stock->change / stock->previousPrice) * 100;

    // Print the updated stock information
    printf("Name: %s\n", stock->name);
    printf("Current Price: %.2lf\n", stock->currentPrice);
    printf("Previous Price: %.2lf\n", stock->previousPrice);
    printf("Change: %.2lf\n", stock->change);
    printf("Change Percent: %.2lf%%\n", stock->changePercent);
    printf("\n");
}

int main() {
    // Create an array of stocks
    Stock stocks[MAX_Stocks];

    // Initialize the stocks
    for (int i = 0; i < MAX_Stocks; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
        stocks[i].changePercent = 0.0;
    }

    // Update the stocks
    updateStock(&stocks[0]);
    updateStock(&stocks[1]);
    updateStock(&stocks[2]);

    // Print the updated stock information
    for (int i = 0; i < MAX_Stocks; i++) {
        printf("Stock: %s\n", stocks[i].name);
        printf("------------------------\n");
    }

    return 0;
}