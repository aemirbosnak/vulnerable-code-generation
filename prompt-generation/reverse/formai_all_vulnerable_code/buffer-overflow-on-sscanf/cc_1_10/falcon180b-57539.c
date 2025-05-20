//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_STOCK_NAME_LENGTH 20
#define MAX_STOCK_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_STOCK_NAME_LENGTH];
    char symbol[MAX_STOCK_SYMBOL_LENGTH];
    int quantity;
    float price;
} Stock;

void print_stock(Stock *stock) {
    printf("Name: %s\n", stock->name);
    printf("Symbol: %s\n", stock->symbol);
    printf("Quantity: %d\n", stock->quantity);
    printf("Price: $%.2f\n", stock->price);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    char input[100];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            break;
        }

        char name[MAX_STOCK_NAME_LENGTH];
        char symbol[MAX_STOCK_SYMBOL_LENGTH];
        int quantity;
        float price;

        sscanf(input, "%s %s %d $%f", name, symbol, &quantity, &price);

        strcpy(stocks[num_stocks].name, name);
        strcpy(stocks[num_stocks].symbol, symbol);
        stocks[num_stocks].quantity = quantity;
        stocks[num_stocks].price = price;

        num_stocks++;
    }

    printf("Number of stocks: %d\n", num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}