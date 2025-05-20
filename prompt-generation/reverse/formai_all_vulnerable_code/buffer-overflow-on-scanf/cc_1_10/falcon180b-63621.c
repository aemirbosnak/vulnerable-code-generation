//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_LENGTH 20
#define MAX_VOLUME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    char price[MAX_PRICE_LENGTH];
    char volume[MAX_VOLUME_LENGTH];
} Stock;

void print_stock(Stock s) {
    printf("Name: %s\n", s.name);
    printf("Symbol: %s\n", s.symbol);
    printf("Price: %s\n", s.price);
    printf("Volume: %s\n", s.volume);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    while (num_stocks < MAX_STOCKS) {
        printf("Enter stock information (leave blank to stop):\n");
        printf("Name: ");
        scanf("%s", stocks[num_stocks].name);

        if (strcmp(stocks[num_stocks].name, "") == 0) {
            break;
        }

        printf("Symbol: ");
        scanf("%s", stocks[num_stocks].symbol);

        printf("Price: ");
        scanf("%s", stocks[num_stocks].price);

        printf("Volume: ");
        scanf("%s", stocks[num_stocks].volume);

        num_stocks++;
    }

    printf("Stock information:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}