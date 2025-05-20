//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

int main() {
    int numStocks;
    Stock stocks[MAX_STOCKS];
    char input[100];

    printf("Enter the number of stocks: ");
    scanf("%d", &numStocks);

    for (int i = 0; i < numStocks; i++) {
        printf("Enter stock name (%d): ", i + 1);
        scanf("%s", stocks[i].name);

        printf("Enter stock symbol (%d): ", i + 1);
        scanf("%s", stocks[i].symbol);

        printf("Enter stock price (%d): ", i + 1);
        scanf("%lf", &stocks[i].price);
    }

    while (1) {
        printf("\n");
        printf("1. Display all stocks\n");
        printf("2. Search for a stock\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", input);

        if (tolower(input[0]) == '1') {
            for (int i = 0; i < numStocks; i++) {
                printf("%d. %s (%s) - $%.2f\n", i + 1, stocks[i].name, stocks[i].symbol, stocks[i].price);
            }
        } else if (tolower(input[0]) == '2') {
            printf("Enter the stock name to search for: ");
            scanf("%s", input);

            for (int i = 0; i < numStocks; i++) {
                if (strcasecmp(stocks[i].name, input) == 0) {
                    printf("%s (%s) - $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
                }
            }
        } else if (tolower(input[0]) == '3') {
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}