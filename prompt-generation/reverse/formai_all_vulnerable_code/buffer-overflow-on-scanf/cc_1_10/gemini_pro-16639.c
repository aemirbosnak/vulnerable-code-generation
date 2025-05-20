//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct Stock {
    char symbol[10];
    double price;
};

int main() {
    // Create an array of stocks
    struct Stock stocks[] = {
        {"AAPL", 100.00},
        {"GOOG", 500.00},
        {"AMZN", 1000.00}
    };

    // Get the number of stocks in the array
    int num_stocks = sizeof(stocks) / sizeof(stocks[0]);

    // Print the header
    printf("Current Stock Prices:\n");
    printf("Symbol\tPrice\n");

    // Print the stock prices
    for (int i = 0; i < num_stocks; i++) {
        printf("%s\t%.2f\n", stocks[i].symbol, stocks[i].price);
    }

    // Get the stock symbol from the user
    char symbol[10];
    printf("Enter the stock symbol: ");
    scanf("%s", symbol);

    // Find the stock in the array
    int index = -1;
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(symbol, stocks[i].symbol) == 0) {
            index = i;
            break;
        }
    }

    // If the stock was not found, print an error message
    if (index == -1) {
        printf("Stock not found.\n");
    } else {
        // Print the stock price
        printf("Stock price: %.2f\n", stocks[index].price);
    }

    return 0;
}