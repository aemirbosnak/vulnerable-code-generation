//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_DIGITS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int change;
    int change_percent;
} Stock;

void read_stocks(Stock stocks[], int num_stocks) {
    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("Error opening stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (i < num_stocks && fscanf(file, "%s %s %lf %d %d", 
                                  stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].change, &stocks[i].change_percent) == 5) {
        i++;
    }

    fclose(file);
}

void print_stock(Stock stock) {
    printf("%-20s %-10s $%.2f +%.2f (+%.2f%%)\n", 
           stock.name, stock.symbol, stock.price, stock.change, stock.change_percent);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    read_stocks(stocks, MAX_STOCKS);
    num_stocks = (int)fmin(num_stocks, MAX_STOCKS);

    printf("Stock Market Tracker\n");
    printf("===================\n");

    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}