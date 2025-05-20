//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: multivariable
// C Stock Market Tracker Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10

// Stock structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
} Stock;

// Function prototypes
void printStock(Stock* stock);
void printStocks(Stock* stocks, int numStocks);
void updateStocks(Stock* stocks, int numStocks);

int main() {
    // Create an array of stocks
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    // Add stocks to the array
    for (int i = 0; i < MAX_STOCKS; i++) {
        // Get stock name and price from the user
        char name[MAX_NAME_LENGTH];
        double price;
        printf("Enter stock name and price (e.g. 'Apple 100'): ");
        scanf("%s %lf", name, &price);

        // Add stock to the array
        strcpy(stocks[i].name, name);
        stocks[i].price = price;
        numStocks++;
    }

    // Print the initial stock prices
    printf("\nInitial stock prices:\n");
    printStocks(stocks, numStocks);

    // Update the stock prices every second
    while (1) {
        updateStocks(stocks, numStocks);
        sleep(1);
    }

    return 0;
}

// Function to print a stock
void printStock(Stock* stock) {
    printf("%s: $%0.2f\n", stock->name, stock->price);
}

// Function to print all stocks
void printStocks(Stock* stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        printStock(&stocks[i]);
    }
}

// Function to update all stock prices
void updateStocks(Stock* stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        // Update the stock price randomly
        stocks[i].price = stocks[i].price + (rand() % 10 - 5);
    }
}