//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store stock information
typedef struct stock {
    char symbol[5];
    double price;
    double change;
} stock;

// Function to compare stocks by price
int compare_stocks_by_price(const void *a, const void *b) {
    const stock *stock1 = (const stock *)a;
    const stock *stock2 = (const stock *)b;

    if (stock1->price < stock2->price) {
        return -1;
    } else if (stock1->price > stock2->price) {
        return 1;
    } else {
        return 0;
    }
}

// Function to compare stocks by change
int compare_stocks_by_change(const void *a, const void *b) {
    const stock *stock1 = (const stock *)a;
    const stock *stock2 = (const stock *)b;

    if (stock1->change < stock2->change) {
        return -1;
    } else if (stock1->change > stock2->change) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print stock information
void print_stock(const stock *stock) {
    printf("%s %.2f %.2f\n", stock->symbol, stock->price, stock->change);
}

// Function to get stock information from a file
int get_stocks(stock **stocks, const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    // Read the number of stocks
    int num_stocks;
    fscanf(file, "%d", &num_stocks);

    // Allocate memory for the stocks
    *stocks = malloc(sizeof(stock) * num_stocks);
    if (*stocks == NULL) {
        fclose(file);
        return -1;
    }

    // Read the stock information
    for (int i = 0; i < num_stocks; i++) {
        fscanf(file, "%s %lf %lf", (*stocks)[i].symbol, &(*stocks)[i].price, &(*stocks)[i].change);
    }

    // Close the file
    fclose(file);

    return num_stocks;
}

// Function to print the stocks in a table
void print_stocks(const stock *stocks, int num_stocks) {
    // Print the header
    printf("%-5s %-10s %-10s\n", "Symbol", "Price", "Change");

    // Print the stocks
    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }
}

// Function to sort the stocks by price
void sort_stocks_by_price(stock *stocks, int num_stocks) {
    qsort(stocks, num_stocks, sizeof(stock), compare_stocks_by_price);
}

// Function to sort the stocks by change
void sort_stocks_by_change(stock *stocks, int num_stocks) {
    qsort(stocks, num_stocks, sizeof(stock), compare_stocks_by_change);
}

// Main function
int main() {
    // Get the stock information from a file
    stock *stocks;
    int num_stocks = get_stocks(&stocks, "stocks.txt");
    if (num_stocks == -1) {
        printf("Error: Could not open file.\n");
        return -1;
    }

    // Sort the stocks by price
    sort_stocks_by_price(stocks, num_stocks);

    // Print the stocks sorted by price
    printf("Stocks sorted by price:\n");
    print_stocks(stocks, num_stocks);

    // Sort the stocks by change
    sort_stocks_by_change(stocks, num_stocks);

    // Print the stocks sorted by change
    printf("Stocks sorted by change:\n");
    print_stocks(stocks, num_stocks);

    // Free the memory allocated for the stocks
    free(stocks);

    return 0;
}