//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_DESC_LENGTH 100

typedef struct Stock {
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESC_LENGTH];
    double price;
    int quantity;
} Stock;

typedef struct StockMarket {
    Stock* stocks;
    int num_stocks;
    double total_value;
} StockMarket;

void addStock(StockMarket* market, const char* name, const char* desc, double price, int quantity) {
    Stock stock = {name, desc, price, quantity};
    market->stocks[market->num_stocks] = stock;
    market->num_stocks++;
}

void removeStock(StockMarket* market, const char* name) {
    int index = -1;
    for (int i = 0; i < market->num_stocks; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index >= 0) {
        for (int i = index; i < market->num_stocks - 1; i++) {
            market->stocks[i] = market->stocks[i + 1];
        }
        market->num_stocks--;
    }
}

void updateStock(StockMarket* market, const char* name, double price) {
    for (int i = 0; i < market->num_stocks; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            market->stocks[i].price = price;
            break;
        }
    }
}

double getStockValue(StockMarket* market, const char* name) {
    for (int i = 0; i < market->num_stocks; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            return market->stocks[i].price * market->stocks[i].quantity;
        }
    }
    return 0.0;
}

void displayStockMarket(StockMarket* market) {
    printf("Stock Market\n");
    for (int i = 0; i < market->num_stocks; i++) {
        printf("%s: %s - $%.2f (%d shares)\n", market->stocks[i].name, market->stocks[i].desc, market->stocks[i].price, market->stocks[i].quantity);
    }
    printf("Total Value: $%.2f\n", market->total_value);
}

int main() {
    StockMarket market = {NULL, 0, 0.0};
    market.stocks = malloc(MAX_STOCKS * sizeof(Stock));

    addStock(&market, "AAPL", "Apple Inc.", 100.0, 10);
    addStock(&market, "GOOG", "Alphabet Inc.", 120.0, 15);
    addStock(&market, "FB", "Facebook Inc.", 150.0, 20);

    updateStock(&market, "AAPL", 90.0);
    updateStock(&market, "GOOG", 130.0);

    displayStockMarket(&market);

    removeStock(&market, "FB");

    displayStockMarket(&market);

    return 0;
}