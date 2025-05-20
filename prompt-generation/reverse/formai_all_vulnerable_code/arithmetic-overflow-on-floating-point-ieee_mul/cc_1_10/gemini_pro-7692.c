//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Stock data structure
typedef struct Stock {
    char *symbol;
    double price;
    double change;
    double percentChange;
} Stock;

// Stock market data
struct StockData {
    int numStocks;
    Stock *stocks;
};

// Reads stock data from a file
struct StockData *readStockData(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the number of stocks
    int numStocks;
    fscanf(file, "%d\n", &numStocks);

    // Allocate memory for the stocks
    struct StockData *stockData = malloc(sizeof(struct StockData));
    stockData->numStocks = numStocks;
    stockData->stocks = malloc(sizeof(Stock) * numStocks);

    // Read the stock data
    for (int i = 0; i < numStocks; i++) {
        char symbol[10];
        double price;
        double change;
        fscanf(file, "%s %lf %lf\n", symbol, &price, &change);

        // Calculate the percent change
        double percentChange = change / price * 100;

        // Store the stock data
        stockData->stocks[i].symbol = strdup(symbol);
        stockData->stocks[i].price = price;
        stockData->stocks[i].change = change;
        stockData->stocks[i].percentChange = percentChange;
    }

    // Close the file
    fclose(file);

    // Return the stock data
    return stockData;
}

// Prints the stock data
void printStockData(struct StockData *stockData) {
    // Print the header
    printf("%-10s %-10s %-10s %-10s\n", "Symbol", "Price", "Change", "% Change");

    // Print the stock data
    for (int i = 0; i < stockData->numStocks; i++) {
        printf("%-10s %-10.2f %-10.2f %-10.2f\n", stockData->stocks[i].symbol, stockData->stocks[i].price, stockData->stocks[i].change, stockData->stocks[i].percentChange);
    }
}

// Frees the memory allocated for the stock data
void freeStockData(struct StockData *stockData) {
    // Free the memory allocated for the stocks
    for (int i = 0; i < stockData->numStocks; i++) {
        free(stockData->stocks[i].symbol);
    }
    free(stockData->stocks);

    // Free the memory allocated for the stock data
    free(stockData);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified a filename
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    // Read the stock data from the file
    struct StockData *stockData = readStockData(argv[1]);
    if (stockData == NULL) {
        return 1;
    }

    // Print the stock data
    printStockData(stockData);

    // Free the memory allocated for the stock data
    freeStockData(stockData);

    return 0;
}