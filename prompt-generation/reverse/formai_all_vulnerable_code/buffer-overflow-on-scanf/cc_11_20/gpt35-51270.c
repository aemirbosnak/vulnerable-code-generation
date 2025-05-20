//FormAI DATASET v1.0 Category: Stock market tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to store stock information
typedef struct Stock {
    char symbol[10];
    float price;
    int volume;
} Stock;

int main() {
    int numStocks, numDays;

    printf("Welcome to the Stock Market Tracker!\n");

    printf("How many stocks would you like to track? ");
    scanf("%d", &numStocks);

    // Allocate memory for array of stocks
    Stock *stocks = malloc(numStocks * sizeof(Stock));

    // Initialize stocks
    for (int i = 0; i < numStocks; i++) {
        printf("Enter the symbol for stock %d: ", i+1);
        scanf("%s", stocks[i].symbol);
        printf("Enter the starting price for stock %d: ", i+1);
        scanf("%f", &stocks[i].price);
        printf("Enter the starting volume for stock %d: ", i+1);
        scanf("%d", &stocks[i].volume);
    }

    printf("How many days would you like to track? ");
    scanf("%d", &numDays);

    // Allocate memory for array of arrays to store daily prices
    float **dailyPrices = malloc(numStocks * sizeof(float *));
    for (int i = 0; i < numStocks; i++) {
        dailyPrices[i] = malloc(numDays * sizeof(float));
    }

    // Initialize daily prices
    for (int i = 0; i < numStocks; i++) {
        for (int j = 0; j < numDays; j++) {
            printf("Enter the price for stock %s on day %d: ", stocks[i].symbol, j+1);
            scanf("%f", &dailyPrices[i][j]);
        }
    }

    // Print out stock information
    printf("\nStock information:\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%s:\n", stocks[i].symbol);
        printf("\tStarting price: $%.2f\n", stocks[i].price);
        printf("\tStarting volume: %d\n", stocks[i].volume);
        printf("\tDaily prices: ");
        for (int j = 0; j < numDays; j++) {
            printf("$%.2f ", dailyPrices[i][j]);
        }
        printf("\n");
    }

    // Calculate average daily prices
    printf("\nAverage daily prices:\n");

    for (int i = 0; i < numStocks; i++) {
        float sum = 0;
        for (int j = 0; j < numDays; j++) {
            sum += dailyPrices[i][j];
        }
        float avg = sum / numDays;
        printf("%s: $%.2f\n", stocks[i].symbol, avg);
    }

    // Sort stocks by volume
    for (int i = 0; i < numStocks-1; i++) {
        for (int j = i+1; j < numStocks; j++) {
            if (stocks[i].volume < stocks[j].volume) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;

                float *tempPrices = dailyPrices[i];
                dailyPrices[i] = dailyPrices[j];
                dailyPrices[j] = tempPrices;
            }
        }
    }

    // Print out sorted stock information
    printf("\nStock information (sorted by volume):\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%s:\n", stocks[i].symbol);
        printf("\tStarting price: $%.2f\n", stocks[i].price);
        printf("\tStarting volume: %d\n", stocks[i].volume);
        printf("\tDaily prices: ");
        for (int j = 0; j < numDays; j++) {
            printf("$%.2f ", dailyPrices[i][j]);
        }
        printf("\n");
    }

    // Free memory used by arrays
    for (int i = 0; i < numStocks; i++) {
        free(dailyPrices[i]);
    }
    free(dailyPrices);
    free(stocks);

    return 0;
}