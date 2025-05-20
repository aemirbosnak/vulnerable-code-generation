//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the stock market tracker structure
typedef struct StockMarketTracker {
    char name[20];
    int currentPrice;
    int previousPrice;
    double change;
    double percentageChange;
} StockMarketTracker;

// Function to get the stock market data from a file
void getStockMarketData(StockMarketTracker* tracker) {
    FILE* file = fopen("stockMarketData.txt", "r");
    if (file) {
        fscanf(file, "%s %d %d %lf %lf", tracker->name, &tracker->currentPrice, &tracker->previousPrice, &tracker->change, &tracker->percentageChange);
        fclose(file);
    } else {
        printf("Error reading stock market data file.\n");
    }
}

// Function to calculate the change and percentage change
void calculateChange(StockMarketTracker* tracker) {
    tracker->change = (double)(tracker->currentPrice - tracker->previousPrice);
    tracker->percentageChange = (double)(tracker->change / tracker->previousPrice) * 100;
}

// Function to print the stock market tracker data
void printStockMarketTrackerData(StockMarketTracker* tracker) {
    printf("%s: $%d, Change: $%.2lf, Percentage Change: %.2lf%\n", tracker->name, tracker->currentPrice, tracker->change, tracker->percentageChange);
}

int main() {
    // Create a stock market tracker structure
    StockMarketTracker tracker;

    // Get the stock market data from the file
    getStockMarketData(&tracker);

    // Calculate the change and percentage change
    calculateChange(&tracker);

    // Print the stock market tracker data
    printStockMarketTrackerData(&tracker);

    return 0;
}