//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_SHARES 1000000

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int shares;
    double total_value;
} Stock;

void print_stock(Stock stock) {
    printf("Name: %s\n", stock.name);
    printf("Symbol: %s\n", stock.symbol);
    printf("Price: $%.2f\n", stock.price);
    printf("Shares: %d\n", stock.shares);
    printf("Total Value: $%.2f\n", stock.total_value);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open stocks file.\n");
        exit(1);
    }

    char line[256];
    while (fgets(line, 256, fp)!= NULL) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: too many stocks in file.\n");
            exit(1);
        }

        char name[MAX_NAME_LEN];
        char symbol[MAX_SYMBOL_LEN];
        double price;
        int shares;

        sscanf(line, "%s %s %lf %d", name, symbol, &price, &shares);

        strncpy(stocks[num_stocks].name, name, MAX_NAME_LEN);
        strncpy(stocks[num_stocks].symbol, symbol, MAX_SYMBOL_LEN);
        stocks[num_stocks].price = price;
        stocks[num_stocks].shares = shares;
        stocks[num_stocks].total_value = price * shares;

        num_stocks++;
    }

    fclose(fp);

    printf("Number of stocks: %d\n", num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}