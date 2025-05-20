//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 50
#define MAX_SYMBOLS 10
#define MAX_PRICES 100

typedef struct {
    char symbol[MAX_SYMBOLS];
    int num_prices;
    double prices[MAX_PRICES];
} Stock;

void add_price(Stock *s, double price) {
    if (s->num_prices >= MAX_PRICES) {
        printf("Error: Stock %s has reached maximum number of prices.\n", s->symbol);
        return;
    }
    s->prices[s->num_prices++] = price;
}

void print_stock(Stock *s) {
    printf("Stock: %s\n", s->symbol);
    for (int i = 0; i < s->num_prices; i++) {
        printf("Price %d: $%.2f\n", i+1, s->prices[i]);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    char input[100];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            break;
        }
        if (sscanf(input, "ADD %s", stocks[num_stocks].symbol)!= 1) {
            printf("Error: Invalid stock symbol.\n");
            continue;
        }
        num_stocks++;
    }

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (sscanf(input, "PRICE %s $%.2f", stocks[--num_stocks].symbol, &stocks[num_stocks].prices[stocks[num_stocks].num_prices-1])!= 2) {
            printf("Error: Invalid stock price.\n");
            continue;
        }
        stocks[num_stocks].num_prices++;
    }

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (sscanf(input, "PRINT %s", input)!= 1) {
            printf("Error: Invalid stock symbol.\n");
            continue;
        }
        int i;
        for (i = 0; i < num_stocks; i++) {
            if (strcmp(stocks[i].symbol, input) == 0) {
                print_stock(&stocks[i]);
                break;
            }
        }
        if (i == num_stocks) {
            printf("Error: Stock not found.\n");
        }
    }

    return 0;
}