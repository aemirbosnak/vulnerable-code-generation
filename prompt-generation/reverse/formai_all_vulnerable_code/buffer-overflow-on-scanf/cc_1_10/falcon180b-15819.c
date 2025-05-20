//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    double price;
    int quantity;
} Stock;

void init_stock(Stock *s, char *name, double price, int quantity) {
    strncpy(s->name, name, MAX_NAME_LEN);
    s->price = price;
    s->quantity = quantity;
}

void print_stock(Stock s) {
    printf("Name: %s\n", s.name);
    printf("Price: $%.2f\n", s.price);
    printf("Quantity: %d\n\n", s.quantity);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Welcome to the Stock Market Tracker!\n\n");

    while (num_stocks < MAX_STOCKS) {
        printf("Enter the name of a stock (or type 'done' to finish): ");
        char input[MAX_NAME_LEN];
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        printf("Enter the current price of %s: ", input);
        double price;
        scanf("%lf", &price);

        printf("Enter the quantity of %s you own: ", input);
        int quantity;
        scanf("%d", &quantity);

        init_stock(&stocks[num_stocks], input, price, quantity);
        num_stocks++;
    }

    printf("\nYour portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}