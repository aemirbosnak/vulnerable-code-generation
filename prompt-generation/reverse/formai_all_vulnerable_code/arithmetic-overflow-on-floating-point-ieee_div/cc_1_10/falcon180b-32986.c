//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks that can be tracked
#define MAX_STOCKS 100

// Define the structure for a single stock
typedef struct {
    char name[50];
    double price;
    double change;
    double percentage_change;
} Stock;

// Function to compare two stocks based on their percentage change
int compare_stocks(const void *a, const void *b) {
    const Stock *stock_a = (const Stock *)a;
    const Stock *stock_b = (const Stock *)b;

    if (stock_a->percentage_change > stock_b->percentage_change) {
        return -1;
    } else if (stock_a->percentage_change < stock_b->percentage_change) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the stock market tracker table
void print_table(Stock stocks[], int num_stocks) {
    printf("+----------------------+\n");
    printf("| Stock Name           |\n");
    printf("+----------------------+\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("| %-40s | $%.2f | $%.2f | %.2f%% |\n", stocks[i].name, stocks[i].price, stocks[i].change, stocks[i].percentage_change);
    }

    printf("+----------------------+\n");
}

int main() {
    // Initialize an array of stocks
    Stock stocks[MAX_STOCKS];

    // Initialize the number of stocks being tracked
    int num_stocks = 0;

    // Read in the stock data from a file
    FILE *fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            fclose(fp);
            return 1;
        }

        Stock stock;
        sscanf(line, "%s $%.2f $%.2f", stock.name, &stock.price, &stock.change);
        stock.percentage_change = (stock.change / stock.price) * 100;

        stocks[num_stocks] = stock;
        num_stocks++;
    }

    fclose(fp);

    // Sort the stocks based on their percentage change
    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks);

    // Print the stock market tracker table
    print_table(stocks, num_stocks);

    return 0;
}