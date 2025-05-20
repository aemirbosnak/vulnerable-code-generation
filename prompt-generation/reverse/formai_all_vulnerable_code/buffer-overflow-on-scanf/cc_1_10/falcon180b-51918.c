//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
} Stock;

void display_menu() {
    printf("\n");
    printf("1. Add a stock\n");
    printf("2. Remove a stock\n");
    printf("3. Display all stocks\n");
    printf("4. Exit\n");
    printf("\n");
}

int main() {
    int choice;
    int num_stocks = 0;
    Stock stocks[MAX_STOCKS];

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_stocks >= MAX_STOCKS) {
                printf("Cannot add more stocks.\n");
            } else {
                printf("Enter stock name: ");
                scanf("%s", stocks[num_stocks].name);
                printf("Enter stock symbol: ");
                scanf("%s", stocks[num_stocks].symbol);
                printf("Enter stock price: ");
                scanf("%lf", &stocks[num_stocks].price);
                num_stocks++;
            }
            break;

        case 2:
            if (num_stocks == 0) {
                printf("No stocks to remove.\n");
            } else {
                printf("Enter stock symbol to remove: ");
                scanf("%s", stocks[num_stocks - 1].symbol);
                num_stocks--;
            }
            break;

        case 3:
            printf("Stocks:\n");
            for (int i = 0; i < num_stocks; i++) {
                printf("%s (%s) - $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}