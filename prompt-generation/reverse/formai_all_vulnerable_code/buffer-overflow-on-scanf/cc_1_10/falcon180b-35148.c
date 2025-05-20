//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} stock;

stock stocks[MAX_STOCKS];

int get_stock_index(char *symbol) {
    int i;
    for (i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            return i;
        }
    }
    return -1;
}

void add_stock(char *name, char *symbol, double price) {
    int index = get_stock_index(symbol);
    if (index == -1) {
        printf("Stock not found.\n");
        return;
    }
    strcpy(stocks[index].name, name);
    strcpy(stocks[index].symbol, symbol);
    stocks[index].price = price;
}

void update_stock_price(char *symbol, double price) {
    int index = get_stock_index(symbol);
    if (index == -1) {
        printf("Stock not found.\n");
        return;
    }
    stocks[index].price = price;
}

void display_stocks() {
    printf("Name\tSymbol\tPrice\n");
    int i;
    for (i = 0; i < MAX_STOCKS; i++) {
        if (strlen(stocks[i].name) > 0 && strlen(stocks[i].symbol) > 0 && stocks[i].price > 0) {
            printf("%-20s %-10s $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
        }
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;

    do {
        printf("1. Add stock\n");
        printf("2. Update stock price\n");
        printf("3. Display stocks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock symbol: ");
                scanf("%s", symbol);
                printf("Enter stock price: $");
                scanf("%lf", &price);
                add_stock(name, symbol, price);
                break;
            case 2:
                printf("Enter stock symbol: ");
                scanf("%s", symbol);
                printf("Enter new stock price: $");
                scanf("%lf", &price);
                update_stock_price(symbol, price);
                break;
            case 3:
                display_stocks();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}