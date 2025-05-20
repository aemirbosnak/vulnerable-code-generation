//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOLS 100
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10

typedef struct {
    char symbol[MAX_SYMBOLS];
    char name[MAX_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
} Stock;

void read_stocks(Stock stocks[], int num_stocks) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %s\n", stocks[i].symbol, stocks[i].name, stocks[i].price)!= EOF) {
        i++;
        if (i >= num_stocks) {
            printf("Warning: Reached maximum number of stocks (%d).\n", num_stocks);
            break;
        }
    }

    fclose(fp);
}

void print_stocks(Stock stocks[], int num_stocks) {
    printf("Stock Symbol\tName\tPrice\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s%-20s%-10s\n", stocks[i].symbol, stocks[i].name, stocks[i].price);
    }
}

int main() {
    Stock stocks[MAX_SYMBOLS];
    int num_stocks = 0;

    read_stocks(stocks, MAX_SYMBOLS);
    num_stocks = MAX_SYMBOLS;

    print_stocks(stocks, num_stocks);

    return 0;
}