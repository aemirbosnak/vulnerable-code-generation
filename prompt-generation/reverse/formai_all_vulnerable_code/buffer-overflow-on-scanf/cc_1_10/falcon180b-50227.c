//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_STOCKS 10
#define MAX_DAYS 30

struct stock {
    char name[50];
    double price[MAX_DAYS];
    int index;
    double prev_close;
    double curr_close;
};

void generate_random_prices(struct stock *stocks) {
    srand(time(NULL));
    for (int i = 0; i < MAX_DAYS; i++) {
        stocks[i].price[i] = rand() % 1000;
    }
}

void print_stock_info(struct stock *stocks) {
    printf("Stock Name\tIndex\tPrevious Close\tCurrent Close\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("%s\t%d\t\t%.2f\t\t%.2f\n", stocks[i].name, stocks[i].index, stocks[i].prev_close, stocks[i].curr_close);
    }
}

int main() {
    struct stock stocks[MAX_STOCKS];
    int n_stocks;

    printf("Enter the number of stocks: ");
    scanf("%d", &n_stocks);

    printf("Enter the names of the stocks:\n");
    for (int i = 0; i < n_stocks; i++) {
        scanf("%s", stocks[i].name);
    }

    printf("Enter the indices of the stocks:\n");
    for (int i = 0; i < n_stocks; i++) {
        scanf("%d", &stocks[i].index);
    }

    generate_random_prices(stocks);

    printf("Stock Market Tracker\n");
    print_stock_info(stocks);

    return 0;
}