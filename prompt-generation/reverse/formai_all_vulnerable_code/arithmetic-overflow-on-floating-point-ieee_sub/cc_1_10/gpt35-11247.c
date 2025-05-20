//FormAI DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define a struct to hold the stock information
typedef struct StockInfo {
    char ticker[10];
    float currentPrice;
    float previousClose;
    float percentChange;
} StockInfo;

// Function to parse a string into a StockInfo struct
StockInfo parseStockInfo(char* input) {
    StockInfo stock;

    char* token = strtok(input, ",");
    strcpy(stock.ticker, token);

    token = strtok(NULL, ",");
    stock.currentPrice = atof(token);

    token = strtok(NULL, ",");
    stock.previousClose = atof(token);

    stock.percentChange = ((stock.currentPrice - stock.previousClose) / stock.previousClose) * 100;

    return stock;
}

int main() {
    char input[50];

    // Initialize the array to hold the stock information
    StockInfo stocks[5];

    // Prompt the user to enter the stock information
    printf("Enter the stock information (ticker, current price, previous close): \n");

    // Loop through and get the stock information for each stock
    for (int i = 0; i < 5; i++) {
        fgets(input, sizeof(input), stdin);
        stocks[i] = parseStockInfo(input);
    }

    // Output the stock information
    printf("\n\nStock prices:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: $%.2f (%+.2f%%)\n", stocks[i].ticker, stocks[i].currentPrice, stocks[i].percentChange);
    }

    return 0;
}