//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

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
    int num_stocks = 0;
    Stock stocks[MAX_STOCKS];

    printf("Welcome to the Stock Market Tracker!\n");
    printf("How many stocks would you like to track? ");
    scanf("%d", &num_stocks);

    if (num_stocks > MAX_STOCKS) {
        printf("Sorry, you can only track up to %d stocks.\n", MAX_STOCKS);
        return 1;
    }

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i+1);
        scanf("%s", stocks[i].name);

        printf("Enter the symbol of stock %d: ", i+1);
        scanf("%s", stocks[i].symbol);

        printf("Enter the current price of stock %s: ", stocks[i].name);
        scanf("%lf", &stocks[i].price);

        printf("Enter the quantity of stock %s you own: ", stocks[i].name);
        scanf("%d", &stocks[i].quantity);
    }

    printf("\nInitial Portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s (%s) - %.2f - %d shares\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }

    double total_value = 0;
    for (int i = 0; i < num_stocks; i++) {
        total_value += stocks[i].price * stocks[i].quantity;
    }

    printf("\nTotal portfolio value: $%.2f\n", total_value);

    return 0;
}