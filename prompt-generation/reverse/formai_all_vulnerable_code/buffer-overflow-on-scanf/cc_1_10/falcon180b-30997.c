//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

Stock stocks[MAX_STOCKS];

int numStocks;

void addStock() {
    printf("Enter stock name: ");
    scanf("%s", stocks[numStocks].name);

    printf("Enter stock symbol: ");
    scanf("%s", stocks[numStocks].symbol);

    printf("Enter stock price: ");
    scanf("%lf", &stocks[numStocks].price);

    numStocks++;
}

void removeStock() {
    int index;

    printf("Enter stock index to remove: ");
    scanf("%d", &index);

    if (index >= 0 && index < numStocks) {
        numStocks--;

        for (int i = index; i < numStocks; i++) {
            strcpy(stocks[i].name, stocks[i+1].name);
            strcpy(stocks[i].symbol, stocks[i+1].symbol);
            stocks[i].price = stocks[i+1].price;
        }
    } else {
        printf("Invalid stock index.\n");
    }
}

void updateStockPrice() {
    int index;

    printf("Enter stock index to update: ");
    scanf("%d", &index);

    if (index >= 0 && index < numStocks) {
        printf("Enter new stock price: ");
        scanf("%lf", &stocks[index].price);
    } else {
        printf("Invalid stock index.\n");
    }
}

void displayStocks() {
    printf("Stock Name\tSymbol\tPrice\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%-20s\t%-10s\t%10.2lf\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
}

int main() {
    numStocks = 0;

    while (1) {
        printf("\n1. Add stock\n2. Remove stock\n3. Update stock price\n4. Display stocks\n5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                removeStock();
                break;
            case 3:
                updateStockPrice();
                break;
            case 4:
                displayStocks();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}