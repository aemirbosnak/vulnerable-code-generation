//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double current_price;
    double previous_price;
    double change;
    double percentage_change;
} Stock;

void update_stock_prices(Stock *stocks, int num_stocks) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    for (int i = 0; i < num_stocks; i++) {
        sprintf(stocks[i].symbol, "STOCK%d", i + 1);
        stocks[i].current_price = (double)tm_now->tm_sec / 100.0;
        stocks[i].previous_price = (double)tm_now->tm_min / 100.0;
        stocks[i].change = stocks[i].current_price - stocks[i].previous_price;
        stocks[i].percentage_change = (stocks[i].change / stocks[i].previous_price) * 100.0;
    }
}

void print_stock_table(Stock *stocks, int num_stocks) {
    printf("+----------------------+\n");
    printf("| %-20s | %-10s | %-10s | %-10s | %-10s |\n", "Name", "Symbol", "Current Price", "Previous Price", "Change");
    printf("+----------------------+\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("| %-20s | %-10s | $%.2f | $%.2f | $%.2f |\n", stocks[i].name, stocks[i].symbol, stocks[i].current_price, stocks[i].previous_price, stocks[i].change);
    }

    printf("+----------------------+\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Enter the names and symbols of up to %d stocks:\n", MAX_STOCKS);

    while (num_stocks < MAX_STOCKS && scanf("%s %s", stocks[num_stocks].name, stocks[num_stocks].symbol) == 2) {
        num_stocks++;
    }

    update_stock_prices(stocks, num_stocks);
    print_stock_table(stocks, num_stocks);

    return 0;
}