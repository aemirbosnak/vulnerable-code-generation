//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float currentPrice;
    int sharesOwned;
} Stock;

void displayStocks(Stock stocks[], int count) {
    printf("\n STONKS TRACKER - SIMPLY THE BEST!\n");
    printf("=====================================\n");
    printf(" ID | Stock Name             | Price  | Owned \n");
    printf("-------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf(" %d  | %-20s | $%.2f | %d\n", i + 1, stocks[i].name, stocks[i].currentPrice, stocks[i].sharesOwned);
    }
    printf("-------------------------------------\n");
}

void buyStock(Stock *stock) {
    int shares;
    printf("Enter the number of shares you want to buy of %s: ", stock->name);
    scanf("%d", &shares);
    stock->sharesOwned += shares;
    printf("You have bought %d shares of %s!\n", shares, stock->name);
}

void sellStock(Stock *stock) {
    int shares;
    printf("Enter the number of shares you want to sell of %s: ", stock->name);
    scanf("%d", &shares);
    if (shares > stock->sharesOwned) {
        printf("You do not have enough shares to sell!\n");
    } else {
        stock->sharesOwned -= shares;
        printf("You have sold %d shares of %s!\n", shares, stock->name);
    }
}

void updateStockPrice(Stock *stock) {
    float newPrice;
    printf("Enter the new price for %s: ", stock->name);
    scanf("%f", &newPrice);
    stock->currentPrice = newPrice;
    printf("The new price of %s is updated to $%.2f!\n", stock->name, stock->currentPrice);
}

int main() {
    Stock stocks[MAX_STOCKS] = {
        {"AAPL", 145.30, 0},
        {"TSLA", 730.00, 0},
        {"GOOGL", 2750.00, 0},
        {"MSFT", 300.50, 0},
        {"AMZN", 3400.00, 0},
        {"FB", 350.00, 0},
        {"NFLX", 600.00, 0},
        {"NVDA", 220.00, 0},
        {"NFLX", 550.00, 0},
        {"BABA", 150.00, 0}
    };
    
    int choice, count = 10;
    
    while (1) {
        printf("\nWelcome to the Retro Stock Market Tracker!\n");
        printf("1. Display Stocks\n");
        printf("2. Buy Stock\n");
        printf("3. Sell Stock\n");
        printf("4. Update Stock Price\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStocks(stocks, count);
                break;
            case 2: {
                int stockID;
                displayStocks(stocks, count);
                printf("Select a stock ID to buy: ");
                scanf("%d", &stockID);
                if (stockID > 0 && stockID <= count) {
                    buyStock(&stocks[stockID - 1]);
                } else {
                    printf("Invalid Stock ID!\n");
                }
                break;
            }
            case 3: {
                int stockID;
                displayStocks(stocks, count);
                printf("Select a stock ID to sell: ");
                scanf("%d", &stockID);
                if (stockID > 0 && stockID <= count) {
                    sellStock(&stocks[stockID - 1]);
                } else {
                    printf("Invalid Stock ID!\n");
                }
                break;
            }
            case 4: {
                int stockID;
                displayStocks(stocks, count);
                printf("Select a stock ID to update its price: ");
                scanf("%d", &stockID);
                if (stockID > 0 && stockID <= count) {
                    updateStockPrice(&stocks[stockID - 1]);
                } else {
                    printf("Invalid Stock ID!\n");
                }
                break;
            }
            case 5:
                printf("Exiting the tracker. Happy trading!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}