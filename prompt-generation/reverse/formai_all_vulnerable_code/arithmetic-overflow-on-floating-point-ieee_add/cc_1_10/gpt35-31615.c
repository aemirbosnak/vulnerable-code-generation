//FormAI DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define SYMBOL_LENGTH 6

// Structure to hold stock information
struct Stock {
    char symbol[SYMBOL_LENGTH];
    float price;
    int volume;
};

// Function to print a stock's information
void printStock(struct Stock stock) {
    printf("%s: $%.2f (%d)\n", stock.symbol, stock.price, stock.volume);
}

// Function to calculate the total value of a stock
float calculateValue(struct Stock stock) {
    return stock.price * stock.volume;
}

int main() {
    // Array of stocks
    struct Stock stocks[MAX_STOCKS];

    // Initialize stocks
    strcpy(stocks[0].symbol, "AAPL");
    stocks[0].price = 127.13;
    stocks[0].volume = 100;

    strcpy(stocks[1].symbol, "GOOGL");
    stocks[1].price = 1739.58;
    stocks[1].volume = 50;

    strcpy(stocks[2].symbol, "AMZN");
    stocks[2].price = 3119.43;
    stocks[2].volume = 25;

    // Print initial stock information
    printf("Initial stock information:\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].symbol[0] != '\0') {
            printStock(stocks[i]);
        }
    }

    // Update stock information
    printf("\nUpdating stock information...\n");
    stocks[1].price = 1745.23;
    stocks[1].volume = 75;

    stocks[2].price = 3121.12;

    // Print updated stock information
    printf("\nUpdated stock information:\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].symbol[0] != '\0') {
            printStock(stocks[i]);
        }
    }

    // Calculate total portfolio value
    float totalValue = 0;
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].symbol[0] != '\0') {
            totalValue += calculateValue(stocks[i]);
        }
    }

    // Print total portfolio value
    printf("\nTotal portfolio value: $%.2f", totalValue);

    return 0;
}