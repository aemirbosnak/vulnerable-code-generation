//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 100

// Define the structure of a stock
typedef struct stock {
    char *name;
    double price;
    double change;
} stock;

// Create an array of stocks
stock stocks[MAX_STOCKS];

// Get the number of stocks to track from the user
int get_num_stocks() {
    int num_stocks;
    printf("How many stocks do you want to track? ");
    scanf("%d", &num_stocks);
    return num_stocks;
}

// Get the details of a stock from the user
stock get_stock_details(int index) {
    stock stock;
    char name[100];
    double price;
    double change;

    printf("Enter the name of stock %d: ", index + 1);
    scanf("%s", name);
    stock.name = strdup(name);

    printf("Enter the price of stock %d: ", index + 1);
    scanf("%lf", &price);
    stock.price = price;

    printf("Enter the change in price of stock %d: ", index + 1);
    scanf("%lf", &change);
    stock.change = change;

    return stock;
}

// Print the details of a stock
void print_stock_details(stock stock) {
    printf("Name: %s\n", stock.name);
    printf("Price: %.2f\n", stock.price);
    printf("Change: %.2f\n", stock.change);
}

// Main function
int main() {
    int num_stocks;
    
    // Get the number of stocks to track
    num_stocks = get_num_stocks();

    // Get the details of each stock
    for (int i = 0; i < num_stocks; i++) {
        stocks[i] = get_stock_details(i);
    }

    // Print the details of each stock
    for (int i = 0; i < num_stocks; i++) {
        print_stock_details(stocks[i]);
    }

    return 0;
}