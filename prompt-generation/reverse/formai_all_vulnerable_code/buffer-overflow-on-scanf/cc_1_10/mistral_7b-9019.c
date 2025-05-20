//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STOCKS 10

typedef struct {
    char symbol[5];
    double price;
    double last_price;
} Stock;

void add_stock(Stock stocks[], char symbol[], double price);
void remove_stock(Stock stocks[], char symbol[]);
void view_prices(Stock stocks[]);
void view_price_change(Stock stocks[], char symbol[]);

int main() {
    Stock stocks[MAX_STOCKS] = {};
    char command[20], symbol[5];
    double price;

    for (;;) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %lf", symbol, &price);
            add_stock(stocks, symbol, price);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%s", symbol);
            remove_stock(stocks, symbol);
        } else if (strcmp(command, "prices") == 0) {
            view_prices(stocks);
        } else if (strcmp(command, "change") == 0) {
            scanf("%s", symbol);
            view_price_change(stocks, symbol);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}

void add_stock(Stock stocks[], char symbol[], double price) {
    for (int i = 0; i < MAX_STOCKS; ++i) {
        if (stocks[i].price == 0.0) {
            strcpy(stocks[i].symbol, symbol);
            stocks[i].price = price;
            stocks[i].last_price = price;
            break;
        }
    }
}

void remove_stock(Stock stocks[], char symbol[]) {
    for (int i = 0; i < MAX_STOCKS; ++i) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            stocks[i].price = 0.0;
            break;
        }
    }
}

void view_prices(Stock stocks[]) {
    for (int i = 0; i < MAX_STOCKS; ++i) {
        if (stocks[i].price > 0.0) {
            printf("%s: %.2f\n", stocks[i].symbol, stocks[i].price);
        }
    }
}

void view_price_change(Stock stocks[], char symbol[]) {
    for (int i = 0; i < MAX_STOCKS; ++i) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            double price_change = (stocks[i].price - stocks[i].last_price) / stocks[i].last_price * 100.0;
            printf("%s: %.2f%%\n", symbol, price_change);
            stocks[i].last_price = stocks[i].price;
            break;
        }
    }
}