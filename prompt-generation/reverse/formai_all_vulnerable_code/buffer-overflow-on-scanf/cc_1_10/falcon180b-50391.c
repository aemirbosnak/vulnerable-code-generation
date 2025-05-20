//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a stock
typedef struct {
    char name[50];
    float price;
} Stock;

// Function to print the stock details
void printStock(Stock s) {
    printf("Name: %s\n", s.name);
    printf("Price: $%.2f\n", s.price);
}

// Function to update the stock price
void updateStock(Stock *s, float newPrice) {
    s->price = newPrice;
}

// Function to buy a stock
void buyStock(Stock *s, float quantity, float price) {
    printf("Buying %s at $%.2f per share.\n", s->name, price);
    s->price = price;
}

// Function to sell a stock
void sellStock(Stock *s, float quantity, float price) {
    printf("Selling %s at $%.2f per share.\n", s->name, price);
    s->price = price;
}

// Function to track the stock market
void trackStockMarket(Stock *stocks, int numStocks, float startPrice, float endPrice, int days) {
    printf("Tracking the stock market for %d days...\n", days);
    for (int i = 0; i < numStocks; i++) {
        printf("Initial stock price for %s: $%.2f\n", stocks[i].name, startPrice);
    }
    for (int i = 0; i < numStocks; i++) {
        for (int j = 0; j < days; j++) {
            if (j % 2 == 0) {
                buyStock(&stocks[i], 1, startPrice + (j * 0.01));
            } else {
                sellStock(&stocks[i], 1, endPrice - (j * 0.01));
            }
        }
    }
}

// Main function
int main() {
    Stock stocks[3] = {{"Apple", 100.00}, {"Google", 50.00}, {"Microsoft", 75.00}};
    int numStocks = sizeof(stocks) / sizeof(stocks[0]);
    float startPrice = 0.00;
    float endPrice = 100.00;
    int days = 10;

    printf("Enter the starting stock price: ");
    scanf("%f", &startPrice);

    printf("Enter the ending stock price: ");
    scanf("%f", &endPrice);

    printf("Enter the number of days to track the stock market: ");
    scanf("%d", &days);

    trackStockMarket(stocks, numStocks, startPrice, endPrice, days);

    return 0;
}