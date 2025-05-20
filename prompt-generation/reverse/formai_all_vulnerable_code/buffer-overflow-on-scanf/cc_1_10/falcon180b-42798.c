//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 100
#define MAX_PRICE_HISTORY 1000
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_prices;
    double prices[MAX_PRICE_HISTORY];
} Stock;

void initialize_stock(Stock* stock) {
    stock->num_prices = 0;
}

void add_price(Stock* stock, double price) {
    if (stock->num_prices >= MAX_PRICE_HISTORY) {
        printf("Error: Price history is full.\n");
        return;
    }
    stock->prices[stock->num_prices++] = price;
}

void print_price_history(Stock* stock) {
    if (stock->num_prices == 0) {
        printf("No price history.\n");
        return;
    }
    printf("Price history:\n");
    for (int i = 0; i < stock->num_prices; i++) {
        printf("%f\n", stock->prices[i]);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    while (num_stocks < MAX_STOCKS) {
        printf("Enter stock name (or type 'done' to finish): ");
        scanf("%s", stocks[num_stocks].name);
        if (strcmp(stocks[num_stocks].name, "done") == 0) {
            break;
        }
        num_stocks++;
    }

    while (1) {
        printf("Enter command: ");
        scanf("%s", stocks[0].name);
        if (strcmp(stocks[0].name, "quit") == 0) {
            break;
        } else if (strcmp(stocks[0].name, "add") == 0) {
            printf("Enter stock name: ");
            scanf("%s", stocks[num_stocks].name);
            initialize_stock(&stocks[num_stocks]);
            num_stocks++;
        } else if (strcmp(stocks[0].name, "price") == 0) {
            printf("Enter stock name: ");
            scanf("%s", stocks[0].name);
            printf("Enter price: ");
            scanf("%lf", &stocks[0].prices[stocks[0].num_prices++]);
        } else if (strcmp(stocks[0].name, "history") == 0) {
            printf("Enter stock name: ");
            scanf("%s", stocks[0].name);
            print_price_history(&stocks[0]);
        }
    }

    return 0;
}