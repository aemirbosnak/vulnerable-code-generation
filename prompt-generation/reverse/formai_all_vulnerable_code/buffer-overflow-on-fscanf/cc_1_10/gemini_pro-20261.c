//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: accurate
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
    double percent_change;
} stock;

// Declare an array of stocks
stock stocks[MAX_STOCKS];

// Get the stock data from a file
void get_stock_data(char *filename) {
    FILE *fp;
    int i;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the stock data from the file
    for (i = 0; i < MAX_STOCKS; i++) {
        fscanf(fp, "%s %lf %lf", stocks[i].symbol, &stocks[i].price, &stocks[i].change);
    }

    // Close the file
    fclose(fp);
}

// Print the stock data to the console
void print_stock_data() {
    int i;

    // Print the header
    printf("%-10s %-10s %-10s %-10s\n", "Symbol", "Price", "Change", "% Change");

    // Print the stock data
    for (i = 0; i < MAX_STOCKS; i++) {
        // Calculate the percent change
        stocks[i].percent_change = (stocks[i].change / stocks[i].price) * 100;

        // Print the stock data
        printf("%-10s %10.2f %10.2f %10.2f%%\n", stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percent_change);
    }
}

// Main function
int main() {
    // Get the stock data from a file
    get_stock_data("stocks.txt");

    // Print the stock data to the console
    print_stock_data();

    return 0;
}