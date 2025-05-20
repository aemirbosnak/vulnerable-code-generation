//FormAI DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10

typedef struct Stock {
    char ticker[10];
    float price;
    float change;
} Stock;

void printStock(Stock s);
void updateStock(Stock *s, float newPrice);
void displayStocks(Stock *stocks, int numStocks);

int main() {
    int numStocks = 0;
    Stock stocks[MAX_STOCKS];
    char choice;
    printf("Welcome to the Stock Market Tracker!\n");
    do {
        printf("Menu:\n");
        printf("1) Add a stock\n");
        printf("2) Update a stock price\n");
        printf("3) Display all stocks\n");
        printf("4) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                if(numStocks >= MAX_STOCKS) {
                    printf("Sorry, the maximum number of stocks has been reached.\n");
                } else {
                    Stock newStock;
                    printf("Enter the stock ticker: ");
                    scanf("%s", newStock.ticker);
                    printf("Enter the stock price: ");
                    scanf("%f", &newStock.price);
                    newStock.change = 0;
                    stocks[numStocks] = newStock;
                    numStocks++;
                    printf("Stock added successfully!\n");
                }
                break;
            case '2':
                if(numStocks == 0) {
                    printf("No stocks found.\n");
                } else {
                    char ticker[10];
                    float newPrice;
                    printf("Enter the stock ticker: ");
                    scanf("%s", ticker);
                    int found = 0;
                    for(int i = 0; i < numStocks; i++) {
                        if(strcmp(stocks[i].ticker, ticker) == 0) {
                            printf("Enter the new stock price: ");
                            scanf("%f", &newPrice);
                            updateStock(&stocks[i], newPrice);
                            found = 1;
                            printf("Stock updated successfully!\n");
                            break;
                        }
                    }
                    if(!found) {
                        printf("No stock with ticker %s found.\n", ticker);
                    }
                }
                break;
            case '3':
                displayStocks(stocks, numStocks);
                break;
            case '4':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != '4');
    return 0;
}

void printStock(Stock s) {
    printf("%s: $%.2f (%+.2f%%)\n", s.ticker, s.price, s.change);
}

void updateStock(Stock *s, float newPrice) {
    s->change = (newPrice - s->price) / s->price * 100;
    s->price = newPrice;
}

void displayStocks(Stock *stocks, int numStocks) {
    if(numStocks == 0) {
        printf("No stocks found.\n");
    } else {
        printf("Stocks:\n");
        for(int i = 0; i < numStocks; i++) {
            printStock(stocks[i]);
        }
    }
}