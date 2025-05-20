//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_LENGTH 20
#define MAX_VOLUME_LENGTH 20
#define MAX_PERCENT_CHANGE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int volume;
    double percent_change;
} Stock;

void read_stocks(Stock stocks[], int num_stocks) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %lf %d %lf\n", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].volume, &stocks[i].percent_change) == 5 && i < num_stocks) {
        i++;
    }

    fclose(fp);
}

void print_stocks(Stock stocks[], int num_stocks) {
    printf("Name\tSymbol\tPrice\tVolume\t% Change\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s\t%-10s\t%.2f\t%d\t%.2f%%\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume, stocks[i].percent_change);
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