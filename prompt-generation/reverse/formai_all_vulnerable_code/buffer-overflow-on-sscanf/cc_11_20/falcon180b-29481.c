//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    char input[100];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (input[0] == 'B') { // Buy
            char name[MAX_NAME_LEN];
            char symbol[MAX_SYMBOL_LEN];
            double price;
            int quantity;

            sscanf(input, "B %s %s %lf %d", name, symbol, &price, &quantity);

            for (int i = 0; i < num_stocks; i++) {
                if (strcmp(stocks[i].symbol, symbol) == 0) {
                    printf("Error: Duplicate symbol %s\n", symbol);
                    return 1;
                }
            }

            strcpy(stocks[num_stocks].name, name);
            strcpy(stocks[num_stocks].symbol, symbol);
            stocks[num_stocks].price = price;
            stocks[num_stocks].quantity = quantity;
            num_stocks++;
        } else if (input[0] == 'S') { // Sell
            char symbol[MAX_SYMBOL_LEN];

            sscanf(input, "S %s", symbol);

            for (int i = 0; i < num_stocks; i++) {
                if (strcmp(stocks[i].symbol, symbol) == 0) {
                    printf("Sold %d shares of %s at $%.2f\n", stocks[i].quantity, stocks[i].name, stocks[i].price);
                    stocks[i].quantity = 0;
                } else {
                    printf("Error: Symbol %s not found\n", symbol);
                }
            }
        } else if (input[0] == 'Q') { // Query
            char symbol[MAX_SYMBOL_LEN];

            sscanf(input, "Q %s", symbol);

            for (int i = 0; i < num_stocks; i++) {
                if (strcmp(stocks[i].symbol, symbol) == 0) {
                    printf("You own %d shares of %s at $%.2f\n", stocks[i].quantity, stocks[i].name, stocks[i].price);
                }
            }
        } else if (input[0] == 'H') { // History
            for (int i = 0; i < num_stocks; i++) {
                printf("%s %s $%.2f %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
            }
        }
    }

    return 0;
}