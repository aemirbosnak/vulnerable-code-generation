//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_NAME_LENGTH];
    float price;
    float change;
} Stock;

void get_stock_info(Stock* stock) {
    printf("Enter stock name: ");
    scanf("%s", stock->name);

    printf("Enter stock symbol: ");
    scanf("%s", stock->symbol);

    printf("Enter stock price: ");
    scanf("%f", &stock->price);

    printf("Enter stock change: ");
    scanf("%f", &stock->change);
}

void display_stock_info(Stock* stock) {
    printf("Name: %s\n", stock->name);
    printf("Symbol: %s\n", stock->symbol);
    printf("Price: $%.2f\n", stock->price);
    printf("Change: $%.2f\n", stock->change);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    while (num_stocks < MAX_STOCKS) {
        printf("\nDo you want to add a stock? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y') {
            get_stock_info(&stocks[num_stocks]);
            num_stocks++;
        } else if (choice == 'n') {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    printf("\nList of stocks:\n");
    for (int i = 0; i < num_stocks; i++) {
        display_stock_info(&stocks[i]);
    }

    return 0;
}