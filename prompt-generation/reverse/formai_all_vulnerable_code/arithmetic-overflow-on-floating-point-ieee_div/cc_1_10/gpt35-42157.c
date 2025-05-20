//FormAI DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10
#define BUFFER_SIZE 1024

typedef struct {
    char* name;
    float currentPrice;
    float previousPrice;
    float changePercent;
} Stock;

Stock stocks[MAX_STOCKS];
int numStocks;

void printWelcomeMessage() {
    printf("Welcome to the Stock Market Tracker!\n");
    printf("Enter the names of up to %d stocks followed by their current price (separated by a space):\n", MAX_STOCKS);
}

void readStocks() {
    char buffer[BUFFER_SIZE];
    char* stockName;
    char* stockPriceString;
    float stockPrice;

    fgets(buffer, BUFFER_SIZE, stdin);

    char* token = strtok(buffer, " ");
    while (token != NULL) {
        if (numStocks >= MAX_STOCKS) {
            printf("Max number of stocks reached.\n");
            return;
        }

        stockName = token;
        stockPriceString = strtok(NULL, " ");
        stockPrice = atof(stockPriceString);

        // Create the new stock and add it to the array
        stocks[numStocks].name = strdup(stockName);
        stocks[numStocks].currentPrice = stockPrice;
        stocks[numStocks].previousPrice = stockPrice;
        stocks[numStocks].changePercent = 0.0;

        numStocks++;

        token = strtok(NULL, " ");
    }

    printf("Successfully read in %d stocks.\n", numStocks);
}

void updateStocks() {
    srand(time(NULL));

    for (int i = 0; i < numStocks; i++) {
        float change = (float)rand() / (float)(RAND_MAX / 10.0) - 5.0;
        stocks[i].previousPrice = stocks[i].currentPrice;
        stocks[i].currentPrice += change;
        stocks[i].changePercent = (stocks[i].currentPrice - stocks[i].previousPrice) / stocks[i].previousPrice * 100.0;
    }

    printf("\nStock prices updated.\n");
}

void printStocks() {
    printf("\nName\t\tCurrent Price\t\tPrevious Price\t\tChange (%)\n");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%-15s\t$ %-15.2f\t\t$ %-15.2f\t\t%.2f %%\n", stocks[i].name, stocks[i].currentPrice, stocks[i].previousPrice, stocks[i].changePercent);
    }
}

int main() {
    printWelcomeMessage();
    readStocks();

    char input;

    do {
        printf("\nPress ENTER to update stock prices (Q to quit): ");
        input = getchar();

        if (input == '\n') {
            updateStocks();
            printStocks();
        }
    } while (input != 'Q');

    printf("\nGoodbye!\n");

    return 0;
}