//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_SYMBOL_LEN 10

typedef struct {
    char symbol[MAX_SYMBOL_LEN];
    double price;
    double change;
} Stock;

void read_data(Stock stocks[], int* num_stocks);
void calculate_prices(Stock stocks[], int num_stocks, int days);
void print_results(Stock stocks[], int num_stocks);

int main() {
    int num_stocks;
    Stock stocks[MAX_STOCKS];

    read_data(stocks, &num_stocks);

    if (num_stocks > 0) {
        int days = 5;
        calculate_prices(stocks, num_stocks, days);
        print_results(stocks, num_stocks);
    } else {
        printf("No stocks provided.\n");
    }

    return 0;
}

void read_data(Stock stocks[], int* num_stocks) {
    char symbol[MAX_SYMBOL_LEN];
    double price;

    printf("Enter the number of stocks and their symbols and initial prices:\n");
    *num_stocks = 0;

    while (1) {
        if (scanf("%s %lf", symbol, &price) != 2) {
            if (feof(stdin)) {
                break;
            } else {
                printf("Invalid input. Please enter a symbol and a price separated by a space.\n");
                continue;
            }
        }

        strcpy(stocks[*num_stocks].symbol, symbol);
        stocks[*num_stocks].price = price;

        (*num_stocks)++;

        if (*num_stocks >= MAX_STOCKS) {
            printf("Max number of stocks reached.\n");
            break;
        }
    }
}

void calculate_prices(Stock stocks[], int num_stocks, int days) {
    double daily_change = 0.05; // Example daily change rate

    for (int i = 0; i < num_stocks; i++) {
        stocks[i].change = stocks[i].price * pow(1 + daily_change, days);
        stocks[i].price = stocks[i].change;
    }
}

void print_results(Stock stocks[], int num_stocks) {
    printf("\nCurrent prices and portfolio value:\n");
    double portfolio_value = 0.0;

    for (int i = 0; i < num_stocks; i++) {
        printf("%s: %.2f\n", stocks[i].symbol, stocks[i].price);
        portfolio_value += stocks[i].price;
    }

    printf("\nPortfolio value: %.2f\n", portfolio_value);
}