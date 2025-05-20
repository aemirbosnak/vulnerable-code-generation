//FormAI DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20

struct Stock {
    char name[MAX_NAME_LENGTH];
    int price;
};

void initialize(struct Stock *stocks, int numStocks);
void updatePrices(struct Stock *stocks, int numStocks);
void display(struct Stock *stocks, int numStocks);
int highestPrice(struct Stock *stocks, int numStocks);
int lowestPrice(struct Stock *stocks, int numStocks);

int main() {
    struct Stock stocks[MAX_STOCKS];
    int numStocks;
    bool running = true;

    printf("How many stocks would you like to track? (Maximum: %d)\n", MAX_STOCKS);
    scanf("%d", &numStocks);
    if (numStocks > MAX_STOCKS) {
        printf("Maximum number of stocks exceeded. Please try again.\n");
        return 1;
    }

    initialize(stocks, numStocks);

    while (running) {
        printf("\nWhat would you like to do?\n");
        printf("1. Update prices\n");
        printf("2. Display stocks\n");
        printf("3. Get highest price\n");
        printf("4. Get lowest price\n");
        printf("5. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                updatePrices(stocks, numStocks);
                break;
            case 2:
                display(stocks, numStocks);
                break;
            case 3: {
                int highest = highestPrice(stocks, numStocks);
                printf("The highest price is %d.\n", highest);
                break;
            }
            case 4: {
                int lowest = lowestPrice(stocks, numStocks);
                printf("The lowest price is %d.\n", lowest);
                break;
            }
            case 5:
                running = false;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    printf("Goodbye!\n");
    return 0;
}

/**
 * Initializes the stocks array with names and random prices.
 * @param stocks The stocks array to initialize.
 * @param numStocks The number of stocks to initialize.
 */
void initialize(struct Stock *stocks, int numStocks) {
    char names[MAX_STOCKS][MAX_NAME_LENGTH] = {"AAPL", "GOOG", "TSLA", "NFLX", "AMZN", "FB", "MSFT", "NVDA", "AMD", "INTC"};
    for (int i = 0; i < numStocks; i++) {
        strcpy(stocks[i].name, names[i]);
        stocks[i].price = rand() % 1000 + 1;
    }
    printf("Stocks initialized.\n");
}

/**
 * Updates the prices of the stocks in the array.
 * @param stocks The stocks array to update.
 * @param numStocks The number of stocks to update.
 */
void updatePrices(struct Stock *stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        stocks[i].price = rand() % 1000 + 1;
    }
    printf("Prices updated.\n");
}

/**
 * Displays the stocks and their current prices in the array.
 * @param stocks The stocks array to display.
 * @param numStocks The number of stocks to display.
 */
void display(struct Stock *stocks, int numStocks) {
    printf("Stocks:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s: %d\n", stocks[i].name, stocks[i].price);
    }
}

/**
 * Returns the highest price of the stocks in the array.
 * @param stocks The stocks array to search.
 * @param numStocks The number of stocks to search.
 * @return The highest price of the stocks.
 */
int highestPrice(struct Stock *stocks, int numStocks) {
    int highest = stocks[0].price;
    for (int i = 1; i < numStocks; i++) {
        if (stocks[i].price > highest) {
            highest = stocks[i].price;
        }
    }
    return highest;
}

/**
 * Returns the lowest price of the stocks in the array.
 * @param stocks The stocks array to search.
 * @param numStocks The number of stocks to search.
 * @return The lowest price of the stocks.
 */
int lowestPrice(struct Stock *stocks, int numStocks) {
    int lowest = stocks[0].price;
    for (int i = 1; i < numStocks; i++) {
        if (stocks[i].price < lowest) {
            lowest = stocks[i].price;
        }
    }
    return lowest;
}