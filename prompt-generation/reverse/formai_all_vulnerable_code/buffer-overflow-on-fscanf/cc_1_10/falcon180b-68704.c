//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

void read_stocks(Stock stocks[], int num_stocks) {
    FILE *fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %lf %d\n", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].quantity) == 4 && i < num_stocks) {
        i++;
    }

    fclose(fp);
}

void print_stock(Stock stock) {
    printf("%-20s %-10s $%.2f %d\n", stock.name, stock.symbol, stock.price, stock.quantity);
}

void sort_stocks(Stock stocks[], int num_stocks) {
    for (int i = 0; i < num_stocks - 1; i++) {
        for (int j = i + 1; j < num_stocks; j++) {
            if (stocks[j].price < stocks[i].price) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    read_stocks(stocks, MAX_STOCKS);
    num_stocks = (int)fmin(num_stocks, MAX_STOCKS);

    printf("Stock Market Tracker\n");
    printf("--------------------\n");

    sort_stocks(stocks, num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}