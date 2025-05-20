//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_DAYS 100

typedef struct {
    char name[20];
    double price;
} Stock;

void generateStockPrices(Stock stocks[MAX_STOCKS], int numStocks) {
    srand(time(NULL));
    for (int i = 0; i < numStocks; i++) {
        stocks[i].price = rand() % 1000;
    }
}

void printStocks(Stock stocks[MAX_STOCKS], int numStocks) {
    printf("Stock Prices:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks;

    printf("Enter number of stocks (up to %d): ", MAX_STOCKS);
    scanf("%d", &numStocks);

    printf("Enter stock names (up to 20 characters each):\n");
    for (int i = 0; i < numStocks; i++) {
        scanf("%s", stocks[i].name);
    }

    generateStockPrices(stocks, numStocks);
    printf("Initial stock prices:\n");
    printStocks(stocks, numStocks);

    int numDays;
    printf("Enter number of days to track (up to %d): ", MAX_DAYS);
    scanf("%d", &numDays);

    for (int i = 0; i < numDays; i++) {
        printf("Day %d:\n", i+1);
        printStocks(stocks, numStocks);
        sleep(1); // Pause for 1 second to simulate real-world time passing
    }

    return 0;
}