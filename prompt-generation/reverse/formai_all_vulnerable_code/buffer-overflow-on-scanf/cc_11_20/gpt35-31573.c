//FormAI DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STOCK_NAME_LEN 50
#define MAX_STOCK_SYMBOL_LEN 5
#define MAX_STOCKS 10

typedef struct {
    char symbol[MAX_STOCK_SYMBOL_LEN];
    char name[MAX_STOCK_NAME_LEN];
    float price;
    float change;
} stock;

int main() {
    int numStocks = 0;
    stock stocks[MAX_STOCKS];

    while (1) {
        system("clear"); // clear the console on each iteration

        printf("=== STOCK MARKET TRACKER ===\n\n");
        for (int i = 0; i < numStocks; i++) {
            printf("[%s] %s - $%.2f (change: %.2f%%)\n", 
                stocks[i].symbol, stocks[i].name, stocks[i].price, stocks[i].change);
        }

        printf("\nOptions:\n");
        printf("(1) Add stock\n");
        printf("(2) Remove stock\n");
        printf("(3) Update stock prices\n");
        printf("(4) Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add stock
                if (numStocks >= MAX_STOCKS) {
                    printf("ERROR: Maximum number of stocks reached.\n");
                    sleep(2); // wait for 2 seconds
                } else {
                    printf("Enter stock symbol (e.g. AAPL): ");
                    scanf("%s", stocks[numStocks].symbol);

                    printf("Enter stock name (e.g. Apple Inc.): ");
                    scanf("%s", stocks[numStocks].name);

                    printf("Enter stock price: ");
                    scanf("%f", &stocks[numStocks].price);

                    stocks[numStocks].change = 0;
                    numStocks++;

                    printf("Stock successfully added!\n");
                    sleep(2);
                }
                break;
            case 2: // Remove stock
                if (numStocks <= 0) {
                    printf("ERROR: No stocks to remove.\n");
                    sleep(2);
                } else {
                    printf("Enter stock symbol to remove: ");
                    char symbol[MAX_STOCK_SYMBOL_LEN];
                    scanf("%s", symbol);

                    int foundIndex = -1;
                    for (int i = 0; i < numStocks; i++) {
                        if (strcmp(stocks[i].symbol, symbol) == 0) {
                            foundIndex = i;
                            break;
                        }
                    }

                    if (foundIndex == -1) {
                        printf("ERROR: Stock not found.\n");
                        sleep(2);
                    } else {
                        for (int i = foundIndex; i < numStocks - 1; i++) {
                            stocks[i] = stocks[i + 1];
                        }
                        numStocks--;

                        printf("Stock successfully removed!\n");
                        sleep(2);
                    }
                }
                break;
            case 3: // Update stock prices
                if (numStocks <= 0) {
                    printf("ERROR: No stocks to update.\n");
                    sleep(2);
                } else {
                    for (int i = 0; i < numStocks; i++) {
                        printf("Enter new price for %s (%s): ", stocks[i].name, stocks[i].symbol);
                        scanf("%f", &stocks[i].price);

                        float percentageChange = ((stocks[i].price - stocks[i].change) / stocks[i].change) * 100;
                        stocks[i].change = percentageChange;
                    }

                    printf("Stock prices successfully updated!\n");
                    sleep(2);
                }
                break;
            case 4: // Exit
                printf("Exiting program...\n");
                sleep(2);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                sleep(2);
                break;
        }
    }
}