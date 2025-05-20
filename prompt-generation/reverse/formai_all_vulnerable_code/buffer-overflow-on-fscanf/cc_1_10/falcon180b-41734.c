//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

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
        printf("Error: could not open stocks file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %lf %d\n", stocks[count].name, stocks[count].symbol, &stocks[count].price, &stocks[count].quantity) == 4) {
        count++;
        if (count >= n) {
            printf("Warning: stocks file contains more than %d stocks.\n", n);
            break;
        }
    }

    fclose(fp);
}

void printStocks(Stock stocks[], int n) {
    printf("Name\tSymbol\tPrice\tQuantity\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10s $%.2f %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
}

void calculateTotalValue(Stock stocks[], int n) {
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        totalValue += stocks[i].price * stocks[i].quantity;
    }
    printf("Total value of stocks: $%.2f\n", totalValue);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int n = 0;

    readStocks(stocks, MAX_STOCKS);
    n = (n > MAX_STOCKS)? MAX_STOCKS : n;

    printStocks(stocks, n);
    calculateTotalValue(stocks, n);

    return 0;
}