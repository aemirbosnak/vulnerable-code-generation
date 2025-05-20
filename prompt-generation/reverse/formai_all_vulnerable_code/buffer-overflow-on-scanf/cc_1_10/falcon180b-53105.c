//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

int compare_stocks(const void *a, const void *b) {
    const Stock *stock_a = (const Stock *)a;
    const Stock *stock_b = (const Stock *)b;

    return strcmp(stock_a->symbol, stock_b->symbol);
}

void print_stock(const Stock *stock) {
    printf("Name: %s\n", stock->name);
    printf("Symbol: %s\n", stock->symbol);
    printf("Price: $%.2f\n\n", stock->price);
}

int main() {
    int num_stocks;
    Stock stocks[MAX_STOCKS];

    printf("Enter the number of stocks to track (up to %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter stock %d information:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", stocks[i].name);
        printf("Symbol: ");
        scanf(" %[^\n]", stocks[i].symbol);
        printf("Price: ");
        scanf(" %lf", &stocks[i].price);
    }

    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks);

    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}