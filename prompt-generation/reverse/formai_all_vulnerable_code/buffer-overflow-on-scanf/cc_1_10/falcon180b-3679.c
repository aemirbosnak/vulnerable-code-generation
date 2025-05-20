//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} stock;

void init_stock(stock *s) {
    s->price = 0.0;
    s->quantity = 0;
}

void print_stock(stock s) {
    printf("Name: %s\n", s.name);
    printf("Symbol: %s\n", s.symbol);
    printf("Price: $%.2f\n", s.price);
    printf("Quantity: %d\n\n", s.quantity);
}

int main() {
    stock portfolio[MAX_STOCKS];
    int num_stocks = 0;
    char input[100];

    srand(time(0));

    printf("Welcome to the Stock Market Tracker!\n");
    printf("Please enter the name of the stock you want to track (or type 'quit' to exit):\n");
    scanf("%s", input);

    while (strcmp(input, "quit")!= 0) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Sorry, you can only track up to %d stocks.\n", MAX_STOCKS);
            break;
        }

        printf("Enter the name of the stock:\n");
        scanf("%s", portfolio[num_stocks].name);

        printf("Enter the symbol of the stock:\n");
        scanf("%s", portfolio[num_stocks].symbol);

        printf("Enter the current price of the stock:\n");
        scanf("%lf", &portfolio[num_stocks].price);

        printf("Enter the quantity of the stock you own:\n");
        scanf("%d", &portfolio[num_stocks].quantity);

        num_stocks++;

        printf("\n");
        printf("Current Portfolio:\n");
        for (int i = 0; i < num_stocks; i++) {
            print_stock(portfolio[i]);
        }

        printf("\n");
        printf("Enter the name of the stock you want to track (or type 'quit' to exit):\n");
        scanf("%s", input);
    }

    return 0;
}