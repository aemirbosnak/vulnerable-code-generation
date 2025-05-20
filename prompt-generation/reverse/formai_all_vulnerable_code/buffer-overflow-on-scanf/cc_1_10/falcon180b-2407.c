//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
} Stock;

void init_stock(Stock *s) {
    strcpy(s->name, "");
    strcpy(s->symbol, "");
    s->price = 0.0;
}

void print_stock(Stock s) {
    printf("Name: %s\n", s.name);
    printf("Symbol: %s\n", s.symbol);
    printf("Price: $%.2f\n", s.price);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    char input[100];

    srand(time(NULL));

    init_stock(&stocks[0]);
    stocks[0].symbol[0] = 'A';
    stocks[0].price = rand() % 100;
    num_stocks++;

    while (num_stocks < MAX_STOCKS) {
        printf("Enter a stock name (or type 'done' to finish): ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "done") == 0) {
            break;
        }

        init_stock(&stocks[num_stocks]);
        strcpy(stocks[num_stocks].name, input);
        strcpy(stocks[num_stocks].symbol, "");

        while (1) {
            stocks[num_stocks].symbol[0] = toupper(rand() % 26 + 'A');

            int found = 0;
            for (int i = 0; i < num_stocks; i++) {
                if (stocks[i].symbol[0] == stocks[num_stocks].symbol[0]) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                break;
            }
        }

        printf("Enter the stock price: ");
        scanf("%lf", &stocks[num_stocks].price);
        num_stocks++;
    }

    printf("Stock Portfolio:\n");

    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}