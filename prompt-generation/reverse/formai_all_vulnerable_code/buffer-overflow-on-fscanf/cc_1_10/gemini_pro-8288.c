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
} Stock;

// Define the array of stocks
Stock stocks[MAX_STOCKS];

// Read the stock data from a file
int read_stock_data(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    int num_stocks = 0;
    while (fscanf(fp, "%s %lf %lf", stocks[num_stocks].symbol, &stocks[num_stocks].price, &stocks[num_stocks].change) == 3) {
        num_stocks++;
    }

    fclose(fp);

    return num_stocks;
}

// Print the stock data
void print_stock_data(int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        printf("%s %.2f %.2f\n", stocks[i].symbol, stocks[i].price, stocks[i].change);
    }
}

// Sort the stock data by price
void sort_stock_data_by_price(int num_stocks) {
    for (int i = 0; i < num_stocks - 1; i++) {
        for (int j = i + 1; j < num_stocks; j++) {
            if (stocks[i].price > stocks[j].price) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

// Sort the stock data by change
void sort_stock_data_by_change(int num_stocks) {
    for (int i = 0; i < num_stocks - 1; i++) {
        for (int j = i + 1; j < num_stocks; j++) {
            if (stocks[i].change > stocks[j].change) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

// Get the user's input
int get_user_input(int *num_stocks, char **filename) {
    printf("Enter the number of stocks to track: ");
    scanf("%d", num_stocks);

    printf("Enter the name of the file containing the stock data: ");
    *filename = malloc(100);
    scanf("%s", *filename);

    return 0;
}

// Main function
int main() {
    int num_stocks;
    char *filename;

    // Get the user's input
    get_user_input(&num_stocks, &filename);

    // Read the stock data from a file
    int num_stocks_read = read_stock_data(filename);
    if (num_stocks_read == -1) {
        return -1;
    }

    // Sort the stock data by price
    sort_stock_data_by_price(num_stocks_read);

    // Print the stock data
    printf("Stocks sorted by price:\n");
    print_stock_data(num_stocks_read);

    // Sort the stock data by change
    sort_stock_data_by_change(num_stocks_read);

    // Print the stock data
    printf("Stocks sorted by change:\n");
    print_stock_data(num_stocks_read);

    // Free the memory allocated for the filename
    free(filename);

    return 0;
}