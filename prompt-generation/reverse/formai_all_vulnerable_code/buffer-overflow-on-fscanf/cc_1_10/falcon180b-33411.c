//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_STOCK_NAME_LENGTH 50
#define MAX_STOCK_SYMBOL_LENGTH 10
#define MAX_STOCK_PRICE_LENGTH 10
#define MAX_STOCK_VOLUME_LENGTH 10
#define MAX_STOCK_CHANGE_LENGTH 10

typedef struct {
    char name[MAX_STOCK_NAME_LENGTH];
    char symbol[MAX_STOCK_SYMBOL_LENGTH];
    char price[MAX_STOCK_PRICE_LENGTH];
    char volume[MAX_STOCK_VOLUME_LENGTH];
    char change[MAX_STOCK_CHANGE_LENGTH];
} Stock;

void loadStocks(Stock* stocks, int numStocks, FILE* file) {
    for (int i = 0; i < numStocks; i++) {
        fscanf(file, "%s %s %s %s %s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume, stocks[i].change);
    }
}

void printStock(Stock stock) {
    printf("%s (%s): $%.2f %.2f %.2f\n", stock.name, stock.symbol, atof(stock.price), atof(stock.volume), atof(stock.change));
}

void sortStocks(Stock* stocks, int numStocks, int (*compare)(const void*, const void*)) {
    qsort(stocks, numStocks, sizeof(Stock), compare);
}

int comparePrice(const void* a, const void* b) {
    Stock* stockA = (Stock*)a;
    Stock* stockB = (Stock*)b;
    return atof(stockA->price) - atof(stockB->price);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    // Load stocks from file
    FILE* file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("Error: could not open stocks file.\n");
        return 1;
    }

    while (fscanf(file, "%s %s %s %s %s\n", stocks[numStocks].name, stocks[numStocks].symbol, stocks[numStocks].price, stocks[numStocks].volume, stocks[numStocks].change)!= EOF) {
        numStocks++;
    }

    fclose(file);

    // Sort stocks by price
    sortStocks(stocks, numStocks, comparePrice);

    // Print stocks
    printf("Sorted by Price:\n");
    for (int i = 0; i < numStocks; i++) {
        printStock(stocks[i]);
    }

    return 0;
}