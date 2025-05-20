//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    float price;
    int quantity;
} Stock;

Stock stocks[MAX_STOCKS];
int numStocks;

void addStock() {
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[numStocks].name);
    printf("Enter the symbol of the stock: ");
    scanf("%s", stocks[numStocks].symbol);
    printf("Enter the current price of the stock: ");
    scanf("%f", &stocks[numStocks].price);
    printf("Enter the quantity of the stock: ");
    scanf("%d", &stocks[numStocks].quantity);
    numStocks++;
}

void displayStocks() {
    printf("\nName\tSymbol\tPrice\tQuantity\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s\t%s\t%.2f\t%d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
}

void searchStock() {
    char searchSymbol[MAX_SYMBOL_LENGTH];
    printf("Enter the symbol of the stock you want to search: ");
    scanf("%s", searchSymbol);
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].symbol, searchSymbol) == 0) {
            printf("\nName: %s\nSymbol: %s\nPrice: %.2f\nQuantity: %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
        }
    }
}

void main() {
    printf("Welcome to the Stock Market Tracker!\n");
    printf("Please choose an option:\n");
    printf("1. Add a stock\n");
    printf("2. Display all stocks\n");
    printf("3. Search for a stock\n");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            addStock();
            break;
        case 2:
            displayStocks();
            break;
        case 3:
            searchStock();
            break;
        default:
            printf("Invalid choice.\n");
    }
}