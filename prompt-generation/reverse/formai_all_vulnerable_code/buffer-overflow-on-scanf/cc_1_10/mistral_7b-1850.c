//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SYMBOLS 100
#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 200

typedef struct {
    char symbol[MAX_SYMBOLS];
    char name[MAX_NAME_LENGTH];
    float current_price;
    float previous_close;
    float change_percent;
} Stock;

void get_stock_data(Stock *stock, char *symbol);
void print_stock_data(Stock stock);
void print_header();

int main() {
    int i;
    Stock stocks[MAX_SYMBOLS];
    char symbol[MAX_SYMBOLS];

    srand(time(NULL));

    print_header();

    for (i = 0; i < 5; i++) {
        printf("Enter stock symbol: ");
        scanf("%s", symbol);
        get_stock_data(&stocks[i], symbol);
    }

    for (i = 0; i < 5; i++) {
        print_stock_data(stocks[i]);
    }

    return 0;
}

void get_stock_data(Stock *stock, char *symbol) {
    float random_price = rand() % 100 + 50;
    int j;

    strcpy(stock->symbol, symbol);

    for (j = 0; j < MAX_NAME_LENGTH && symbol[j] != '\0'; j++) {
        stock->name[j] = toupper(symbol[j]);
    }
    stock->name[j] = '\0';

    stock->current_price = random_price;
    stock->previous_close = random_price - (rand() % 20 + 10);
    stock->change_percent = ((stock->current_price - stock->previous_close) / stock->previous_close) * 100;
}

void print_stock_data(Stock stock) {
    printf("%-10s | %-50s | %-10.2f | %-10.2f | %-8.2f%%\n", stock.symbol, stock.name, stock.current_price, stock.previous_close, stock.change_percent);
}

void print_header() {
    printf("%-10s | %-50s | %-10s | %-10s | %-8s%s\n", "Symbol", "Name", "Current Price", "Previous Close", "Change %%", "");
}