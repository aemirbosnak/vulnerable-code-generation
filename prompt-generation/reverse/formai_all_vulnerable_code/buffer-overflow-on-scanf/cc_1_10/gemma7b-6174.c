//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Stocks 10

struct Stock {
    char name[20];
    int currentPrice;
    int previousPrice;
    double change;
    double percentageChange;
};

void calculateChangeAndPercentageChange(struct Stock *stock) {
    stock->change = stock->currentPrice - stock->previousPrice;
    stock->percentageChange = (stock->change / stock->previousPrice) * 100;
}

void displayStock(struct Stock *stock) {
    printf("Name: %s\n", stock->name);
    printf("Current Price: %d\n", stock->currentPrice);
    printf("Previous Price: %d\n", stock->previousPrice);
    printf("Change: %d\n", stock->change);
    printf("Percentage Change: %.2f%%\n", stock->percentageChange);
    printf("\n");
}

int main() {
    struct Stock stocks[MAX_Stocks];
    int i;

    // Initialize stocks
    for (i = 0; i < MAX_Stocks; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0;
        stocks[i].previousPrice = 0;
        stocks[i].change = 0.0;
        stocks[i].percentageChange = 0.0;
    }

    // Get stock data
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[0].name);

    printf("Enter the current price of the stock: ");
    scanf("%d", &stocks[0].currentPrice);

    printf("Enter the previous price of the stock: ");
    scanf("%d", &stocks[0].previousPrice);

    // Calculate change and percentage change
    calculateChangeAndPercentageChange(&stocks[0]);

    // Display stock information
    displayStock(&stocks[0]);

    return 0;
}