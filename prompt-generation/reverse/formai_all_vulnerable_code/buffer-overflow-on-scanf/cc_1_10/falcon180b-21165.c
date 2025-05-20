//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} stock_t;

int main() {
    int num_stocks = 0;
    stock_t stocks[MAX_STOCKS];

    // Initialize random seed
    srand(time(NULL));

    // Prompt user for number of stocks
    printf("Enter the number of stocks to track (up to %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    // Generate random stock names
    for (int i = 0; i < num_stocks; i++) {
        char name[MAX_NAME_LEN];
        sprintf(name, "Stock %d", i+1);
        strcpy(stocks[i].name, name);

        // Generate random stock symbols
        char symbol[MAX_SYMBOL_LEN];
        sprintf(symbol, "S%d", i+1);
        strcpy(stocks[i].symbol, symbol);

        // Set initial stock prices
        stocks[i].price = rand() % 1000;
    }

    // Display initial stock prices
    printf("\nInitial Stock Prices:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s %-10s $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }

    // Simulate stock market changes
    for (int day = 1; day <= 30; day++) {
        printf("\nDay %d Stock Prices:\n", day);
        for (int i = 0; i < num_stocks; i++) {
            double change = (rand() % 100) - 50; // Random change between -50% and +50%
            stocks[i].price += change * stocks[i].price / 100; // Apply percentage change
            printf("%-20s %-10s $%.2f (%.2f%%)\n", stocks[i].name, stocks[i].symbol, stocks[i].price, change * 100);
        }
        printf("\n");
    }

    return 0;
}