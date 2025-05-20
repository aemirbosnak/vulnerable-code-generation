//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store stock information
typedef struct Stock {
    char symbol[10];
    float open;
    float high;
    float low;
    float close;
    float volume;
} Stock;

// Function to compare two stocks by their closing price
int compareStocks(const void *a, const void *b) {
    const Stock *stock1 = (const Stock *)a;
    const Stock *stock2 = (const Stock *)b;

    if (stock1->close > stock2->close) {
        return -1;
    } else if (stock1->close < stock2->close) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print stock information
void printStock(const Stock *stock) {
    printf("Symbol: %s\n", stock->symbol);
    printf("Open: %.2f\n", stock->open);
    printf("High: %.2f\n", stock->high);
    printf("Low: %.2f\n", stock->low);
    printf("Close: %.2f\n", stock->close);
    printf("Volume: %.2f\n\n", stock->volume);
}

// Main function
int main() {
    // Get the number of stocks from the user
    int numStocks;
    printf("Enter the number of stocks: ");
    scanf("%d", &numStocks);

    // Allocate memory for the array of stocks
    Stock *stocks = (Stock *)malloc(sizeof(Stock) * numStocks);

    // Get the data for each stock
    for (int i = 0; i < numStocks; i++) {
        printf("Enter the data for stock %d:\n", i + 1);

        printf("Symbol: ");
        scanf("%s", stocks[i].symbol);

        printf("Open: ");
        scanf("%f", &stocks[i].open);

        printf("High: ");
        scanf("%f", &stocks[i].high);

        printf("Low: ");
        scanf("%f", &stocks[i].low);

        printf("Close: ");
        scanf("%f", &stocks[i].close);

        printf("Volume: ");
        scanf("%f", &stocks[i].volume);

        printf("\n");
    }

    // Sort the stocks by their closing price
    qsort(stocks, numStocks, sizeof(Stock), compareStocks);

    // Print the sorted stocks
    printf("Sorted stocks by closing price:\n");
    for (int i = 0; i < numStocks; i++) {
        printStock(&stocks[i]);
    }

    // Free the memory allocated for the array of stocks
    free(stocks);

    return 0;
}