//FormAI DATASET v1.0 Category: Stock market tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_SYMBOL_LENGTH 5

/* Structure to hold stock information */
struct Stock {
    char symbol[MAX_SYMBOL_LENGTH+1];
    double price;
    double change;
};

/* Function to get stock information */
void getStockInfo(struct Stock *s, int numStocks) {
    char buffer[MAX_SYMBOL_LENGTH+1];
    printf("Please enter information for %d stocks:\n", numStocks);
    for(int i = 0; i < numStocks; i++) {
        printf("\nStock %d:\n", i+1);
        printf("Enter symbol (up to 5 characters): ");
        scanf("%s", buffer);
        strcpy(s[i].symbol, buffer);
        printf("Enter price: ");
        scanf("%lf", &s[i].price);
        printf("Enter change: ");
        scanf("%lf", &s[i].change);
    }
}

/* Function to print stock information */
void printStockInfo(struct Stock *s, int numStocks) {
    printf("\n%-10s%-10s%-10s\n", "Symbol", "Price", "Change");
    for(int i = 0; i < numStocks; i++) {
        printf("%-10s%-10.2f%-10.2f\n", s[i].symbol, s[i].price, s[i].change);
    }
}

int main() {
    struct Stock stocks[MAX_STOCKS];
    int numStocks;
    printf("How many stocks would you like to track? (Maximum %d): ", MAX_STOCKS);
    scanf("%d", &numStocks);

    if(numStocks > MAX_STOCKS) {
        printf("Error: Maximum number of stocks exceeded.\n");
        return 1;
    }

    getStockInfo(stocks, numStocks);

    while(1) {
        system("clear");
        printf("Welcome to the Stock Market Tracker!\n\n");
        printStockInfo(stocks, numStocks);
        printf("\nPress ENTER to refresh or 'Q' to quit.\n");
        char input = getchar();
        if(input == 'q' || input == 'Q') {
            break;
        }
    }

    return 0;
}