//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int quantity;
} Stock;

void loadStocks(Stock stocks[], int numStocks) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error loading stocks.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %lf %d", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].quantity) == 4 && i < numStocks) {
        i++;
    }

    fclose(fp);
}

void saveStocks(Stock stocks[], int numStocks) {
    FILE *fp = fopen("stocks.txt", "w");
    if (fp == NULL) {
        printf("Error saving stocks.\n");
        exit(1);
    }

    for (int i = 0; i < numStocks; i++) {
        fprintf(fp, "%s %s %lf %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }

    fclose(fp);
}

void printStock(Stock stock) {
    printf("%-20s %-10s $%.2lf %d\n", stock.name, stock.symbol, stock.price, stock.quantity);
}

void printStocks(Stock stocks[], int numStocks) {
    printf("Name\tSymbol\tPrice\tQuantity\n");
    for (int i = 0; i < numStocks; i++) {
        printStock(stocks[i]);
    }
}

int main() {
    srand(time(NULL));

    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    loadStocks(stocks, MAX_STOCKS);
    numStocks = rand() % MAX_STOCKS + 1;

    for (int i = 0; i < numStocks; i++) {
        stocks[i].price += rand() % 101 - 50;
        stocks[i].quantity += rand() % 101 - 50;
    }

    saveStocks(stocks, numStocks);

    printf("Stock Market Tracker\n");
    printStocks(stocks, numStocks);

    return 0;
}