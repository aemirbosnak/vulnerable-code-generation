//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_DECIMALS 2

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int num_shares;
} Stock;

void print_stock(Stock* stock) {
    printf("Name: %s\n", stock->name);
    printf("Symbol: %s\n", stock->symbol);
    printf("Price: $%.2f\n", stock->price);
    printf("Number of shares: %d\n", stock->num_shares);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Welcome to the Stock Market Tracker!\n");

    while (num_stocks < MAX_STOCKS) {
        printf("Enter the name of the stock (or type 'quit' to exit):\n");
        char input[MAX_NAME_LEN];
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        printf("Enter the symbol of the stock:\n");
        char symbol[MAX_SYMBOL_LEN];
        scanf("%s", symbol);

        printf("Enter the current price of the stock:\n");
        double price;
        scanf("%lf", &price);

        printf("Enter the number of shares you own:\n");
        int num_shares;
        scanf("%d", &num_shares);

        strcpy(stocks[num_stocks].name, input);
        strcpy(stocks[num_stocks].symbol, symbol);
        stocks[num_stocks].price = price;
        stocks[num_stocks].num_shares = num_shares;

        num_stocks++;
    }

    printf("\nYour portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}