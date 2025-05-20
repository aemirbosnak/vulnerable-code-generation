//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: shape shifting
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
    char price[MAX_PRICE_LEN];
} stock_t;

stock_t stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock() {
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[num_stocks].name);

    printf("Enter the symbol of the stock: ");
    scanf("%s", stocks[num_stocks].symbol);

    printf("Enter the current price of the stock: ");
    scanf("%s", stocks[num_stocks].price);

    num_stocks++;
}

void remove_stock() {
    int index;

    printf("Enter the index of the stock to remove: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_stocks) {
        num_stocks--;

        for (int i = index; i < num_stocks; i++) {
            strcpy(stocks[i].name, stocks[i + 1].name);
            strcpy(stocks[i].symbol, stocks[i + 1].symbol);
            strcpy(stocks[i].price, stocks[i + 1].price);
        }
    } else {
        printf("Invalid index.\n");
    }
}

void display_stocks() {
    printf("\nName\tSymbol\tPrice\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("%s\t%s\t%s\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
}

void main() {
    int choice, index;

    printf("Welcome to the Stock Market Tracker!\n");

    while (1) {
        printf("\n1. Add stock\n2. Remove stock\n3. Display stocks\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_stock();
                break;

            case 2:
                printf("Enter the index of the stock to remove: ");
                scanf("%d", &index);
                remove_stock();
                break;

            case 3:
                display_stocks();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}