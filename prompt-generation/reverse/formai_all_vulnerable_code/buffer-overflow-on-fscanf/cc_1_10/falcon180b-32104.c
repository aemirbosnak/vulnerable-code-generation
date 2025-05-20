//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 50
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

// Define the structure for a stock
typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

void readStocksFromFile(Stock stocks[], int numStocks) {
    FILE *fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Could not open stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %lf\n", stocks[i].name, stocks[i].symbol, &stocks[i].price) == 3) {
        i++;
        if (i >= numStocks) {
            break;
        }
    }

    fclose(fp);
}

void printStock(Stock stock) {
    printf("%-20s %-10s $%.2f\n", stock.name, stock.symbol, stock.price);
}

void sortStocksByPrice(Stock stocks[], int numStocks) {
    for (int i = 0; i < numStocks - 1; i++) {
        for (int j = i + 1; j < numStocks; j++) {
            if (stocks[j].price < stocks[i].price) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    readStocksFromFile(stocks, MAX_STOCKS);
    numStocks = MAX_STOCKS;

    printf("Romeo and Juliet's Stock Market Tracker\n\n");
    printf("+-----------------+-------------------+---------------+\n");
    printf("| Name            | Symbol            | Price          |\n");
    printf("+-----------------+-------------------+---------------+\n");

    sortStocksByPrice(stocks, numStocks);

    for (int i = 0; i < numStocks; i++) {
        printStock(stocks[i]);
    }

    return 0;
}