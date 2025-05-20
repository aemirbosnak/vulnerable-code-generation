//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Claude Shannon
/* 
Author: Claude Shannon
Date: January 1, 1951
Description: This program tracks the stock market, giving real-time updates on the prices of various stocks. It uses an algorithm that takes into account previous trends in the market and uses that information to predict future prices.

Assumptions: 
- The user has inputted the starting price for each stock
- The user has inputted the number of shares the user currently owns for each stock
- The user has inputted the name of each stock that they are tracking

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to represent each stock
typedef struct {
    char* name;
    double price;
    int sharesOwned;
} Stock;

// Function to generate a random price change
double generatePriceChange(double currentPrice) {
    double maxChange = 0.02 * currentPrice; // Max price change is 2% of current price
    double minChange = -maxChange; // Price can go up or down
    double priceChange = ((double) rand() / RAND_MAX) * (maxChange - minChange) + minChange; // Generate a random price change
    return priceChange;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Define an array of stocks
    Stock stocks[5];

    // Initialize each stock with user inputted values
    for (int i = 0; i < 5; i++) {
        // Allocate memory for stock name
        stocks[i].name = (char*) malloc(sizeof(char) * 20);

        // Get user input
        printf("Enter the name of stock %d: ", i+1);
        scanf("%s", stocks[i].name);
        printf("Enter the starting price of stock %d: ", i+1);
        scanf("%lf", &stocks[i].price);
        printf("Enter the number of shares of stock %d you currently own: ", i+1);
        scanf("%d", &stocks[i].sharesOwned);
    }

    // Print the initial values
    printf("\nInitial stock values:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - Price: %.2f, Shares owned: %d\n", stocks[i].name, stocks[i].price, stocks[i].sharesOwned);
    }

    // Run the simulation
    int numIterations = 10;
    for (int i = 1; i <= numIterations; i++) {
        printf("\nIteration %d:\n", i);

        // Generate a price change for each stock and update the price and value of each stock
        for (int j = 0; j < 5; j++) {
            double priceChange = generatePriceChange(stocks[j].price);
            stocks[j].price += priceChange;
            double value = stocks[j].price * stocks[j].sharesOwned;
            printf("%s - Price: %.2f (%+.2f%%), Value: %.2f\n", stocks[j].name, stocks[j].price, (priceChange / stocks[j].price) * 100, value);
        }

        // Wait for 5 seconds to simulate real-time updates
        printf("Waiting for 5 seconds...\n");
        sleep(5);
    }

    // Free memory allocated for stock names
    for (int i = 0; i < 5; i++) {
        free(stocks[i].name);
    }

    return 0;
}