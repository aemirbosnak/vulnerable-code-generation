//FormAI DATASET v1.0 Category: Stock market tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// define the maximum number of stocks to track
#define MAX_STOCKS 10

// structure to hold information about a single stock
struct stock {
    char symbol[10];
    char name[100];
    double price;
};

// function to get data for a single stock
void get_stock_data(struct stock *s) {
    printf("Enter symbol for the stock: ");
    scanf("%s", s->symbol);
    printf("Enter name for the stock: ");
    scanf("%s", s->name);
    printf("Enter current price for the stock: ");
    scanf("%lf", &s->price);
}

// function to print data for a single stock
void print_stock_data(struct stock s) {
    printf("Symbol: %s\n", s.symbol);
    printf("Name: %s\n", s.name);
    printf("Current Price: %.2f\n", s.price);
}

// function to track the stocks
void track_stocks() {
    // create an array to hold data for all the stocks
    struct stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    // loop to get data for all the stocks
    while (num_stocks < MAX_STOCKS) {
        // check if user wants to add another stock
        char choice;
        printf("Do you want to add a stock? (y/n) ");
        scanf(" %c", &choice);
        if (choice != 'y') {
            break;
        }

        // get data for the stock and add it to the array
        get_stock_data(&stocks[num_stocks]);
        num_stocks++;
    }

    // loop to print data for all the stocks
    int i;
    for (i = 0; i < num_stocks; i++) {
        printf("\n");
        print_stock_data(stocks[i]);
    }
}

int main() {
    printf("Welcome to the Stock Market Tracker!\n\n");

    // call the function to track the stocks
    track_stocks();

    printf("\nThank you for using the Stock Market Tracker!\n");
    return 0;
}