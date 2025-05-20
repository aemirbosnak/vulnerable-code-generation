//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

// Struct to hold stock information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int quantity;
} Stock;

int main() {
    int numStocks;
    Stock stocks[MAX_STOCKS];

    // Get number of stocks from user
    printf("Enter number of stocks: ");
    scanf("%d", &numStocks);

    // Get stock information from user
    for (int i = 0; i < numStocks; i++) {
        printf("Enter stock %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", stocks[i].name);
        printf("Symbol: ");
        scanf("%s", stocks[i].symbol);
        printf("Price: ");
        scanf("%lf", &stocks[i].price);
        printf("Quantity: ");
        scanf("%d", &stocks[i].quantity);
    }

    // Print initial stock prices
    printf("\nInitial stock prices:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s (%s) - $%.2f - %d shares\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }

    // Simulate stock market changes
    for (int day = 1; day <= 7; day++) {
        printf("\nDay %d:\n", day);
        for (int i = 0; i < numStocks; i++) {
            double change = (rand() % 101) / 100.0; // Random percentage change between -1% and 1%
            stocks[i].price += change * stocks[i].price; // Apply percentage change to price
            printf("%s (%s) - $%.2f (+/-$%.2f) - %d shares\n", stocks[i].name, stocks[i].symbol, stocks[i].price, change*stocks[i].price, stocks[i].quantity);
        }
    }

    return 0;
}