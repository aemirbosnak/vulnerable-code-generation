//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 10

// Define the structure of a stock
typedef struct {
    char symbol[10];
    double price;
    double change;
} Stock;

// Function to print the stock information
void printStock(Stock stock) {
    printf("%s: $%.2f (%.2f%%)\n", stock.symbol, stock.price, stock.change);
}

// Function to update the stock information
void updateStock(Stock *stock, double newPrice) {
    double oldPrice = stock->price;
    stock->price = newPrice;
    stock->change = (newPrice - oldPrice) / oldPrice * 100;
}

// Function to get the stock information from the user
Stock getStockInfo() {
    Stock stock;
    printf("Enter stock symbol: ");
    scanf("%s", stock.symbol);
    printf("Enter stock price: ");
    scanf("%lf", &stock.price);
    stock.change = 0.0;
    return stock;
}

// Function to main program
int main() {
    // Create an array of stocks
    Stock stocks[MAX_STOCKS];

    // Get the number of stocks to track
    int numStocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &numStocks);

    // Get the stock information for each stock
    for (int i = 0; i < numStocks; i++) {
        stocks[i] = getStockInfo();
    }

    // Print the stock information
    printf("\nCurrent stock information:\n");
    for (int i = 0; i < numStocks; i++) {
        printStock(stocks[i]);
    }

    // Update the stock information
    for (int i = 0; i < numStocks; i++) {
        double newPrice;
        printf("Enter new price for %s: ", stocks[i].symbol);
        scanf("%lf", &newPrice);
        updateStock(&stocks[i], newPrice);
    }

    // Print the updated stock information
    printf("\nUpdated stock information:\n");
    for (int i = 0; i < numStocks; i++) {
        printStock(stocks[i]);
    }

    return 0;
}