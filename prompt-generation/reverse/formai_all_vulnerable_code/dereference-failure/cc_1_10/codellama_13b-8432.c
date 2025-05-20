//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: careful
/*
 * stock_tracker.c
 *
 *  Created on: Feb 5, 2023
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKERS 100
#define MAX_TICKER_LEN 10

struct Stock {
    char ticker[MAX_TICKER_LEN + 1];
    float price;
};

struct StockTracker {
    struct Stock *stocks;
    int num_stocks;
};

void add_stock(struct StockTracker *tracker, const char *ticker, float price) {
    tracker->stocks = realloc(tracker->stocks, (tracker->num_stocks + 1) * sizeof(struct Stock));
    if (tracker->stocks == NULL) {
        printf("Error: failed to allocate memory\n");
        return;
    }

    strcpy(tracker->stocks[tracker->num_stocks].ticker, ticker);
    tracker->stocks[tracker->num_stocks].price = price;
    tracker->num_stocks++;
}

void remove_stock(struct StockTracker *tracker, const char *ticker) {
    for (int i = 0; i < tracker->num_stocks; i++) {
        if (strcmp(tracker->stocks[i].ticker, ticker) == 0) {
            tracker->stocks[i] = tracker->stocks[tracker->num_stocks - 1];
            tracker->num_stocks--;
            return;
        }
    }
}

void update_price(struct StockTracker *tracker, const char *ticker, float price) {
    for (int i = 0; i < tracker->num_stocks; i++) {
        if (strcmp(tracker->stocks[i].ticker, ticker) == 0) {
            tracker->stocks[i].price = price;
            return;
        }
    }
}

void print_stock_tracker(struct StockTracker *tracker) {
    printf("Stock Tracker\n");
    printf("=============\n\n");

    for (int i = 0; i < tracker->num_stocks; i++) {
        printf("%s: %f\n", tracker->stocks[i].ticker, tracker->stocks[i].price);
    }
}

int main() {
    struct StockTracker tracker;
    tracker.stocks = NULL;
    tracker.num_stocks = 0;

    add_stock(&tracker, "AAPL", 123.45);
    add_stock(&tracker, "GOOG", 789.10);
    add_stock(&tracker, "AMZN", 145.67);

    print_stock_tracker(&tracker);

    update_price(&tracker, "AAPL", 124.56);
    update_price(&tracker, "GOOG", 790.11);
    update_price(&tracker, "AMZN", 146.78);

    print_stock_tracker(&tracker);

    remove_stock(&tracker, "GOOG");

    print_stock_tracker(&tracker);

    return 0;
}