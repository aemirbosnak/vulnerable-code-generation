//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100

struct Stock {
    char name[100];
    float price;
};

struct Stock* stocks[MAX_STOCKS];
int num_stocks = 0;

void addStock(char* name, float price) {
    struct Stock* stock = malloc(sizeof(struct Stock));
    strcpy(stock->name, name);
    stock->price = price;
    stocks[num_stocks++] = stock;
}

void removeStock(char* name) {
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i]->name, name) == 0) {
            free(stocks[i]);
            stocks[i] = NULL;
            break;
        }
    }
}

void updateStockPrice(char* name, float price) {
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i]->name, name) == 0) {
            stocks[i]->price = price;
            break;
        }
    }
}

void printStock(struct Stock* stock) {
    printf("%s: $%.2f\n", stock->name, stock->price);
}

int main() {
    addStock("AAPL", 100.00);
    addStock("GOOG", 200.00);
    addStock("AMZN", 300.00);

    printStock(stocks[0]);
    printStock(stocks[1]);
    printStock(stocks[2]);

    removeStock("GOOG");
    updateStockPrice("AAPL", 105.00);

    printStock(stocks[0]);
    printStock(stocks[1]);
    printStock(stocks[2]);

    return 0;
}