//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
} Stock;

void readStocks(Stock stocks[]) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open stocks.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %s %s\n", stocks[count].name, stocks[count].symbol, stocks[count].price, stocks[count].volume)!= EOF) {
        count++;
        if (count == MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached\n");
            exit(1);
        }
    }

    fclose(fp);
}

void printStocks(Stock stocks[]) {
    printf("Name\tSymbol\tPrice\tVolume\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            printf("%-20s %-10s %-10s %-10s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume);
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];

    readStocks(stocks);
    printStocks(stocks);

    return 0;
}