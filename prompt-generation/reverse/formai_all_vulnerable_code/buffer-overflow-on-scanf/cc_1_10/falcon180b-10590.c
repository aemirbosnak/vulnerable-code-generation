//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} stock_t;

void print_stock(stock_t* s) {
    printf("%s (%s): $%.2f x %d\n", s->name, s->symbol, s->price, s->quantity);
}

int main() {
    char input[100];
    stock_t stocks[MAX_STOCKS];
    int num_stocks = 0;
    double total_value = 0.0;

    printf("Welcome to the Love Stock Market!\n");
    printf("Please enter the name and symbol of your beloved stocks:\n");

    while (scanf("%s", input) == 1) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Sorry, you have reached the maximum number of stocks.\n");
            break;
        }

        char* name = strtok(input, " ");
        char* symbol = strtok(NULL, " ");

        if (name == NULL || symbol == NULL) {
            printf("Invalid input. Please enter the name and symbol separated by a space.\n");
            continue;
        }

        strcpy(stocks[num_stocks].name, name);
        strcpy(stocks[num_stocks].symbol, symbol);
        stocks[num_stocks].price = 0.0;
        stocks[num_stocks].quantity = 0;

        num_stocks++;
    }

    printf("\nYour portfolio:\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the price and quantity for %s (%s):\n", stocks[i].name, stocks[i].symbol);
        scanf("%lf %d", &stocks[i].price, &stocks[i].quantity);
        total_value += stocks[i].price * stocks[i].quantity;
    }

    printf("\nTotal value of your portfolio: $%.2f\n", total_value);

    return 0;
}