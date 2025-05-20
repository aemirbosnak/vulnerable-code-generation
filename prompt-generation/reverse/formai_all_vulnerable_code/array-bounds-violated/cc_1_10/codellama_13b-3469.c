//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKERS 100
#define MAX_TICKER_LENGTH 10

struct Stock {
    char ticker[MAX_TICKER_LENGTH];
    float price;
    float change;
};

int main() {
    struct Stock stocks[MAX_TICKERS];
    int num_stocks = 0;
    char input[MAX_TICKER_LENGTH];

    while (1) {
        printf("Enter a ticker (or 'q' to quit): ");
        fgets(input, MAX_TICKER_LENGTH, stdin);
        if (strcmp(input, "q\n") == 0) {
            break;
        }

        // Check if ticker is already in the list
        int exists = 0;
        for (int i = 0; i < num_stocks; i++) {
            if (strcmp(stocks[i].ticker, input) == 0) {
                exists = 1;
                break;
            }
        }

        // If ticker does not exist, add it to the list
        if (!exists) {
            strcpy(stocks[num_stocks].ticker, input);
            stocks[num_stocks].price = 0;
            stocks[num_stocks].change = 0;
            num_stocks++;
        }

        // Get the price of the ticker
        printf("Enter the price of %s: ", input);
        fgets(input, MAX_TICKER_LENGTH, stdin);
        stocks[num_stocks - 1].price = atof(input);

        // Calculate the change in price
        stocks[num_stocks - 1].change = stocks[num_stocks - 1].price - stocks[num_stocks - 2].price;

        // Print the current stock prices and changes
        printf("Current stock prices:\n");
        for (int i = 0; i < num_stocks; i++) {
            printf("%s: %f (%f)\n", stocks[i].ticker, stocks[i].price, stocks[i].change);
        }
    }

    return 0;
}