//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void display_header() {
    printf("\n");
    printf("+------------------------+\n");
    printf("| %20s | %10s | %10s | %10s |\n", "Name", "Symbol", "Price", "Volume");
    printf("+------------------------+\n");
}

void display_stock(Stock *stock) {
    printf("%20s | %10s | %10s | %10s |\n", stock->name, stock->symbol, stock->price, stock->volume);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    char input[MAX_NAME_LEN + MAX_SYMBOL_LEN + MAX_PRICE_LEN + MAX_VOLUME_LEN + 1];
    char name[MAX_NAME_LEN + 1];
    char symbol[MAX_SYMBOL_LEN + 1];
    char price[MAX_PRICE_LEN + 1];
    char volume[MAX_VOLUME_LEN + 1];
    int i, j;

    display_header();

    while (fgets(input, sizeof(input), stdin)) {
        if (sscanf(input, "%s %s %s %s", name, symbol, price, volume) == 4) {
            if (num_stocks >= MAX_STOCKS) {
                printf("Error: Maximum number of stocks reached.\n");
                continue;
            }
            strcpy(stocks[num_stocks].name, name);
            strcpy(stocks[num_stocks].symbol, symbol);
            strcpy(stocks[num_stocks].price, price);
            strcpy(stocks[num_stocks].volume, volume);
            num_stocks++;
        } else {
            printf("Error: Invalid input.\n");
        }
    }

    printf("\n");
    for (i = 0; i < num_stocks; i++) {
        display_stock(&stocks[i]);
    }

    return 0;
}