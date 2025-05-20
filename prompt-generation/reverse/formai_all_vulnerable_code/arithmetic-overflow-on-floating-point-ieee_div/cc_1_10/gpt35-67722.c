//FormAI DATASET v1.0 Category: Stock market tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 50
#define MAX_SYMBOL_LEN 10

// Define the stock structure
typedef struct stock {
    char symbol[MAX_SYMBOL_LEN];
    float price;
    float change;
    float percent_change;
} Stock;

// Function to fetch the current price of a stock
float getStockPrice(char *symbol) {
    // Generate a random price between 0 and 100
    float price = ((float)rand()/(float)(RAND_MAX)) * 100.0;
    return price;
}

// Function to update the stock data
void updateStockData(Stock *s) {
    s->price = getStockPrice(s->symbol);
    // Generate a random change between -10 and 10
    s->change = (((float)rand()/(float)(RAND_MAX)) * 20.0) - 10.0;
    s->percent_change = (s->change / s->price) * 100.0;
}

// Function to display the stock data
void printStockData(Stock *s) {
    printf("%s: %.2f (%+.2f / %.2f%%)\n", s->symbol, s->price, s->change, s->percent_change);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Define an array of stocks
    Stock stocks[MAX_STOCKS] = {
        {"AAPL", 0.0, 0.0, 0.0},
        {"GOOG", 0.0, 0.0, 0.0},
        {"AMZN", 0.0, 0.0, 0.0},
        {"MSFT", 0.0, 0.0, 0.0},
        {"FB", 0.0, 0.0, 0.0}
    };
    int num_stocks = 5; // The number of stocks in the array
    
    // Continuously update and display the stock data
    while (1) {
        // Update the data for each stock
        for (int i = 0; i < num_stocks; i++) {
            updateStockData(&stocks[i]);
            printStockData(&stocks[i]);
        }
        printf("\n"); // Add a blank line between iterations
        // Sleep for 1 second before updating the data again
        #ifdef _WIN32
        Sleep(1000);
        #else
        sleep(1);
        #endif
    }
    
    return 0;
}