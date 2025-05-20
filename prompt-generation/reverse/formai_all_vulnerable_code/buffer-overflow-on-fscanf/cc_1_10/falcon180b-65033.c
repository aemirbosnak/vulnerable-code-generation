//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME 20
#define MAX_SYMBOL 10

typedef struct {
    char name[MAX_NAME];
    char symbol[MAX_SYMBOL];
    double price;
    double change;
    double percent_change;
} stock_t;

void load_stocks(stock_t stocks[]) {
    FILE *fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error loading stocks\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %lf\n", stocks[count].name, stocks[count].symbol, &stocks[count].price) == 3) {
        count++;
    }

    fclose(fp);
}

void update_stocks(stock_t stocks[]) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    if (tm->tm_hour >= 9 && tm->tm_hour < 16) {
        for (int i = 0; i < MAX_STOCKS; i++) {
            if (stocks[i].price > 0) {
                double change = stocks[i].price - stocks[i].price * 0.01;
                stocks[i].price -= change;
                stocks[i].change = change;
                stocks[i].percent_change = change / stocks[i].price * 100;
            }
        }
    }
}

void display_stocks(stock_t stocks[]) {
    printf("Name\tSymbol\tPrice\tChange\tPercent Change\n");

    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].price > 0) {
            printf("%-20s %-10s $%.2lf $%.2lf %.2lf%%\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percent_change);
        }
    }
}

int main() {
    stock_t stocks[MAX_STOCKS];

    load_stocks(stocks);

    while (1) {
        update_stocks(stocks);
        display_stocks(stocks);

        sleep(60);
    }

    return 0;
}