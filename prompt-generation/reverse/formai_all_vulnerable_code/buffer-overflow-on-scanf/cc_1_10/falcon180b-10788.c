//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_DAYS 100

// Struct to hold stock data
typedef struct {
    char name[20];
    double price;
    int numDays;
} Stock;

// Function to generate random stock prices
void generatePrices(Stock* stocks, int numStocks, int numDays) {
    srand(time(NULL));

    for (int i = 0; i < numStocks; i++) {
        stocks[i].price = rand() % 100;
        stocks[i].numDays = numDays;
    }
}

// Function to print the current stock prices
void printPrices(Stock* stocks, int numStocks) {
    printf("Current Stock Prices:\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
}

// Function to simulate the stock market for a given number of days
void simulateMarket(Stock* stocks, int numStocks, int numDays) {
    printf("Simulating the stock market for %d days...\n", numDays);

    for (int day = 1; day <= numDays; day++) {
        printf("Day %d:\n", day);
        printPrices(stocks, numStocks);

        // Randomly increase or decrease the stock prices
        for (int i = 0; i < numStocks; i++) {
            if (rand() % 2 == 0) {
                stocks[i].price += rand() % 10;
            } else {
                stocks[i].price -= rand() % 10;
            }
        }
    }
}

int main() {
    // Initialize the stocks
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    printf("Enter the names of the stocks (up to %d):\n", MAX_STOCKS - 1);

    while (numStocks < MAX_STOCKS && scanf("%s", stocks[numStocks].name)!= EOF) {
        numStocks++;
    }

    // Generate random stock prices
    generatePrices(stocks, numStocks, MAX_DAYS);

    // Simulate the stock market
    simulateMarket(stocks, numStocks, MAX_DAYS);

    return 0;
}