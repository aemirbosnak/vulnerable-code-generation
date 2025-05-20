//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10
#define MAX_CHANGE_LEN 10
#define MAX_PERCENT_CHANGE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int volume;
    double change;
    double percent_change;
} Stock;

void read_stocks(Stock stocks[], int num_stocks) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %lf %d %lf %lf\n", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].volume, &stocks[i].change, &stocks[i].percent_change) == 6) {
        i++;
        if (i >= num_stocks) {
            printf("Error: too many stocks in file\n");
            exit(1);
        }
    }

    fclose(fp);
}

void print_header() {
    printf("Name\tSymbol\tPrice\tVolume\tChange\t% Change\n");
}

void print_stock(Stock stock) {
    printf("%-20s %-10s $%.2f %10d $%.2f %.2f%%\n", stock.name, stock.symbol, stock.price, stock.volume, stock.change, stock.percent_change);
}

void print_stocks(Stock stocks[], int num_stocks) {
    print_header();
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    read_stocks(stocks, MAX_STOCKS);
    num_stocks = MAX_STOCKS;

    print_stocks(stocks, num_stocks);

    return 0;
}