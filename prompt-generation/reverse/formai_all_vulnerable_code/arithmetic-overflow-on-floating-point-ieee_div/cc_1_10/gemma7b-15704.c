//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the stock market data structure
typedef struct Stock {
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
    double changePercent;
} Stock;

// Create a function to get the latest stock market data
void getStockData(Stock *stock) {
    // Simulate getting data from an API
    stock->currentPrice = rand() % 1000;
    stock->previousPrice = rand() % 1000;
    stock->change = stock->currentPrice - stock->previousPrice;
    stock->changePercent = (stock->change / stock->previousPrice) * 100;
}

// Main function
int main() {
    // Create an array of stocks
    Stock stocks[5] = {
        {"Apple", 1200.0, 1150.0, 50.0, 4.3},
        {"Microsoft", 2300.0, 2200.0, 100.0, 4.5},
        {"Amazon", 1600.0, 1500.0, 100.0, 6.6},
        {"Google", 1400.0, 1300.0, 100.0, 7.5},
        {"Tesla", 2000.0, 1900.0, 100.0, 5.2}
    };

    // Get the latest stock market data
    for (int i = 0; i < 5; i++) {
        getStockData(&stocks[i]);
    }

    // Print the stock market data
    for (int i = 0; i < 5; i++) {
        printf("Stock: %s\n", stocks[i].name);
        printf("Current Price: %.2lf\n", stocks[i].currentPrice);
        printf("Previous Price: %.2lf\n", stocks[i].previousPrice);
        printf("Change: %.2lf\n", stocks[i].change);
        printf("Change Percent: %.2lf%%\n", stocks[i].changePercent);
        printf("\n");
    }

    return 0;
}