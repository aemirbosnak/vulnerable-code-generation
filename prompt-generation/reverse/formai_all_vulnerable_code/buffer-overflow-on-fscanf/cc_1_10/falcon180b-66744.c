//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 50
#define MAX_NAME_LEN 50
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

void read_stocks_data(Stock stocks[], int size) {
    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open stocks.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %s %s %s %s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume, stocks[i].change)!= EOF) {
        i++;
        if (i >= size) {
            printf("Error: Too many stocks in stocks.txt\n");
            exit(1);
        }
    }

    fclose(file);
}

void print_stock_data(Stock stock) {
    printf("Name: %s\n", stock.name);
    printf("Symbol: %s\n", stock.symbol);
    printf("Price: %s\n", stock.price);
    printf("Volume: %s\n", stock.volume);
    printf("Change: %s\n", stock.change);
    printf("\n");
}

void print_stocks_data(Stock stocks[], int size) {
    for (int i = 0; i < size; i++) {
        print_stock_data(stocks[i]);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int size = 0;

    read_stocks_data(stocks, MAX_STOCKS);
    size = MAX_STOCKS;

    print_stocks_data(stocks, size);

    return 0;
}