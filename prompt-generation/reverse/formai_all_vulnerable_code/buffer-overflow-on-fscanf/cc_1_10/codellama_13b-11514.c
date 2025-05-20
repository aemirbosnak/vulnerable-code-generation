//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: immersive
// Stock Market Tracker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Struct for holding stock data
typedef struct {
    char *name;
    int price;
    int change;
} Stock;

// Function to read stock data from file
void readStockData(Stock *stocks, int numStocks) {
    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("Error: unable to open file\n");
        return;
    }

    for (int i = 0; i < numStocks; i++) {
        fscanf(file, "%s %d %d", stocks[i].name, &stocks[i].price, &stocks[i].change);
    }

    fclose(file);
}

// Function to print stock data
void printStockData(Stock *stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        printf("%s: $%d (%+d)\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

// Function to update stock data
void updateStockData(Stock *stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        stocks[i].price += stocks[i].change;
    }
}

// Main function
int main() {
    int numStocks = 5;
    Stock *stocks = malloc(numStocks * sizeof(Stock));

    readStockData(stocks, numStocks);
    printStockData(stocks, numStocks);

    // Simulate stock market updates for 10 minutes
    for (int i = 0; i < 10; i++) {
        updateStockData(stocks, numStocks);
        printf("------------------------------------\n");
        printStockData(stocks, numStocks);
        sleep(60);
    }

    free(stocks);
    return 0;
}