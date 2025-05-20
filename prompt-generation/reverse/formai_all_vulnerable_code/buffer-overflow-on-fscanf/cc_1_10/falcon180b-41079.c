//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

void read_stocks(Stock stocks[]) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %lf %d\n", stocks[count].name, stocks[count].symbol, &stocks[count].price, &stocks[count].quantity) == 4) {
        count++;
        if (count >= MAX_STOCKS) {
            printf("Error: Too many stocks in file.\n");
            exit(1);
        }
    }

    fclose(fp);
}

void print_stocks(Stock stocks[]) {
    printf("Name\tSymbol\tPrice\tQuantity\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            printf("%-20s\t%s\t%.2lf\t%d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
        }
    }
}

void update_stock(Stock stocks[], char symbol[]) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Enter new price for %s: ", stocks[i].name);
            scanf("%lf", &stocks[i].price);
            printf("Enter new quantity for %s: ", stocks[i].name);
            scanf("%d", &stocks[i].quantity);
            break;
        }
    }
}

void buy_stock(Stock stocks[], char symbol[]) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("You bought %d shares of %s at $%.2lf.\n", stocks[i].quantity, stocks[i].name, stocks[i].price);
            break;
        }
    }
}

void sell_stock(Stock stocks[], char symbol[]) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("You sold %d shares of %s at $%.2lf.\n", stocks[i].quantity, stocks[i].name, stocks[i].price);
            break;
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    read_stocks(stocks);
    print_stocks(stocks);

    char choice;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Buy stock\n2. Sell stock\n3. Update stock price/quantity\n4. Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter stock symbol: ");
                char symbol[MAX_SYMBOL_LEN];
                scanf("%s", symbol);
                buy_stock(stocks, symbol);
                break;
            case '2':
                printf("Enter stock symbol: ");
                scanf("%s", symbol);
                sell_stock(stocks, symbol);
                break;
            case '3':
                printf("Enter stock symbol: ");
                scanf("%s", symbol);
                update_stock(stocks, symbol);
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice!= '4');

    return 0;
}