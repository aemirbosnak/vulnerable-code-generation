//FormAI DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define struct for holding stock data */
struct stock {
    char ticker[10];
    float price;
    float change;
};

/* Define function for updating stock data */
void update_stock(struct stock *s) {
    printf("Enter current price for %s: ", s->ticker);
    scanf("%f", &s->price);

    printf("Enter change (+/-) for %s: ", s->ticker);
    scanf("%f", &s->change);
}

/* Define function for printing stock data */
void print_stock(const struct stock *s) {
    printf("%-10s %-10.2f %-10.2f\n", s->ticker, s->price, s->change);
}

int main() {

    /* Define initial stock data */
    struct stock stocks[5];
    strcpy(stocks[0].ticker, "AAPL");
    stocks[0].price = 146.69;
    stocks[0].change = -0.21;

    strcpy(stocks[1].ticker, "GOOG");
    stocks[1].price = 2706.62;
    stocks[1].change = 0.95;

    strcpy(stocks[2].ticker, "NVDA");
    stocks[2].price = 214.58;
    stocks[2].change = 1.23;

    strcpy(stocks[3].ticker, "TSLA");
    stocks[3].price = 729.40;
    stocks[3].change = -0.61;

    strcpy(stocks[4].ticker, "AMZN");
    stocks[4].price = 3225.00;
    stocks[4].change = 0.04;

    /* Print initial stock data */
    printf("%-10s %-10s %-10s\n", "Ticker", "Price", "Change");
    for (int i = 0; i < 5; i++) {
        print_stock(&stocks[i]);
    }

    /* Prompt user to update stock data */
    printf("\nEnter new stock data:\n");
    for (int i = 0; i < 5; i++) {
        update_stock(&stocks[i]);
    }

    /* Print updated stock data */
    printf("\n%-10s %-10s %-10s\n", "Ticker", "Price", "Change");
    for (int i = 0; i < 5; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}