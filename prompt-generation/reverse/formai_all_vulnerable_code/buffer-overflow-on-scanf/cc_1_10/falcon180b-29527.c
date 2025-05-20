//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STOCKS 10
#define MAX_DAYS 100

typedef struct {
    char name[20];
    double price;
} stock_t;

void initialize_stocks(stock_t stocks[], int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i + 1);
        scanf("%s", stocks[i].name);
        printf("Enter the initial price of stock %s: ", stocks[i].name);
        scanf("%lf", &stocks[i].price);
    }
}

void simulate_stock_market(stock_t stocks[], int num_stocks, int num_days) {
    for (int i = 0; i < num_days; i++) {
        for (int j = 0; j < num_stocks; j++) {
            double change = rand() % 11 - 5; // Random change between -5% and +5%
            stocks[j].price += change / 100; // Convert percentage to actual change
            if (stocks[j].price < 0) {
                stocks[j].price = 0; // Prevent negative prices
            }
        }
        printf("\nDay %d:\n", i + 1);
        for (int j = 0; j < num_stocks; j++) {
            printf("%s: $%.2f (%+.2f%%)\n", stocks[j].name, stocks[j].price, (stocks[j].price - 1) * 100);
        }
    }
}

int main() {
    stock_t stocks[MAX_STOCKS];
    int num_stocks;

    printf("Enter the number of stocks to track (up to %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    if (num_stocks < 1 || num_stocks > MAX_STOCKS) {
        printf("Invalid number of stocks.\n");
        return 1;
    }

    initialize_stocks(stocks, num_stocks);

    int num_days;

    printf("Enter the number of days to simulate the stock market (up to %d): ", MAX_DAYS);
    scanf("%d", &num_days);

    if (num_days < 1 || num_days > MAX_DAYS) {
        printf("Invalid number of days.\n");
        return 1;
    }

    simulate_stock_market(stocks, num_stocks, num_days);

    return 0;
}