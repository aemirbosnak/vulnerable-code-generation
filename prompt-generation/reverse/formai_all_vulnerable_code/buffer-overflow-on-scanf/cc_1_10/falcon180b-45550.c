//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100
#define MAX_PRICE_HISTORY 1000

typedef struct {
    char symbol[10];
    double price;
} Stock;

typedef struct {
    Stock stocks[MAX_SYMBOLS];
    int num_stocks;
} Portfolio;

void init_portfolio(Portfolio* portfolio) {
    portfolio->num_stocks = 0;
}

void add_stock(Portfolio* portfolio, char* symbol, double price) {
    if (portfolio->num_stocks >= MAX_SYMBOLS) {
        printf("Error: portfolio is full.\n");
        return;
    }

    strcpy(portfolio->stocks[portfolio->num_stocks].symbol, symbol);
    portfolio->stocks[portfolio->num_stocks].price = price;
    portfolio->num_stocks++;
}

void print_portfolio(Portfolio* portfolio) {
    printf("Portfolio:\n");
    for (int i = 0; i < portfolio->num_stocks; i++) {
        printf("%s %.2f\n", portfolio->stocks[i].symbol, portfolio->stocks[i].price);
    }
}

void track_stock(Stock* stock, int history_size, double* prices) {
    int i = 0;
    while (i < history_size - 1) {
        prices[i] = prices[i + 1];
        i++;
    }

    stock->price = prices[history_size - 1];
    prices[history_size - 1] = 0;
}

int main() {
    Portfolio portfolio;
    init_portfolio(&portfolio);

    char symbol[10];
    double price;

    while (1) {
        printf("Enter stock symbol: ");
        scanf("%s", symbol);

        printf("Enter stock price: ");
        scanf("%lf", &price);

        add_stock(&portfolio, symbol, price);
    }

    return 0;
}