//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 100

// Define the structure of a stock
typedef struct stock {
    char symbol[10];
    double price;
    double change;
} stock;

// Create an array of stocks
stock stocks[MAX_STOCKS];

// Get the number of stocks to track
int get_num_stocks() {
    int num_stocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &num_stocks);
    return num_stocks;
}

// Get the stock data
void get_stock_data(int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the symbol for stock %d: ", i + 1);
        scanf("%s", stocks[i].symbol);
        printf("Enter the price for stock %d: ", i + 1);
        scanf("%lf", &stocks[i].price);
        printf("Enter the change for stock %d: ", i + 1);
        scanf("%lf", &stocks[i].change);
    }
}

// Print the stock data
void print_stock_data(int num_stocks) {
    printf("\nStock data:\n");
    printf("Symbol\tPrice\tChange\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s\t%.2f\t%.2f\n", stocks[i].symbol, stocks[i].price, stocks[i].change);
    }
}

// Main function
int main() {
    // Get the number of stocks to track
    int num_stocks = get_num_stocks();

    // Get the stock data
    get_stock_data(num_stocks);

    // Print the stock data
    print_stock_data(num_stocks);

    return 0;
}