//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_CHANGE_LEN 10
#define MAX_PERCENT_CHANGE_LEN 10
#define MAX_LAST_UPDATE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char change[MAX_CHANGE_LEN];
    char percent_change[MAX_PERCENT_CHANGE_LEN];
    char last_update[MAX_LAST_UPDATE_LEN];
} stock_t;

void update_stock_info(stock_t *stock) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(stock->last_update, MAX_LAST_UPDATE_LEN, "%Y-%m-%d %H:%M:%S", tm);
}

int main() {
    stock_t stocks[MAX_STOCKS];
    int num_stocks = 0;

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open stocks.txt\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %s %s %s %s\n", stocks[num_stocks].name, stocks[num_stocks].symbol, stocks[num_stocks].price, stocks[num_stocks].change, stocks[num_stocks].percent_change, stocks[num_stocks].last_update)!= EOF) {
        num_stocks++;
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: too many stocks in stocks.txt\n");
            exit(1);
        }
    }

    fclose(fp);

    while (1) {
        for (int i = 0; i < num_stocks; i++) {
            update_stock_info(&stocks[i]);
            printf("%s %s $%.2f $%.2f %.2f%% %s\n", stocks[i].name, stocks[i].symbol, atof(stocks[i].price), atof(stocks[i].change), atof(stocks[i].percent_change), stocks[i].last_update);
        }

        sleep(60); // update every minute
    }

    return 0;
}