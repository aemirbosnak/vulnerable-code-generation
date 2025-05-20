//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: Alan Turing
// Stock market tracker program in Alan Turing style
#include <stdio.h>
#include <stdlib.h>

// Define struct for stock data
typedef struct {
    char name[10];
    float price;
    float change;
} Stock;

// Function to print stock data
void printStock(Stock *s) {
    printf("%s: $%.2f (%+.2f%%)\n", s->name, s->price, s->change);
}

// Main program
int main() {
    // Declare variables
    Stock *stocks = NULL;
    int numStocks = 0;
    float totalPrice = 0;
    float maxChange = 0;
    char maxChangeStock[10] = "";

    // Open file
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read stock data
    while (fscanf(fp, "%s %f %f", stocks[numStocks].name, &stocks[numStocks].price, &stocks[numStocks].change) == 3) {
        totalPrice += stocks[numStocks].price;
        if (stocks[numStocks].change > maxChange) {
            maxChange = stocks[numStocks].change;
            strcpy(maxChangeStock, stocks[numStocks].name);
        }
        numStocks++;
    }

    // Close file
    fclose(fp);

    // Print stock data
    for (int i = 0; i < numStocks; i++) {
        printStock(&stocks[i]);
    }

    // Print total price and max change
    printf("Total price: $%.2f\n", totalPrice);
    printf("Max change: %+.2f%% (%s)\n", maxChange, maxChangeStock);

    // Free memory
    free(stocks);

    return 0;
}