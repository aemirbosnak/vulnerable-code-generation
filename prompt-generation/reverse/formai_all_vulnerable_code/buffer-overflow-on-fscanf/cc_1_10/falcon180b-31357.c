//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

// Structure to hold stock information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_NAME_LENGTH];
    double price;
} Stock;

// Function to read in stock data from a file
void read_stocks(Stock stocks[], FILE *fp) {
    int count = 0;
    while (fscanf(fp, "%s %s %lf\n", stocks[count].name, stocks[count].symbol, &stocks[count].price) == 3) {
        count++;
        if (count >= MAX_STOCKS) {
            printf("Error: Too many stocks in file.\n");
            exit(1);
        }
    }
}

// Function to sort stocks by price
void sort_stocks(Stock stocks[]) {
    for (int i = 0; i < MAX_STOCKS - 1; i++) {
        for (int j = i + 1; j < MAX_STOCKS; j++) {
            if (stocks[j].price < stocks[i].price) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

// Function to print stock information
void print_stocks(Stock stocks[]) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("%s (%s): $%.2lf\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
}

// Main function
int main() {
    Stock stocks[MAX_STOCKS];
    FILE *fp;

    // Open stock data file
    fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open stocks file.\n");
        exit(1);
    }

    // Read in stock data
    read_stocks(stocks, fp);

    // Sort stocks by price
    sort_stocks(stocks);

    // Print stock information
    printf("Stock Information:\n");
    print_stocks(stocks);

    fclose(fp);
    return 0;
}