//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int quantity;
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char *name, char *symbol, double price, int quantity) {
    if (num_stocks >= MAX_STOCKS) {
        printf("Error: Maximum number of stocks reached.\n");
        return;
    }
    strncpy(stocks[num_stocks].name, name, MAX_NAME_LENGTH);
    strncpy(stocks[num_stocks].symbol, symbol, MAX_SYMBOL_LENGTH);
    stocks[num_stocks].price = price;
    stocks[num_stocks].quantity = quantity;
    num_stocks++;
}

void remove_stock(char *symbol) {
    int i;
    for (i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            num_stocks--;
            memmove(&stocks[i], &stocks[i+1], sizeof(Stock) * (num_stocks - i - 1));
            break;
        }
    }
}

void update_stock(char *symbol, double price, int quantity) {
    int i;
    for (i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            stocks[i].price = price;
            stocks[i].quantity = quantity;
            break;
        }
    }
}

void display_stocks() {
    printf("Name\tSymbol\tPrice\tQuantity\n");
    int i;
    for (i = 0; i < num_stocks; i++) {
        printf("%-20s %-10s $%.2f %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int quantity;

    while (1) {
        printf("Enter stock information (name, symbol, price, quantity):\n");
        scanf("%s %s %lf %d", name, symbol, &price, &quantity);
        add_stock(name, symbol, price, quantity);
    }

    return 0;
}