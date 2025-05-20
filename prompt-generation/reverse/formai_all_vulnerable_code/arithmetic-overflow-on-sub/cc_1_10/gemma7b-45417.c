//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Stocks 10

typedef struct Stock {
    char name[20];
    double price;
    double change;
    double prev_price;
    int vol_avg;
    time_t last_updated;
} Stock;

Stock stocks[MAX_Stocks];

void update_stock(Stock *stock) {
    // Simulate fetching stock data
    stock->price = rand() % 1000;
    stock->change = (rand() % 2 - 1) / 100.0;
    stock->prev_price = stock->price;
    stock->last_updated = time(NULL);
}

void display_stocks() {
    for (int i = 0; i < MAX_Stocks; i++) {
        printf("%s: $%.2f, %+.2f%%, last updated: %.2f hours ago\n", stocks[i].name, stocks[i].price, stocks[i].change, (time(NULL) - stocks[i].last_updated) / 3600);
    }
}

int main() {
    // Initialize stocks
    for (int i = 0; i < MAX_Stocks; i++) {
        strcpy(stocks[i].name, "Stock #");
        stocks[i].price = rand() % 1000;
        stocks[i].change = (rand() % 2 - 1) / 100.0;
        stocks[i].prev_price = stocks[i].price;
        stocks[i].vol_avg = rand() % 100;
        stocks[i].last_updated = time(NULL);
    }

    // Update stock prices
    update_stock(&stocks[0]);

    // Display stocks
    display_stocks();

    return 0;
}