//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

void readStocks(Stock stocks[], int numStocks) {
    FILE *fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %lf %d\n", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].quantity)!= EOF && i < numStocks) {
        i++;
    }

    fclose(fp);
}

void printStocks(Stock stocks[], int numStocks) {
    printf("Name\tSymbol\tPrice\tQuantity\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%-20s\t%-10s\t$%.2f\t%d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
}

void sortStocks(Stock stocks[], int numStocks, int (*compare)(const void *, const void *)) {
    qsort(stocks, numStocks, sizeof(Stock), compare);
}

int comparePrice(const void *a, const void *b) {
    const Stock *stockA = (const Stock *)a;
    const Stock *stockB = (const Stock *)b;

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
    numStocks = sizeof(stocks) / sizeof(stocks[0]);

    printf("Unsorted stocks:\n");
    printStocks(stocks, numStocks);

    sortStocks(stocks, numStocks, comparePrice);

    printf("\nSorted by price:\n");
    printStocks(stocks, numStocks);

    return 0;
}