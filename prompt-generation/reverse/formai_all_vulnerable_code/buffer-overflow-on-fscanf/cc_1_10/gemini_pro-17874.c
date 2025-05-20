//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 10

// Define the structure of a stock
typedef struct stock {
    char *name;
    double price;
    double change;
} stock;

// Create an array of stocks
stock stocks[MAX_STOCKS];

// Get the stock data from a file
void get_stock_data(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the stock data from the file
    int i = 0;
    while (fscanf(file, "%s %lf %lf", stocks[i].name, &stocks[i].price, &stocks[i].change) != EOF) {
        i++;
    }

    // Close the file
    fclose(file);
}

// Print the stock data to the console
void print_stock_data() {
    printf("Stock Data\n");
    printf("----------\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("%s\t$%.2f\t%.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
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