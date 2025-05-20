//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100

typedef struct {
    char symbol[5];
    double price;
    double last_price;
    double percentage_change;
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock() {
    if (num_stocks >= MAX_STOCKS) {
        printf("Error: Max number of stocks reached.\n");
        return;
    }

    printf("Enter stock symbol (up to 5 characters): ");
    scanf("%s", stocks[num_stocks].symbol);

    printf("Enter current stock price: ");
    scanf("%lf", &stocks[num_stocks].price);

    stocks[num_stocks].last_price = stocks[num_stocks].price;
    stocks[num_stocks].percentage_change = 0.0;

    num_stocks++;
}

void display_stocks() {
    if (num_stocks == 0) {
        printf("No stocks in the portfolio.\n");
        return;
    }

    printf("%-10s %-15s %-15s %-15s\n", "Symbol", "Current Price", "Last Price", "Percentage Change");

    for (int i = 0; i < num_stocks; i++) {
        double price_change = stocks[i].price - stocks[i].last_price;
        stocks[i].percentage_change = (price_change / stocks[i].last_price) * 100;

        printf("%-10s $%.2f $%.2f %+.2f%%\n", stocks[i].symbol, stocks[i].price, stocks[i].last_price, stocks[i].percentage_change);
        stocks[i].last_price = stocks[i].price;
    }
}

void remove_stock() {
    if (num_stocks == 0) {
        printf("Error: No stocks in the portfolio.\n");
        return;
    }

    char symbol[5];
    printf("Enter stock symbol to remove: ");
    scanf("%s", symbol);

    int index = -1;
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Stock not found in the portfolio.\n");
        return;
    }

    for (int i = index; i < num_stocks - 1; i++) {
        strcpy(stocks[i].symbol, stocks[i+1].symbol);
    }

    num_stocks--;
}

int main() {
    int choice;

    while (1) {
        printf("\nStock Market Tracker\n");
        printf("1. Add stock\n");
        printf("2. Display stocks\n");
        printf("3. Remove stock\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_stock();
                break;
            case 2:
                display_stocks();
                break;
            case 3:
                remove_stock();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}