//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double current_price;
    double initial_price;
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char* name, char* symbol, double current_price, double initial_price) {
    if (num_stocks >= MAX_STOCKS) {
        printf("Sorry, you've reached the maximum number of stocks (%d)!\n", MAX_STOCKS);
        return;
    }

    strcpy(stocks[num_stocks].name, name);
    strcpy(stocks[num_stocks].symbol, symbol);
    stocks[num_stocks].current_price = current_price;
    stocks[num_stocks].initial_price = initial_price;

    printf("Stock added successfully!\n");
    num_stocks++;
}

void remove_stock(char* symbol) {
    int i;

    for (i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Stock removed successfully!\n");
            num_stocks--;
            break;
        }
    }
}

void display_stocks() {
    int i;

    for (i = 0; i < num_stocks; i++) {
        printf("Name: %s\nSymbol: %s\nCurrent Price: $%.2f\nInitial Price: $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].current_price, stocks[i].initial_price);
    }
}

int main() {
    int choice;

    printf("Welcome to the Stock Market Tracker!\n");
    printf("1. Add a stock\n2. Remove a stock\n3. Display stocks\n4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the stock: ");
                scanf("%s", stocks[num_stocks].name);
                printf("Enter the symbol of the stock: ");
                scanf("%s", stocks[num_stocks].symbol);
                printf("Enter the current price of the stock: $");
                scanf("%lf", &stocks[num_stocks].current_price);
                printf("Enter the initial price of the stock: $");
                scanf("%lf", &stocks[num_stocks].initial_price);
                break;

            case 2:
                printf("Enter the symbol of the stock to remove: ");
                scanf("%s", stocks[num_stocks].symbol);
                remove_stock(stocks[num_stocks].symbol);
                break;

            case 3:
                display_stocks();
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}