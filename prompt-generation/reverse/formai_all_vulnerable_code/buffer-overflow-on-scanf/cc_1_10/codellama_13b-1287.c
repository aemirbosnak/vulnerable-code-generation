//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 32

typedef struct {
    char name[MAX_NAME_LEN];
    double price;
} Stock;

void print_stock(Stock* stock) {
    printf("%s: $%.2f\n", stock->name, stock->price);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    char input[MAX_NAME_LEN];

    while (1) {
        printf("Enter a stock name: ");
        fgets(input, MAX_NAME_LEN, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }

        if (num_stocks >= MAX_STOCKS) {
            printf("Too many stocks, please try again.\n");
            continue;
        }

        strcpy(stocks[num_stocks].name, input);
        printf("Enter the stock price: ");
        scanf("%lf", &stocks[num_stocks].price);

        print_stock(&stocks[num_stocks]);
        num_stocks++;
    }

    printf("Stock Market Tracker:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}