//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10

typedef struct {
    char symbol[10];
    float price;
} Stock;

int num_stocks = 0;
Stock stocks[MAX_STOCKS];

void add_stock();
void delete_stock();
void display_stocks();

int main() {
    char choice;

    do {
        printf("\nStock Market Tracker\n");
        printf("1. Add a stock\n");
        printf("2. Delete a stock\n");
        printf("3. Display stocks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_stock();
                break;
            case '2':
                delete_stock();
                break;
            case '3':
                display_stocks();
                break;
            case '4':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != '4');

    return 0;
}

void add_stock() {
    if (num_stocks == MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }

    printf("\nEnter stock symbol: ");
    scanf("%s", stocks[num_stocks].symbol);

    printf("Enter stock price: ");
    scanf("%f", &stocks[num_stocks].price);

    num_stocks++;
}

void delete_stock() {
    if (num_stocks == 0) {
        printf("No stocks to delete.\n");
        return;
    }

    char symbol[10];
    int i, j;

    printf("\nEnter stock symbol to delete: ");
    scanf("%s", symbol);

    for (i = 0; i < num_stocks; i++) {
        if (strcmp(symbol, stocks[i].symbol) == 0) {
            for (j = i; j < num_stocks - 1; j++) {
                strcpy(stocks[j].symbol, stocks[j+1].symbol);
                stocks[j].price = stocks[j+1].price;
            }
            num_stocks--;
            printf("Stock deleted.\n");
            return;
        }
    }

    printf("Stock not found.\n");
}

void display_stocks() {
    int i;

    if (num_stocks == 0) {
        printf("No stocks to display.\n");
        return;
    }

    printf("\nStocks in portfolio:\n");
    for (i = 0; i < num_stocks; i++) {
        printf("%-10s $%7.2f\n", stocks[i].symbol, stocks[i].price);
    }
}