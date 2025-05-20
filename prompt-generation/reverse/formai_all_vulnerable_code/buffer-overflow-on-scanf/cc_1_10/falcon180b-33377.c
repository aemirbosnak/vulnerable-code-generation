//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_NAME 20
#define MAX_SYMBOL 10

typedef struct {
    char name[MAX_NAME];
    char symbol[MAX_SYMBOL];
    double price;
    int quantity;
} stock;

int main() {
    system("clear");
    stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Welcome to the Stock Market Tracker!\n");
    printf("Please enter the name of the stock you want to track (or type 'exit' to quit):\n");
    char input[MAX_NAME];
    fgets(input, MAX_NAME, stdin);

    while (strcmp(input, "exit")!= 0) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Sorry, you can only track up to %d stocks.\n", MAX_STOCKS);
            break;
        }
        stocks[num_stocks].name[0] = '\0';
        stocks[num_stocks].symbol[0] = '\0';
        stocks[num_stocks].price = 0;
        stocks[num_stocks].quantity = 0;

        printf("Enter the name of the stock: ");
        fgets(stocks[num_stocks].name, MAX_NAME, stdin);
        printf("Enter the symbol of the stock: ");
        fgets(stocks[num_stocks].symbol, MAX_SYMBOL, stdin);
        printf("Enter the current price of the stock: ");
        scanf("%lf", &stocks[num_stocks].price);
        printf("Enter the quantity of the stock you own: ");
        scanf("%d", &stocks[num_stocks].quantity);
        num_stocks++;

        printf("\n");
        system("clear");
        printf("Welcome to the Stock Market Tracker!\n");
        printf("You are currently tracking the following stocks:\n");
        for (int i = 0; i < num_stocks; i++) {
            printf("%s (%s) - $%.2f - %d shares\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
        }
        printf("\n");
        system("pause");

        printf("Please enter the name of the stock you want to track (or type 'exit' to quit):\n");
        fgets(input, MAX_NAME, stdin);
    }

    return 0;
}