//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 10
#define MAX_STOCK_NAME_LEN 20
#define MAX_STOCK_SYMBOL_LEN 10
#define MAX_STOCK_PRICE_DECIMALS 2

typedef struct {
    char name[MAX_STOCK_NAME_LEN];
    char symbol[MAX_STOCK_SYMBOL_LEN];
    float price;
    float change;
    float percent_change;
} Stock;

void print_stock(Stock *stock) {
    printf("%-20s %-10s $%.2f $%.2f %.2f%%\n", stock->name, stock->symbol, stock->price, stock->change, stock->percent_change);
}

int compare_stocks(const void *a, const void *b) {
    const Stock *stock_a = a;
    const Stock *stock_b = b;

    if (stock_a->price < stock_b->price) {
        return -1;
    } else if (stock_a->price > stock_b->price) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_stocks;
    printf("Enter the number of stocks to track (max %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    Stock stocks[MAX_STOCKS];
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter stock %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", stocks[i].name);
        printf("Symbol: ");
        scanf("%s", stocks[i].symbol);
        printf("Price: $");
        scanf("%f", &stocks[i].price);
    }

    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks);

    printf("\nStock Market Tracker\n");
    printf("---------------------\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}