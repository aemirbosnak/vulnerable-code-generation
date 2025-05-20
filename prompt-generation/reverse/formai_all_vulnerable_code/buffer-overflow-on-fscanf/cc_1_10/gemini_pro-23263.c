//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum number of stocks that can be tracked
#define MAX_STOCKS 10

// Define the structure of a stock
typedef struct stock {
    char symbol[10];       // The stock's symbol
    double price;          // The stock's current price
    double change;         // The stock's change in price since the previous day
    double volume;         // The stock's volume for the day
} stock;

// Define an array of stocks
stock stocks[MAX_STOCKS];

// Define the function to get the stock data from a file
void getStockData(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Read the stock data from the file
    int i = 0;
    while (fscanf(file, "%s %lf %lf %lf", stocks[i].symbol, &stocks[i].price, &stocks[i].change, &stocks[i].volume) != EOF) {
        i++;
    }

    // Close the file
    fclose(file);
}

// Define the function to print the stock data
void printStockData() {
    // Print the header
    printf("%-10s %-10s %-10s %-10s\n", "Symbol", "Price", "Change", "Volume");

    // Print the stock data
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("%-10s %-10.2f %-10.2f %-10.2f\n", stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].volume);
    }
}

// Define the main function
int main() {
    // Get the stock data from a file
    getStockData("stocks.txt");

    // Print the stock data
    printStockData();

    return 0;
}