//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char symbol[10];
    float price;
    float change;
} Stock;

void printMenu() {
    printf("\nWelcome to the Stock Market Tracker!\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock\n");
    printf("3. Display All Stocks\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

void inputStock(Stock *stock) {
    printf("Enter stock name: ");
    scanf("%s", stock->name);
    printf("Enter stock symbol: ");
    scanf("%s", stock->symbol);
    printf("Enter stock price: ");
    scanf("%f", &stock->price);
    printf("Enter stock price change: ");
    scanf("%f", &stock->change);
}

void updateStock(Stock *stocks, int count) {
    char symbol[10];
    printf("Enter stock symbol to update: ");
    scanf("%s", symbol);
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Updating details for %s (%s)\n", stocks[i].name, stocks[i].symbol);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Enter new price change: ");
            scanf("%f", &stocks[i].change);
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Stock with symbol %s not found.\n", symbol);
}

void displayStocks(Stock *stocks, int count) {
    printf("\nCurrent Stocks:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Symbol: %s, Price: %.2f, Change: %.2f%%\n", 
            stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].change);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    while(1) {
        printMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if (count < MAX_STOCKS) {
                    inputStock(&stocks[count]);
                    count++;
                    printf("Stock added successfully!\n");
                } else {
                    printf("Stock list is full. Cannot add more stocks.\n");
                }
                break;
            case 2:
                updateStock(stocks, count);
                break;
            case 3:
                displayStocks(stocks, count);
                break;
            case 4:
                printf("Exiting the tracker. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select from 1-4.\n");
        }
    }
    
    return 0;
}