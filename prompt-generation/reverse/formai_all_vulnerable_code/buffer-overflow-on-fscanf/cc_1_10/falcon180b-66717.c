//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
    int quantity;
} Stock;

void readStocksFromFile(Stock stocks[], int *numStocks) {
    FILE *fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    *numStocks = 0;

    while (fscanf(fp, "%s %lf %d\n", stocks[*numStocks].name, &stocks[*numStocks].price, &stocks[*numStocks].quantity)!= EOF) {
        (*numStocks)++;
    }

    fclose(fp);
}

void printStock(Stock stock) {
    printf("%-20s $%.2f x %d\n", stock.name, stock.price, stock.quantity);
}

void sortStocksByPrice(Stock stocks[], int numStocks) {
    for (int i = 0; i < numStocks - 1; i++) {
        for (int j = i + 1; j < numStocks; j++) {
            if (stocks[i].price > stocks[j].price) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

void main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    readStocksFromFile(stocks, &numStocks);

    printf("Stock Market Tracker\n");
    printf("---------------------\n");

    sortStocksByPrice(stocks, numStocks);

    for (int i = 0; i < numStocks; i++) {
        printStock(stocks[i]);
    }

    printf("\nThank you for using our Stock Market Tracker. We hope it has been a delightful experience for you.\n");
}