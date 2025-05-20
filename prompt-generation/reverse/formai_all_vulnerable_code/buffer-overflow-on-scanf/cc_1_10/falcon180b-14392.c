//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_STOCK_NAME_LENGTH 20
#define MAX_STOCK_SYMBOL_LENGTH 10
#define MAX_STOCK_PRICE_LENGTH 10

typedef struct {
    char name[MAX_STOCK_NAME_LENGTH];
    char symbol[MAX_STOCK_SYMBOL_LENGTH];
    float price;
} Stock;

Stock stocks[MAX_STOCKS];
int numStocks;

void addStock() {
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[numStocks].name);
    printf("Enter the symbol of the stock: ");
    scanf("%s", stocks[numStocks].symbol);
    printf("Enter the price of the stock: ");
    scanf("%f", &stocks[numStocks].price);
    numStocks++;
}

void displayStocks() {
    printf("\n");
    printf("Stock Name\tSymbol\tPrice\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s\t%s\t$%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
}

void updateStockPrice() {
    printf("Enter the symbol of the stock to update: ");
    char symbol[MAX_STOCK_SYMBOL_LENGTH];
    scanf("%s", symbol);
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Enter the new price of the stock: ");
            scanf("%f", &stocks[i].price);
            printf("\nStock price updated.\n");
            break;
        }
    }
}

void deleteStock() {
    printf("Enter the symbol of the stock to delete: ");
    char symbol[MAX_STOCK_SYMBOL_LENGTH];
    scanf("%s", symbol);
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            for (int j = i; j < numStocks - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            numStocks--;
            printf("\nStock deleted.\n");
            break;
        }
    }
}

int main() {
    printf("Welcome to the Ada Lovelace Stock Market Tracker!\n");
    printf("---------------------------------------------------------------\n");
    printf("1. Add a stock\n2. Display stocks\n3. Update stock price\n4. Delete stock\n5. Exit\n");
    printf("---------------------------------------------------------------\n");
    int choice;
    int validChoice = 0;
    while (!validChoice) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 5) {
            validChoice = 1;
        } else {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }
    switch (choice) {
        case 1:
            addStock();
            break;
        case 2:
            displayStocks();
            break;
        case 3:
            updateStockPrice();
            break;
        case 4:
            deleteStock();
            break;
        case 5:
            printf("Exiting...\n");
            break;
    }
    return 0;
}