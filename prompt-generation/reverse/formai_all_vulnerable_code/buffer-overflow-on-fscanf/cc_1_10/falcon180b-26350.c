//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
} Stock;

void readStocks(Stock stocks[]) {
    FILE *file = fopen("stocks.txt", "r");

    if (file == NULL) {
        printf("Error reading stocks file.\n");
        exit(1);
    }

    int numStocks = 0;

    while (fscanf(file, "%s %s %lf\n", stocks[numStocks].name, stocks[numStocks].symbol, &stocks[numStocks].price)!= EOF) {
        numStocks++;
    }

    fclose(file);
}

void printStock(Stock stock) {
    printf("%-20s %-10s $%.2f\n", stock.name, stock.symbol, stock.price);
}

void printStocks(Stock stocks[]) {
    printf("Stock Name         Symbol   Price\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            printStock(stocks[i]);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];

    readStocks(stocks);
    printStocks(stocks);

    return 0;
}