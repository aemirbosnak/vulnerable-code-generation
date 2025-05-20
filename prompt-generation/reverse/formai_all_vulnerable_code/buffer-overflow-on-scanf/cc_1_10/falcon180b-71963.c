//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_STOCKS 1000
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 20

struct stock {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
};

int main() {
    int num_stocks;
    struct stock stocks[MAX_STOCKS];

    printf("Enter the number of stocks to track: ");
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i+1);
        scanf("%s", stocks[i].name);

        printf("Enter the symbol of stock %d: ", i+1);
        scanf("%s", stocks[i].symbol);

        printf("Enter the current price of stock %d: $", i+1);
        scanf("%lf", &stocks[i].price);
    }

    printf("\nStock Tracker\n");
    printf("=============\n");

    while (1) {
        system("clear");
        printf("\nStock Tracker\n");
        printf("=============\n");

        for (int i = 0; i < num_stocks; i++) {
            printf("%-50s %-10s $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
        }

        printf("\nPress any key to continue...\n");
        getchar();
    }

    return 0;
}