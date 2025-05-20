//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store stock data
typedef struct Stock {
    char *symbol;
    double price;
    double change;
} Stock;

// Function to compare stocks by price
int compare_by_price(const void *a, const void *b) {
    Stock *stock1 = (Stock *)a;
    Stock *stock2 = (Stock *)b;
    return stock1->price - stock2->price;
}

// Function to compare stocks by change
int compare_by_change(const void *a, const void *b) {
    Stock *stock1 = (Stock *)a;
    Stock *stock2 = (Stock *)b;
    return stock1->change - stock2->change;
}

// Function to load stock data from a file
int load_stock_data(const char *filename, Stock **stocks) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read the number of stocks
    int num_stocks;
    fscanf(fp, "%d", &num_stocks);

    // Allocate memory for the stocks
    *stocks = (Stock *)malloc(sizeof(Stock) * num_stocks);
    if (*stocks == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return -1;
    }

    // Read the stock data
    for (int i = 0; i < num_stocks; i++) {
        Stock *stock = &(*stocks)[i];

        // Read the stock symbol
        char symbol[10];
        fscanf(fp, "%s", symbol);
        stock->symbol = strdup(symbol);

        // Read the stock price
        double price;
        fscanf(fp, "%lf", &price);
        stock->price = price;

        // Read the stock change
        double change;
        fscanf(fp, "%lf", &change);
        stock->change = change;
    }

    fclose(fp);

    return num_stocks;
}

// Function to print stock data
void print_stock_data(Stock *stocks, int num_stocks) {
    printf("%-10s %-10s %-10s\n", "Symbol", "Price", "Change");
    for (int i = 0; i < num_stocks; i++) {
        Stock *stock = &stocks[i];
        printf("%-10s %-10.2f %-10.2f\n", stock->symbol, stock->price, stock->change);
    }
}

// Function to free stock data
void free_stock_data(Stock *stocks, int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        Stock *stock = &stocks[i];
        free(stock->symbol);
    }
    free(stocks);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load stock data
    Stock *stocks;
    int num_stocks = load_stock_data(argv[1], &stocks);
    if (num_stocks < 0) {
        return EXIT_FAILURE;
    }

    // Print stock data
    printf("Original stock data:\n");
    print_stock_data(stocks, num_stocks);

    // Sort stocks by price
    qsort(stocks, num_stocks, sizeof(Stock), compare_by_price);

    // Print sorted stock data
    printf("\nSorted stock data by price:\n");
    print_stock_data(stocks, num_stocks);

    // Sort stocks by change
    qsort(stocks, num_stocks, sizeof(Stock), compare_by_change);

    // Print sorted stock data
    printf("\nSorted stock data by change:\n");
    print_stock_data(stocks, num_stocks);

    // Free stock data
    free_stock_data(stocks, num_stocks);

    return EXIT_SUCCESS;
}