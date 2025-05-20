//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_DAYS 365

typedef struct {
    char name[20];
    double price;
} stock_t;

void read_stocks(stock_t stocks[], int num_stocks) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open stocks.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %lf", stocks[i].name, &stocks[i].price)!= EOF) {
        i++;
        if (i >= num_stocks) {
            printf("Error: too many stocks in stocks.txt\n");
            exit(1);
        }
    }

    fclose(fp);
}

void write_stocks(stock_t stocks[], int num_stocks) {
    FILE *fp = fopen("stocks.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open stocks.txt for writing\n");
        exit(1);
    }

    for (int i = 0; i < num_stocks; i++) {
        fprintf(fp, "%s %lf\n", stocks[i].name, stocks[i].price);
    }

    fclose(fp);
}

void print_stocks(stock_t stocks[], int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        printf("%s: $%.2lf\n", stocks[i].name, stocks[i].price);
    }
}

void update_prices(stock_t stocks[], int num_stocks, double change_percent) {
    for (int i = 0; i < num_stocks; i++) {
        stocks[i].price += stocks[i].price * change_percent;
    }
}

int main() {
    srand(time(NULL));

    int num_stocks = rand() % MAX_STOCKS + 1;
    stock_t stocks[MAX_STOCKS];

    read_stocks(stocks, num_stocks);

    int num_days = rand() % MAX_DAYS + 1;

    printf("Stock Market Tracker\n");
    printf("===================\n");

    for (int i = 0; i < num_days; i++) {
        double change_percent = (double)rand() / RAND_MAX * 0.1 - 0.05;
        update_prices(stocks, num_stocks, change_percent);

        printf("\nDay %d:\n", i + 1);
        print_stocks(stocks, num_stocks);

        write_stocks(stocks, num_stocks);
    }

    return 0;
}