//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: portable
/*
 * stock_tracker.c
 *
 * A simple stock market tracker program written in C.
 *
 * Usage: ./stock_tracker <stock_symbol>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>

#define MAX_STOCK_SYMBOL_LEN 16
#define MAX_LINE_LEN 256
#define MAX_PRICE_DIGITS 10

typedef struct {
    char symbol[MAX_STOCK_SYMBOL_LEN];
    double price;
} Stock;

bool parse_stock(char *line, Stock *stock) {
    char *p = line;
    char *symbol = NULL;
    double price = 0.0;

    while (*p && isspace(*p)) p++;

    symbol = p;
    while (*p && !isspace(*p)) p++;

    if (!*p) return false;

    *p++ = '\0';

    while (*p && isspace(*p)) p++;

    if (!*p) return false;

    price = strtod(p, &p);
    if (errno == ERANGE || price < 0 || price > INT_MAX) return false;

    strcpy(stock->symbol, symbol);
    stock->price = price;

    return true;
}

void print_stock(Stock stock) {
    printf("%s: $%.2f\n", stock.symbol, stock.price);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <stock_symbol>\n", argv[0]);
        return 1;
    }

    char line[MAX_LINE_LEN];
    Stock stock;

    while (fgets(line, sizeof(line), stdin)) {
        if (!parse_stock(line, &stock)) continue;
        if (strcmp(stock.symbol, argv[1]) == 0) {
            print_stock(stock);
            break;
        }
    }

    return 0;
}