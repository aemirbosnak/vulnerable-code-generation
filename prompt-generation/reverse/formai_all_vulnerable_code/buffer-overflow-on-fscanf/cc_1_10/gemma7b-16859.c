//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_Stocks 100
#define MAX_Quotes 1000

typedef struct Stock {
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
    double volatility;
} Stock;

Stock stocks[MAX_Stocks];

void updateStock(Stock *stock) {
    // Get the latest quote for the stock
    char quote[MAX_Quotes];
    FILE *fp = fopen("quotes.txt", "r");
    fscanf(fp, "%s ", quote);
    fclose(fp);

    // Parse the quote and update the stock's price
    double newPrice = atof(quote);
    stock->previousPrice = stock->currentPrice;
    stock->currentPrice = newPrice;

    // Calculate the stock's change and volatility
    double change = (newPrice - stock->previousPrice) / stock->previousPrice * 100;
    stock->change = change;
    double volatility = abs(change) / 100;
    stock->volatility = volatility;
}

void displayStock(Stock *stock) {
    printf("%s: ", stock->name);
    printf("$%.2f", stock->currentPrice);
    printf(" (%.2f%%), ", stock->change);
    printf("Volatility: %.2f%%", stock->volatility);
    printf("\n");
}

int main() {
    // Create and initialize the stocks
    for (int i = 0; i < MAX_Stocks; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
        stocks[i].volatility = 0.0;
    }

    // Update the stock prices
    updateStock(stocks);

    // Display the stock prices
    for (int i = 0; i < MAX_Stocks; i++) {
        displayStock(&stocks[i]);
    }

    return 0;
}