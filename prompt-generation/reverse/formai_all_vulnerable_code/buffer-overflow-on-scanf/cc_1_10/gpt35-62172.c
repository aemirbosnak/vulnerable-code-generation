//FormAI DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 20

struct Stock {
    char symbol[10];
    double currentPrice;
    int volume;
};

struct Portfolio {
    struct Stock stocks[MAX_STOCKS];
    int numOfStocks;
};

double calculateTotalWorth(struct Portfolio portfolio) {
    double totalWorth = 0;
    for (int i = 0; i < portfolio.numOfStocks; i++) {
        totalWorth += (portfolio.stocks[i].currentPrice * portfolio.stocks[i].volume);
    }
    return totalWorth;
}

void printPortfolio(struct Portfolio portfolio) {
    printf("Current Portfolio:\n");
    for (int i = 0; i < portfolio.numOfStocks; i++) {
        printf("%s - Volume: %d - Current Price: $%.2f\n", portfolio.stocks[i].symbol, portfolio.stocks[i].volume, portfolio.stocks[i].currentPrice);
    }
    printf("Total portfolio worth: $%.2f\n", calculateTotalWorth(portfolio));
}

int main() {

    struct Portfolio myPortfolio = {0};
    int choice = 0;

    do {
        printf("\n1. Add stock\n2. Remove stock\n3. Update stock price\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (myPortfolio.numOfStocks == MAX_STOCKS) {
                    printf("Error: Portfolio is full. Cannot add more stocks.\n");
                    break;
                }
                struct Stock newStock = {0};
                printf("\nEnter stock symbol: ");
                scanf("%s", newStock.symbol);
                printf("Enter stock price: $");
                scanf("%lf", &newStock.currentPrice);
                printf("Enter stock volume: ");
                scanf("%d", &newStock.volume);
                myPortfolio.stocks[myPortfolio.numOfStocks] = newStock;
                myPortfolio.numOfStocks++;
                printf("\nStock added to portfolio.\n");
                printPortfolio(myPortfolio);
                break;
            }
            case 2: {
                if (myPortfolio.numOfStocks == 0) {
                    printf("Error: Portfolio is empty. Cannot remove stocks.\n");
                    break;
                }
                char symbol[10];
                printf("\nEnter stock symbol to remove: ");
                scanf("%s", symbol);
                for (int i = 0; i < myPortfolio.numOfStocks; i++) {
                    if (strcmp(myPortfolio.stocks[i].symbol, symbol) == 0) {
                        for (int j = i; j < myPortfolio.numOfStocks - 1; j++) {
                            myPortfolio.stocks[j] = myPortfolio.stocks[j + 1];
                        }
                        myPortfolio.numOfStocks--;
                        printf("\nStock removed from portfolio.\n");
                        printPortfolio(myPortfolio);
                        break;
                    }
                    if (i == myPortfolio.numOfStocks - 1) {
                        printf("\nError: Stock not found in portfolio.\n");
                    }
                }
                break;
            }
            case 3: {
                if (myPortfolio.numOfStocks == 0) {
                    printf("Error: Portfolio is empty. Cannot update stocks.\n");
                    break;
                }
                char symbol[10];
                double newPrice = 0;
                printf("\nEnter stock symbol to update: ");
                scanf("%s", symbol);
                for (int i = 0; i < myPortfolio.numOfStocks; i++) {
                    if (strcmp(myPortfolio.stocks[i].symbol, symbol) == 0) {
                        printf("Enter new stock price: $");
                        scanf("%lf", &newPrice);
                        myPortfolio.stocks[i].currentPrice = newPrice;
                        printf("\nStock price updated.\n");
                        printPortfolio(myPortfolio);
                        break;
                    }
                    if (i == myPortfolio.numOfStocks - 1) {
                        printf("\nError: Stock not found in portfolio.\n");
                    }
                }
                break;
            }
            case 4: {
                printf("\nExiting program.\n");
                break;
            }
            default: {
                printf("\nInvalid choice. Please choose again.\n");
                break;
            }
        }
    } while (choice != 4);

    return 0;
}