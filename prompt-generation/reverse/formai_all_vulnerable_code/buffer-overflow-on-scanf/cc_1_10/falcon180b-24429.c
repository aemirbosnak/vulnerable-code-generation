//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_DECIMALS 4

typedef struct {
    char name[MAX_NAME_LEN + 1];
    char symbol[MAX_SYMBOL_LEN + 1];
    double price;
} Stock;

int main() {
    int num_stocks;
    scanf("%d", &num_stocks);

    Stock stocks[MAX_STOCKS];
    int num_added_stocks = 0;

    for (int i = 0; i < num_stocks; i++) {
        char name[MAX_NAME_LEN + 1] = "";
        char symbol[MAX_SYMBOL_LEN + 1] = "";
        double price = 0.0;

        printf("Enter stock %d information:\n", i + 1);
        printf("Name: ");
        scanf("%s", name);
        strcpy(stocks[i].name, name);

        printf("Symbol: ");
        scanf("%s", symbol);
        strcpy(stocks[i].symbol, symbol);

        printf("Price: $");
        if (scanf("%lf", &price)!= 1) {
            printf("Invalid input\n");
            continue;
        }
        stocks[i].price = price;

        num_added_stocks++;
    }

    if (num_added_stocks == 0) {
        printf("No valid stocks added\n");
        return 1;
    }

    printf("\nAdded stocks:\n");
    for (int i = 0; i < num_added_stocks; i++) {
        printf("%s (%s) - $%.4f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }

    return 0;
}