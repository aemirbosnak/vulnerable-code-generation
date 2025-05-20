//FormAI DATASET v1.0 Category: Stock market tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 20

// Define the size of the stock symbol array
#define SYMBOL_SIZE 10

// Define a struct to store the stock data
typedef struct {
    char symbol[SYMBOL_SIZE];
    double price;
    double change;
    double percent_change;
} Stock;

int main() {
    
    // Declare an array to hold the stock information
    Stock stocks[MAX_STOCKS];
    
    // Initialize the array with dummy data
    for(int i = 0; i < MAX_STOCKS; i++) {
        snprintf(stocks[i].symbol, SYMBOL_SIZE, "STK%i", i+1);
        stocks[i].price = (double)rand()/(double)(RAND_MAX/100.0);
        stocks[i].change = (double)rand()/(double)(RAND_MAX/10.0);
        stocks[i].percent_change = (stocks[i].change / stocks[i].price) * 100.0;
    }
    
    // Print the initial stock information
    printf("Initial Stock Information:\n");
    printf("Symbol\tPrice\tChange\tPercent Change\n");
    for(int i = 0; i < MAX_STOCKS; i++) {
        printf("%s\t%.2lf\t%.2lf\t%.2lf%%\n", stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percent_change);
    }
    
    // Wait for user input to update the stock prices
    printf("\nPress enter to update stock prices.\n");
    getchar();
    
    // Update the stock prices with random values
    for(int i = 0; i < MAX_STOCKS; i++) {
        stocks[i].price += (double)rand()/(double)(RAND_MAX/10.0);
        stocks[i].change = stocks[i].price - stocks[i].change;
        stocks[i].percent_change = (stocks[i].change / stocks[i].price) * 100.0;
    }
    
    // Print the updated stock information
    printf("\nUpdated Stock Information:\n");
    printf("Symbol\tPrice\tChange\tPercent Change\n");
    for(int i = 0; i < MAX_STOCKS; i++) {
        printf("%s\t%.2lf\t%.2lf\t%.2lf%%\n", stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percent_change);
    }
    
    return 0;
}