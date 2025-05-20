//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_STOCK_NAME_LENGTH 50
#define MAX_STOCK_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_STOCK_NAME_LENGTH];
    char symbol[MAX_STOCK_SYMBOL_LENGTH];
    double price;
    int quantity;
} Stock;

void readStocks(Stock stocks[], int numStocks) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %lf %d\n", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].quantity)!= EOF) {
        i++;
    }

    fclose(fp);
}

void printStocks(Stock stocks[], int numStocks) {
    printf("Name\tSymbol\tPrice\tQuantity\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s\t%s\t%.2lf\t%d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
}

void sortStocks(Stock stocks[], int numStocks, int (*compare)(const void *, const void *)) {
    qsort(stocks, numStocks, sizeof(Stock), compare);
}

int comparePrice(const void *a, const void *b) {
    const Stock *stockA = a;
    const Stock *stockB = b;

    if (stockA->price < stockB->price) {
        return -1;
    } else if (stockA->price > stockB->price) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    readStocks(stocks, MAX_STOCKS);
    numStocks = fmin(numStocks, MAX_STOCKS);

    printStocks(stocks, numStocks);

    sortStocks(stocks, numStocks, comparePrice);
    printf("\nSorted by price:\n");
    printStocks(stocks, numStocks);

    return 0;
}