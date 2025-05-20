//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
} stock_t;

int main() {
    int num_stocks;
    stock_t stocks[MAX_STOCKS];

    printf("Welcome to the Stock Market Tracker!\n");
    printf("How many stocks would you like to track? (Max %d) ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i+1);
        scanf("%s", stocks[i].name);

        printf("Enter the symbol of stock %d: ", i+1);
        scanf("%s", stocks[i].symbol);

        printf("Enter the current price of stock %s: ", stocks[i].symbol);
        scanf("%s", stocks[i].price);
    }

    while (1) {
        printf("\nCurrent stock prices:\n");
        for (int i = 0; i < num_stocks; i++) {
            printf("%s: $%s\n", stocks[i].name, stocks[i].price);
        }

        printf("\nEnter 'q' to quit or any other key to continue: ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'q' || choice == 'Q') {
            break;
        }
    }

    return 0;
}