//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100

typedef struct {
    char *symbol;
    double price;
    double change;
    double percent_change;
} stock_t;

int main() {
    // Initialize the stock array
    stock_t stocks[MAX_STOCKS];
    int num_stocks = 0;

    // Read the stock data from a file
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (!feof(fp)) {
        // Read the stock symbol
        char symbol[10];
        if (fscanf(fp, "%s ", symbol) != 1) {
            break;
        }

        // Read the stock price
        double price;
        if (fscanf(fp, "%lf ", &price) != 1) {
            break;
        }

        // Read the stock change
        double change;
        if (fscanf(fp, "%lf ", &change) != 1) {
            break;
        }

        // Read the stock percent change
        double percent_change;
        if (fscanf(fp, "%lf ", &percent_change) != 1) {
            break;
        }

        // Add the stock to the array
        stocks[num_stocks].symbol = strdup(symbol);
        stocks[num_stocks].price = price;
        stocks[num_stocks].change = change;
        stocks[num_stocks].percent_change = percent_change;
        num_stocks++;
    }

    fclose(fp);

    // Print the stock data
    printf("Stock Data:\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("| Symbol | Price | Change | Percent Change |\n");
    printf("----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("| %s | %.2f | %.2f | %.2f%% |\n", stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percent_change);
    }

    // Free the allocated memory
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i].symbol);
    }

    return EXIT_SUCCESS;
}