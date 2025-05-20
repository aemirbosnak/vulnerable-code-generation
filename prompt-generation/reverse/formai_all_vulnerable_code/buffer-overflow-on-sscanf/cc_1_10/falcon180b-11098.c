//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10
#define MAX_CHANGE_LEN 10
#define MAX_PERCENT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int volume;
    double change;
    double percent_change;
} stock_t;

stock_t stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char* name, char* symbol, double price, int volume, double change, double percent_change) {
    if (num_stocks >= MAX_STOCKS) {
        printf("Error: Maximum number of stocks reached.\n");
        return;
    }

    strcpy(stocks[num_stocks].name, name);
    strcpy(stocks[num_stocks].symbol, symbol);
    stocks[num_stocks].price = price;
    stocks[num_stocks].volume = volume;
    stocks[num_stocks].change = change;
    stocks[num_stocks].percent_change = percent_change;

    num_stocks++;
}

void print_stocks() {
    printf("Name\tSymbol\tPrice\tVolume\tChange\t% Change\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s\t%-10s\t%10.2f\t%10d\t%10.2f\t%10.2f%%\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume, stocks[i].change, stocks[i].percent_change);
    }
}

int main() {
    char input[1000];
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int volume;
    double change;
    double percent_change;

    while (1) {
        printf("Enter stock information (name symbol price volume change percent_change):\n");
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%s %s %lf %d %lf %lf", name, symbol, &price, &volume, &change, &percent_change)!= 6) {
            printf("Error: Invalid input format.\n");
            continue;
        }

        add_stock(name, symbol, price, volume, change, percent_change);
    }

    return 0;
}