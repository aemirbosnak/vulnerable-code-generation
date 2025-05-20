//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define TickerLength 10

typedef struct {
    char ticker[TickerLength];
    float price;
    int volume;
} Stock;

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Cannot add more stocks. Maximum limit reached.\n");
        return;
    }

    Stock newStock;

    printf("Enter stock ticker: ");
    scanf("%s", newStock.ticker);
    
    // Simulate fetching stock price and volume
    newStock.price = (float)(rand() % 10000) / 100; // Random price from 0.00 to 99.99
    newStock.volume = rand() % 10000; // Random volume

    stocks[*count] = newStock;
    (*count)++;
    printf("Added: %s Price: %.2f Volume: %d\n", newStock.ticker, newStock.price, newStock.volume);
}

void displayStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks currently being tracked.\n");
        return;
    }

    printf("Tracked Stocks:\n");
    for (int i = 0; i < count; i++) {
        printf("Ticker: %s | Price: %.2f | Volume: %d\n", stocks[i].ticker, stocks[i].price, stocks[i].volume);
    }
}

void updateStock(Stock stocks[], int count) {
    char ticker[TickerLength];
    printf("Enter the stock ticker to update: ");
    scanf("%s", ticker);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            // Simulate fetching new stock information
            stocks[i].price = (float)(rand() % 10000) / 100; // New random price
            stocks[i].volume = rand() % 10000; // New random volume
            printf("Updated %s to Price: %.2f Volume: %d\n", ticker, stocks[i].price, stocks[i].volume);
            return;
        }
    }
    printf("Stock ticker %s not found.\n", ticker);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;

    srand(time(NULL)); // Seed for random number generation
    int choice;

    do {
        printf("\nStock Market Tracker\n");
        printf("1. Add Stock\n");
        printf("2. Display Stocks\n");
        printf("3. Update Stock\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &count);
                break;
            case 2:
                displayStocks(stocks, count);
                break;
            case 3:
                updateStock(stocks, count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}