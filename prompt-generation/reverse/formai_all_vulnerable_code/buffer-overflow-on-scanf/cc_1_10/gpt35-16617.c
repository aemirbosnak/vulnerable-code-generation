//FormAI DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOL_LENGTH 10

// Define a struct for holding stock data
typedef struct StockData {
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
} StockData;

// Function to get stock data from user input
void getInput(StockData* stock) {
    printf("Enter the symbol for the stock: ");
    scanf("%s", stock->symbol);
    printf("Enter the current price for %s: $", stock->symbol);
    scanf("%lf", &stock->price);
}

// Function to display stock data
void displayStockData(StockData stock) {
    printf("Symbol: %s\tPrice: $%.2f\n", stock.symbol, stock.price);
}

int main() {
    char userChoice = ' ';
    StockData* stocks = NULL;
    int numStocks = 0;
    int maxStocks = 10;
    
    // Allocate memory for an array of StockData structs
    stocks = (StockData*)malloc(maxStocks * sizeof(StockData));
    if (stocks == NULL) {
        printf("Error allocating memory for stocks.\n");
        return 1;
    }
    
    while (userChoice != 'q') {
        printf("Enter 'a' to add a stock, 'd' to display all stocks, or 'q' to quit: ");
        scanf(" %c", &userChoice);
        
        if (userChoice == 'a') {
            // Check if we need to allocate more memory for the stocks array
            if (numStocks == maxStocks) {
                maxStocks += 10;
                stocks = (StockData*)realloc(stocks, maxStocks * sizeof(StockData));
                if (stocks == NULL) {
                    printf("Error reallocating memory for stocks.\n");
                    return 1;
                }
            }
            // Get stock data from user and add it to the stocks array
            getInput(&stocks[numStocks]);
            numStocks++;
        }
        else if (userChoice == 'd') {
            // Display all stocks in the stocks array
            for (int i=0; i<numStocks; i++) {
                displayStockData(stocks[i]);
            }
        }
    }
    
    // Free memory allocated for stocks array
    free(stocks);
    
    return 0;
}