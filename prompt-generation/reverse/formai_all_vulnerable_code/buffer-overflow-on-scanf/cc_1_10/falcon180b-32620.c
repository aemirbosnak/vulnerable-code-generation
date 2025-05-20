//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_DAYS 365

typedef struct {
    char name[50];
    double price;
    int num_shares;
} stock;

void generate_random_data(stock *stocks, int num_stocks) {
    srand(time(NULL));
    for (int i = 0; i < num_stocks; i++) {
        stocks[i].price = rand() % 100;
        stocks[i].num_shares = rand() % 1000;
    }
}

void print_stock_data(stock *stocks, int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        printf("%s: $%.2f (%d shares)\n", stocks[i].name, stocks[i].price, stocks[i].num_shares);
    }
}

void simulate_stock_market(stock *stocks, int num_stocks, int num_days) {
    for (int day = 0; day < num_days; day++) {
        for (int i = 0; i < num_stocks; i++) {
            stocks[i].price += (rand() % 10 - 5) / 100.0;
        }
    }
}

int main() {
    stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Enter the number of stocks to track (up to %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    printf("Enter the names of the stocks:\n");
    for (int i = 0; i < num_stocks; i++) {
        scanf("%s", stocks[i].name);
    }

    generate_random_data(stocks, num_stocks);
    print_stock_data(stocks, num_stocks);

    printf("Simulate the stock market for how many days? ");
    int num_days;
    scanf("%d", &num_days);

    simulate_stock_market(stocks, num_stocks, num_days);

    printf("Stock market data after %d days:\n", num_days);
    print_stock_data(stocks, num_stocks);

    return 0;
}