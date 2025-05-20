//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STOCKS 1000
#define MAX_NAME_LENGTH 100
#define MAX_SHARE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SHARE_LENGTH];
    double price;
    int shares;
} stock_t;

void init_stock(stock_t* s) {
    s->price = 0.0;
    s->shares = 0;
}

void print_stock(const stock_t* s) {
    printf("%-20s %-10s $%.2f %10d\n", s->name, s->symbol, s->price, s->shares);
}

int main() {
    stock_t stocks[MAX_STOCKS];
    int num_stocks = 0;
    char input[1024];

    srand(time(NULL));

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            continue;
        }

        char* name = strtok(input, ",");
        char* symbol = strtok(NULL, ",");
        double price = rand() % 1000 / 100.0;
        int shares = rand() % 1000;

        strncpy(stocks[num_stocks].name, name, MAX_NAME_LENGTH - 1);
        strncpy(stocks[num_stocks].symbol, symbol, MAX_SHARE_LENGTH - 1);
        stocks[num_stocks].price = price;
        stocks[num_stocks].shares = shares;

        num_stocks++;
    }

    printf("Stock Market Tracker\n");
    printf("--------------------\n");

    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}