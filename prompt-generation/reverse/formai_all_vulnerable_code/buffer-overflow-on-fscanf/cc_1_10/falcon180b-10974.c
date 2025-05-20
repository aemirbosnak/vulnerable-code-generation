//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10
#define MAX_CHANGE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
    char change[MAX_CHANGE_LEN];
} Stock;

void load_stocks(Stock stocks[], int num_stocks) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %s %s %s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume, stocks[i].change) == 5) {
        i++;
        if (i == num_stocks) {
            break;
        }
    }

    fclose(fp);
}

void display_stocks(Stock stocks[], int num_stocks) {
    printf("Name\tSymbol\tPrice\tVolume\tChange\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s %-10s %-10s %-10s %-10s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume, stocks[i].change);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    load_stocks(stocks, MAX_STOCKS);
    num_stocks = MAX_STOCKS;

    display_stocks(stocks, num_stocks);

    return 0;
}