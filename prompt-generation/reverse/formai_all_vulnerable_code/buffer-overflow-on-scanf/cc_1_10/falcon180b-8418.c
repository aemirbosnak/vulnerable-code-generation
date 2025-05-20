//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
} stock;

stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char *name, char *symbol, char *price) {
    if (num_stocks >= MAX_STOCKS) {
        printf("Error: Maximum number of stocks reached.\n");
        return;
    }

    strncpy(stocks[num_stocks].name, name, MAX_NAME_LEN);
    strncpy(stocks[num_stocks].symbol, symbol, MAX_SYMBOL_LEN);
    strncpy(stocks[num_stocks].price, price, MAX_PRICE_LEN);

    num_stocks++;
}

void display_stocks() {
    printf("Name\tSymbol\tPrice\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s\t%-10s\t%s\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
}

int main() {
    char input[100];
    time_t current_time;
    struct tm *time_info;

    current_time = time(NULL);
    time_info = localtime(&current_time);

    printf("Enter the name of the stock: ");
    scanf("%s", input);

    add_stock(input, "AAPL", "145.68");
    add_stock("MSFT", "MSFT", "261.97");
    add_stock("GOOG", "GOOG", "2295.09");

    display_stocks();

    return 0;
}