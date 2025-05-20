//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

int main() {
    int numStocks;
    Stock stocks[MAX_STOCKS];
    char input[100];

    printf("Enter the number of stocks to track: ");
    scanf("%d", &numStocks);

    printf("Enter the stock information:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("Stock %d:\n", i+1);
        printf("Name: ");
        scanf("%s", stocks[i].name);
        strcpy(stocks[i].symbol, toupper(stocks[i].name));
        printf("Symbol: %s\n", stocks[i].symbol);
        printf("Price: ");
        scanf("%lf", &stocks[i].price);
    }

    while (1) {
        printf("Enter a stock symbol to search for: ");
        scanf("%s", input);
        int found = 0;
        for (int i = 0; i < numStocks; i++) {
            if (strcmp(input, stocks[i].symbol) == 0) {
                printf("Stock found:\n");
                printf("Name: %s\n", stocks[i].name);
                printf("Symbol: %s\n", stocks[i].symbol);
                printf("Price: $%.2f\n", stocks[i].price);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Stock not found.\n");
        }
    }

    return 0;
}