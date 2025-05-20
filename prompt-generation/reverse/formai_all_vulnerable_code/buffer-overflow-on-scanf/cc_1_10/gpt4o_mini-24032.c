//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LEN 30

typedef struct {
    char name[NAME_LEN];
    float price;
    float change;
} Stock;

void initializeStocks(Stock stocks[], int count);
void displayStocks(const Stock stocks[], int count);
void updateStocks(Stock stocks[], int count);
void generateRandomChanges(Stock stocks[], int count);

int main() {
    srand(time(0)); // Seed for random number generation

    int stockCount;
    printf("Enter the number of stocks to track (max %d): ", MAX_STOCKS);
    scanf("%d", &stockCount);

    if (stockCount > MAX_STOCKS || stockCount <= 0) {
        printf("Invalid number of stocks. Please enter between 1 and %d.\n", MAX_STOCKS);
        return 1;
    }

    Stock stocks[MAX_STOCKS];
    initializeStocks(stocks, stockCount);

    char choice;
    do {
        printf("\n--- Stock Market Tracker ---\n");
        displayStocks(stocks, stockCount);
        printf("Press 'u' to update stock values or 'q' to quit: ");
        scanf(" %c", &choice);

        if (choice == 'u') {
            updateStocks(stocks, stockCount);
        }
    } while (choice != 'q');

    printf("Thank you for using the Stock Market Tracker!\n");
    return 0;
}

void initializeStocks(Stock stocks[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for stock %d: ", i + 1);
        scanf("%s", stocks[i].name);
        stocks[i].price = (float)(rand() % 10000) / 100; // Price between 0.00 and 99.99
        stocks[i].change = (float)(rand() % 2000 - 1000) / 100; // Change between -10.00 and +10.00
    }
}

void displayStocks(const Stock stocks[], int count) {
    printf("\n%-20s%-10s%-10s\n", "Stock Name", "Price", "Change");
    printf("------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s%-10.2f%-10.2f\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    printf("------------------------------------------\n");
}

void updateStocks(Stock stocks[], int count) {
    generateRandomChanges(stocks, count);
    printf("Stocks updated successfully.\n");
}

void generateRandomChanges(Stock stocks[], int count) {
    for (int i = 0; i < count; i++) {
        float change = (float)(rand() % 2000 - 1000) / 100; // Random change
        stocks[i].price += change; // Apply change to price
        stocks[i].change = change; // Update change record
        // Ensure price does not go below zero
        if (stocks[i].price < 0) {
            stocks[i].price = 0.0;
        }
    }
}