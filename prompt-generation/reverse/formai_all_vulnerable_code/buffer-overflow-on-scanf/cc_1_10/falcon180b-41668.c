//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: automated
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

void readStocks(Stock stocks[], int n) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %lf %d\n", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].quantity) == 4 && i < n) {
        i++;
    }

    fclose(fp);
}

void printStock(const Stock *stock) {
    printf("%-20s %-10s $%.2f %d\n", stock->name, stock->symbol, stock->price, stock->quantity);
}

void sortStocks(Stock stocks[], int n) {
    qsort(stocks, n, sizeof(Stock), (int (*)(const void *, const void *))strcmp);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int n;

    printf("Enter the number of stocks (up to %d): ", MAX_STOCKS);
    scanf("%d", &n);

    readStocks(stocks, n);
    sortStocks(stocks, n);

    printf("Stock Portfolio:\n");
    for (int i = 0; i < n; i++) {
        printStock(&stocks[i]);
    }

    return 0;
}