//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 10

// Define the structure of a stock
typedef struct {
    char symbol[10];
    double price;
    double change;
} Stock;

// Define the function to print the stock data
void print_stock(Stock stock) {
    printf("%s %.2f %.2f\n", stock.symbol, stock.price, stock.change);
}

// Define the function to compare two stocks by price
int compare_stocks_by_price(const void *a, const void *b) {
    Stock *stock1 = (Stock *)a;
    Stock *stock2 = (Stock *)b;

    if (stock1->price < stock2->price) {
        return -1;
    } else if (stock1->price > stock2->price) {
        return 1;
    } else {
        return 0;
    }
}

// Define the function to track the stock market
void track_stock_market() {
    // Get the number of stocks to track
    int num_stocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &num_stocks);

    // Create an array of stocks
    Stock stocks[MAX_STOCKS];

    // Get the stock data for each stock
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the symbol for stock %d: ", i + 1);
        scanf("%s", stocks[i].symbol);

        printf("Enter the price for stock %d: ", i + 1);
        scanf("%lf", &stocks[i].price);

        printf("Enter the change for stock %d: ", i + 1);
        scanf("%lf", &stocks[i].change);
    }

    // Print the stock data
    printf("\nStock data:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    // Sort the stocks by price
    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks_by_price);

    // Print the sorted stock data
    printf("\nSorted stock data:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }
}

int main() {
    // Track the stock market
    track_stock_market();

    return 0;
}