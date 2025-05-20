//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Stock Market Tracker structure
typedef struct StockMarketTracker {
    char name[50];
    double currentPrice;
    double previousPrice;
    double change;
} StockMarketTracker;

// Function to update the stock market tracker
void updateStockMarketTracker(StockMarketTracker *tracker) {
    printf("Enter the current price of %s: ", tracker->name);
    scanf("%lf", &tracker->currentPrice);

    // Calculate the change in price
    tracker->change = (tracker->currentPrice - tracker->previousPrice) / tracker->previousPrice * 100;

    // Update the previous price
    tracker->previousPrice = tracker->currentPrice;
}

// Function to display the stock market tracker
void displayStockMarketTracker(StockMarketTracker *tracker) {
    printf("Name: %s\n", tracker->name);
    printf("Current Price: %.2lf\n", tracker->currentPrice);
    printf("Previous Price: %.2lf\n", tracker->previousPrice);
    printf("Change: %.2lf%%\n", tracker->change);
    printf("\n");
}

int main() {
    // Create a stock market tracker
    StockMarketTracker tracker;

    // Initialize the tracker
    strcpy(tracker.name, "Apple");
    tracker.currentPrice = 100.00;
    tracker.previousPrice = 90.00;

    // Update the tracker
    updateStockMarketTracker(&tracker);

    // Display the tracker
    displayStockMarketTracker(&tracker);

    return 0;
}