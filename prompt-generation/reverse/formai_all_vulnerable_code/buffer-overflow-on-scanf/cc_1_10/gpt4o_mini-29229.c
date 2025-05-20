//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 50

// Structure to hold stock information
typedef struct {
    char name[NAME_LENGTH];
    float price;
    float change;
} Stock;

// Function prototypes
void initializeStocks(Stock stocks[], int count);
void updateStockPrices(Stock stocks[], int count);
void displayStockMarket(Stock stocks[], int count);
void sortStocksByChange(Stock stocks[], int count);
void showTopGainers(Stock stocks[], int count);
void showTopLosers(Stock stocks[], int count);

int main() {
    Stock stocks[MAX_STOCKS];
    int numberOfStocks;

    printf("Welcome to the Curious Stock Market Tracker!\n");
    printf("How many stocks would you like to track? (Max %d): ", MAX_STOCKS);
    scanf("%d", &numberOfStocks);
    
    if (numberOfStocks <= 0 || numberOfStocks > MAX_STOCKS) {
        printf("Please enter a valid number of stocks.\n");
        return 1;
    }

    initializeStocks(stocks, numberOfStocks);

    while (1) {
        updateStockPrices(stocks, numberOfStocks);
        printf("\nCurrent Stock Market Overview:\n");
        displayStockMarket(stocks, numberOfStocks);

        showTopGainers(stocks, numberOfStocks);
        showTopLosers(stocks, numberOfStocks);

        char choice;
        printf("\nWould you like to refresh the stock prices? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    printf("Thank you for using the Curious Stock Market Tracker!\n");
    return 0;
}

void initializeStocks(Stock stocks[], int count) {
    printf("Please enter the stock names and their current prices:\n");
    for (int i = 0; i < count; i++) {
        printf("Stock %d Name: ", i + 1);
        scanf("%s", stocks[i].name);
        printf("Current Price of %s: ", stocks[i].name);
        scanf("%f", &stocks[i].price);
        stocks[i].change = 0.0f; // Initialize change to zero
    }
}

void updateStockPrices(Stock stocks[], int count) {
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < count; i++) {
        float changePercent = ((rand() % 100) - 50) / 100.0; // Random change between -0.5 and 0.5
        stocks[i].change = changePercent * stocks[i].price; // Calculate change
        stocks[i].price += stocks[i].change; // Update price
    }
}

void displayStockMarket(Stock stocks[], int count) {
    printf("\n%-20s %-10s %-10s\n", "Stock Name", "Price", "Change");
    for (int i = 0; i < count; i++) {
        printf("%-20s $%.2f   $%.2f\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

void sortStocksByChange(Stock stocks[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (stocks[j].change < stocks[j + 1].change) {
                Stock temp = stocks[j];
                stocks[j] = stocks[j + 1];
                stocks[j + 1] = temp;
            }
        }
    }
}

void showTopGainers(Stock stocks[], int count) {
    sortStocksByChange(stocks, count);
    printf("\nTop Gainers:\n");
    for (int i = 0; i < (count < 5 ? count : 5); i++) {
        printf("%d. %s: $%.2f\n", i + 1, stocks[i].name, stocks[i].change);
    }
}

void showTopLosers(Stock stocks[], int count) {
    // Sort in reverse for losers
    sortStocksByChange(stocks, count);
    printf("\nTop Losers:\n");
    for (int i = count - 1; i >= (count - 5 > 0 ? count - 5 : 0); i--) {
        printf("%d. %s: $%.2f\n", count - i, stocks[i].name, -stocks[i].change);
    }
}