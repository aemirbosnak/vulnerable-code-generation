//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_VALUE_LEN 20
#define MAX_DATE_LEN 20

struct stock {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char value[MAX_VALUE_LEN];
    char date[MAX_DATE_LEN];
};

struct stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char *name, char *symbol, char *value, char *date) {
    if (num_stocks >= MAX_STOCKS) {
        printf("Error: Maximum number of stocks reached.\n");
        return;
    }

    strncpy(stocks[num_stocks].name, name, MAX_NAME_LEN);
    strncpy(stocks[num_stocks].symbol, symbol, MAX_SYMBOL_LEN);
    strncpy(stocks[num_stocks].value, value, MAX_VALUE_LEN);
    strncpy(stocks[num_stocks].date, date, MAX_DATE_LEN);

    num_stocks++;
}

void print_stocks() {
    printf("Stock Name | Stock Symbol | Stock Value | Date\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("%s | %s | %s | %s\n", stocks[i].name, stocks[i].symbol, stocks[i].value, stocks[i].date);
    }
}

int main() {
    char input[MAX_VALUE_LEN];

    while (1) {
        printf("Enter stock name: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        printf("Enter stock symbol: ");
        scanf("%s", input);

        printf("Enter stock value: ");
        scanf("%s", input);

        printf("Enter stock date: ");
        scanf("%s", input);

        add_stock(input, input, input, input);
    }

    print_stocks();

    return 0;
}