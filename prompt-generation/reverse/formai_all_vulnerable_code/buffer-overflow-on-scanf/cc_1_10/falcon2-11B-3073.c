//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Global variables
int stockPrice = 0;
float portfolioValue = 0.0;
int sharesBought = 0;

// Function to get current stock price
void getStockPrice() {
    stockPrice = 100; // Assume stock price is 100 for simplicity
    printf("Current stock price: %d\n", stockPrice);
}

// Function to buy shares of stock
void buyShares() {
    int shares;
    printf("Enter number of shares to buy: ");
    scanf("%d", &shares);

    if (shares <= sharesBought) {
        printf("You already have this many shares.\n");
    } else {
        sharesBought += shares;
        portfolioValue += (stockPrice * sharesBought);
        printf("Shares bought: %d\n", shares);
        printf("Portfolio value: $%.2f\n", portfolioValue);
    }
}

// Function to sell shares of stock
void sellShares() {
    int shares;
    printf("Enter number of shares to sell: ");
    scanf("%d", &shares);

    if (shares > sharesBought) {
        printf("You don't have this many shares.\n");
    } else {
        sharesBought -= shares;
        portfolioValue -= (stockPrice * sharesBought);
        printf("Shares sold: %d\n", shares);
        printf("Portfolio value: $%.2f\n", portfolioValue);
    }
}

int main() {
    getStockPrice();

    while (1) {
        printf("1. Get stock price\n");
        printf("2. Buy shares\n");
        printf("3. Sell shares\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getStockPrice();
                break;
            case 2:
                buyShares();
                break;
            case 3:
                sellShares();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}