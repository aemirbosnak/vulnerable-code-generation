//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STOCKS 50
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

void init_stock(Stock* stock) {
    strcpy(stock->name, "");
    strcpy(stock->symbol, "");
    stock->price = 0;
    stock->quantity = 0;
}

void print_stock(Stock stock) {
    printf("Name: %s\n", stock.name);
    printf("Symbol: %s\n", stock.symbol);
    printf("Price: $%.2f\n", stock.price);
    printf("Quantity: %d\n\n", stock.quantity);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    while (num_stocks < MAX_STOCKS) {
        printf("Enter stock information (enter 'done' when finished):\n");
        scanf("%s", stocks[num_stocks].symbol);

        if (strcmp(stocks[num_stocks].symbol, "done") == 0) {
            break;
        }

        printf("Enter stock name:\n");
        scanf("%s", stocks[num_stocks].name);

        printf("Enter stock price:\n");
        scanf("%lf", &stocks[num_stocks].price);

        printf("Enter stock quantity:\n");
        scanf("%d", &stocks[num_stocks].quantity);

        num_stocks++;
    }

    printf("\nStock Portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}