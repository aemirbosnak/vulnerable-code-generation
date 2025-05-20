//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 100

// Define the structure of a stock
typedef struct {
    char *name;
    double price;
    double change;
} Stock;

// Define the function to compare two stocks by price
int compare_stocks_by_price(const void *a, const void *b) {
    const Stock *stock1 = (const Stock *)a;
    const Stock *stock2 = (const Stock *)b;
    return stock1->price - stock2->price;
}

// Define the function to compare two stocks by change
int compare_stocks_by_change(const void *a, const void *b) {
    const Stock *stock1 = (const Stock *)a;
    const Stock *stock2 = (const Stock *)b;
    return stock1->change - stock2->change;
}

// Define the function to print a stock
void print_stock(const Stock *stock) {
    printf("%s: $%.2f (%.2f%%)\n", stock->name, stock->price, stock->change);
}

// Define the function to get the current stock data
void get_stock_data(Stock *stocks, int num_stocks) {
    // Seed the random number generator
    srand(time(NULL));

    // Generate random stock data
    for (int i = 0; i < num_stocks; i++) {
        stocks[i].name = malloc(32);
        sprintf(stocks[i].name, "Stock %d", i + 1);
        stocks[i].price = (rand() % 1000) / 100.0;
        stocks[i].change = (rand() % 201) / 100.0 - 1.0;
    }
}

// Define the function to track the stock market
void track_stock_market(Stock *stocks, int num_stocks) {
    // Get the current stock data
    get_stock_data(stocks, num_stocks);

    // Sort the stocks by price
    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks_by_price);

    // Print the top 10 stocks by price
    printf("Top 10 Stocks by Price:\n");
    for (int i = 0; i < 10; i++) {
        print_stock(&stocks[i]);
    }

    // Sort the stocks by change
    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks_by_change);

    // Print the top 10 stocks by change
    printf("\nTop 10 Stocks by Change:\n");
    for (int i = 0; i < 10; i++) {
        print_stock(&stocks[i]);
    }
}

// Define the main function
int main() {
    // Create an array of stocks
    Stock stocks[MAX_STOCKS];

    // Get the number of stocks to track
    int num_stocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &num_stocks);

    // Track the stock market
    track_stock_market(stocks, num_stocks);

    // Free the memory allocated for the stocks
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i].name);
    }

    return 0;
}