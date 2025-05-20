//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

void readStocks(Stock stocks[], int n) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %lf %d\n", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].quantity) == 4 && i < n) {
        i++;
    }

    fclose(fp);
}

void printStocks(Stock stocks[], int n) {
    printf("Name\tSymbol\tPrice\tQuantity\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10s $%.2f %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
}

void buyStock(Stock stocks[], int n, char symbol[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Buying %s...\n", stocks[i].name);
            stocks[i].quantity++;
            break;
        }
    }
}

void sellStock(Stock stocks[], int n, char symbol[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Selling %s...\n", stocks[i].name);
            stocks[i].quantity--;
            break;
        }
    }
}

void updatePrices(Stock stocks[], int n) {
    for (int i = 0; i < n; i++) {
        stocks[i].price += (rand() % 101 - 50) / 100.0;
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int n = 0;

    readStocks(stocks, MAX_STOCKS);
    printStocks(stocks, n);

    char choice;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Buy stock\n2. Sell stock\n3. Update prices\n4. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("Enter stock symbol: ");
            char symbol[MAX_SYMBOL_LEN];
            scanf("%s", symbol);
            buyStock(stocks, n, symbol);
            break;
        case '2':
            printf("Enter stock symbol: ");
            scanf("%s", symbol);
            sellStock(stocks, n, symbol);
            break;
        case '3':
            updatePrices(stocks, n);
            printf("\nPrices updated.\n");
            break;
        case '4':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }

        printStocks(stocks, n);
    } while (choice!= '4');

    return 0;
}