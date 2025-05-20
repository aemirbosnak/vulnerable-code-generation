//FormAI DATASET v1.0 Category: Stock market tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to print the current stock price
void printStockPrice(float price) {
    printf("Current stock price is: %.2f\n", price);
}

// Function to calculate the average price of the stock
float calculateAveragePrice(float* priceList, int numOfPrices) {
    float totalPrice = 0.0;
    for (int i = 0; i < numOfPrices; i++) {
        totalPrice += priceList[i];
    }
    return totalPrice / numOfPrices;
}

int main() {

    // Get user input for initial stock price
    float initialStockPrice;
    printf("Enter the initial stock price: ");
    scanf("%f", &initialStockPrice);

    // An array to store the latest stock prices
    float latestPrices[10];
    latestPrices[0] = initialStockPrice;

    // Keep track of number of prices in the array
    int numOfPrices = 1;

    // Loop to simulate fluctuating stock prices
    for (int i = 1; i <= 50; i++) {
        // Generate a random change in stock price
        float changeInPrice = ((float)rand()/(float)(RAND_MAX)) * 10 - 5;
        // Calculate the new stock price
        float newPrice = latestPrices[numOfPrices-1] + changeInPrice;
        // Update the stock price array
        latestPrices[numOfPrices] = newPrice;
        numOfPrices += 1;
        // Print the new stock price
        printf("Day %d: ", i);
        printStockPrice(newPrice);
        // Calculate the average stock price
        float averagePrice = calculateAveragePrice(latestPrices, numOfPrices);
        printf("Average price over the last %d days is: %.2f\n", numOfPrices, averagePrice);
    }

    return 0;
}