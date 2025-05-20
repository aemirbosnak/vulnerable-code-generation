//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int quantity;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    char input[100];

    while (1) {
        printf("Enter a command (buy/sell/status/exit): ");
        scanf("%s", input);

        if (strcmp(input, "buy") == 0) {
            if (num_stocks >= MAX_STOCKS) {
                printf("Error: maximum number of stocks reached.\n");
            } else {
                printf("Enter stock name: ");
                scanf("%s", stocks[num_stocks].name);
                printf("Enter stock symbol: ");
                scanf("%s", stocks[num_stocks].symbol);
                printf("Enter stock price: ");
                scanf("%lf", &stocks[num_stocks].price);
                printf("Enter stock quantity: ");
                scanf("%d", &stocks[num_stocks].quantity);
                num_stocks++;
            }
        } else if (strcmp(input, "sell") == 0) {
            printf("Enter stock symbol to sell: ");
            scanf("%s", input);
            int index = -1;
            for (int i = 0; i < num_stocks; i++) {
                if (strcmp(stocks[i].symbol, input) == 0) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                printf("Error: stock not found.\n");
            } else {
                printf("Enter quantity to sell: ");
                scanf("%d", &stocks[index].quantity);
            }
        } else if (strcmp(input, "status") == 0) {
            printf("Stock Portfolio:\n");
            for (int i = 0; i < num_stocks; i++) {
                printf("%s (%s) - %.2lf - %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
            }
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Error: invalid command.\n");
        }
    }

    return 0;
}