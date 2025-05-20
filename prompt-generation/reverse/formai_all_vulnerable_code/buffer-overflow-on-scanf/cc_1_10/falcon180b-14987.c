//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_DECIMALS 2

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    double prev_price;
    int volume;
    time_t timestamp;
} Stock;

void init_stock(Stock *s, char *name, char *symbol, double price, int volume) {
    strcpy(s->name, name);
    strcpy(s->symbol, symbol);
    s->price = price;
    s->prev_price = price;
    s->volume = volume;
    s->timestamp = time(NULL);
}

void print_stock(Stock s) {
    printf("%-20s %-10s $%.2f (%+.2f%%) %d\n", s.name, s.symbol, s.price, 100 * (s.price - s.prev_price) / s.prev_price, s.volume);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    while (num_stocks < MAX_STOCKS) {
        printf("Enter stock information (name, symbol, price, volume):\n");
        char name[MAX_NAME_LEN], symbol[MAX_SYMBOL_LEN];
        double price, volume;
        if (scanf("%s %s %lf %d", name, symbol, &price, &volume)!= 4) {
            printf("Invalid input.\n");
            continue;
        }
        init_stock(&stocks[num_stocks], name, symbol, price, volume);
        num_stocks++;
    }

    while (1) {
        system("clear");
        printf("Stock Market Tracker\n");
        for (int i = 0; i < num_stocks; i++) {
            print_stock(stocks[i]);
        }
        sleep(5);
    }

    return 0;
}