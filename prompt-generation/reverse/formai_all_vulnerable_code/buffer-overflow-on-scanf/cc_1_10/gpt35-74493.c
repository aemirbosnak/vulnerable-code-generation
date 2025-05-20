//FormAI DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Create a list of stocks to track
    char* stockList[] = {"AAPL", "GOOG", "MSFT", "TSLA", "AMZN"};

    // Create an array to hold the daily prices for each stock
    float stockPrices[5];

    // Define a variable to hold the current day
    int dayNumber = 1;

    // Start tracking the stock prices
    while (dayNumber <= 5) {

        // Print the day number and ask the user to enter the prices for each stock
        printf("\nDay %d:\nEnter the stock prices for the following companies:\n", dayNumber);
        for (int i = 0; i < 5; i++) {
            printf("- %s: ", stockList[i]);
            scanf("%f", &stockPrices[i]);
        }

        // Print the daily stock report
        printf("\nDaily Stock Report:\n");
        for (int i = 0; i < 5; i++) {
            printf("%s: $%.2f\n", stockList[i], stockPrices[i]);
        }

        // Check for profitable stocks
        int profitableStocks = 0;
        for (int i = 0; i < 5; i++) {
            if (stockPrices[i] > 100) {
                profitableStocks++;
            }
        }

        // Print the number of profitable stocks
        printf("\n%d out of 5 stocks are currently priced above $100.\n", profitableStocks);

        // Increment the day counter
        dayNumber++;
    }

    // Print the final message
    printf("\nThanks for using the stock market tracker program!\n");

    return 0;
}