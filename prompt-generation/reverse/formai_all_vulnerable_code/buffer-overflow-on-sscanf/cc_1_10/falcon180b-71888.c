//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_DECIMALS 2
#define MAX_VOLUME_DECIMALS 2

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int volume;
    time_t timestamp;
} Stock;

void print_stock(const Stock *stock) {
    printf("%-20s %-10s $%.2f %d %s\n", stock->name, stock->symbol, stock->price, stock->volume, ctime(&stock->timestamp));
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    char input[1024];

    while (fgets(input, sizeof(input), stdin)) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            continue;
        }

        char name[MAX_NAME_LEN];
        char symbol[MAX_SYMBOL_LEN];
        double price;
        int volume;
        time_t timestamp;

        if (sscanf(input, "%s %s $%lf %d %s", name, symbol, &price, &volume, ctime(&timestamp))!= 5) {
            printf("Error: Invalid input format.\n");
            continue;
        }

        strncpy(stocks[num_stocks].name, name, MAX_NAME_LEN);
        strncpy(stocks[num_stocks].symbol, symbol, MAX_SYMBOL_LEN);
        stocks[num_stocks].price = price;
        stocks[num_stocks].volume = volume;
        stocks[num_stocks].timestamp = timestamp;

        ++num_stocks;
    }

    printf("Stock Market Tracker\n");
    printf("--------------------\n");

    for (int i = 0; i < num_stocks; ++i) {
        print_stock(&stocks[i]);
    }

    return 0;
}