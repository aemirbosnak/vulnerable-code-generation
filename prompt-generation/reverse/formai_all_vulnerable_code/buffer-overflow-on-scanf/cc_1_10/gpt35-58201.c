//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SYMBOL_LENGTH 10
#define MAX_STOCKS 100

struct stock {
    char symbol[MAX_SYMBOL_LENGTH];
    float price;
    int volume;
};

struct stock stocks[MAX_STOCKS];
int num_of_stocks = 0;

void add_stock() {
    // check if there is enough space in stocks array
    if (num_of_stocks >= MAX_STOCKS) {
        printf("ERROR: Maximum number of stocks reached.\n");
        return;
    }

    // get symbol from user
    char symbol[MAX_SYMBOL_LENGTH];
    printf("Enter the symbol for the stock: ");
    scanf("%s", symbol);

    // check if the symbol is already in the stocks array
    for (int i = 0; i < num_of_stocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("ERROR: Stock with symbol %s already exists.\n", symbol);
            return;
        }
    }

    // get price from user
    float price;
    printf("Enter the price for the stock: ");
    scanf("%f", &price);

    // get volume from user
    int volume;
    printf("Enter the volume for the stock: ");
    scanf("%d", &volume);

    // add stock to stocks array
    struct stock new_stock;
    strcpy(new_stock.symbol, symbol);
    new_stock.price = price;
    new_stock.volume = volume;
    stocks[num_of_stocks] = new_stock;
    num_of_stocks++;
    printf("Stock with symbol %s added successfully.\n", symbol);
}

void remove_stock() {
    // get symbol from user
    char symbol[MAX_SYMBOL_LENGTH];
    printf("Enter the symbol of the stock to remove: ");
    scanf("%s", symbol);

    // find the stock with given symbol and remove it
    int found = 0;
    for (int i = 0; i < num_of_stocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            // found the stock, remove it
            for (int j = i; j < num_of_stocks - 1; j++) {
                stocks[j] = stocks[j+1];
            }
            num_of_stocks--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Stock with symbol %s removed successfully.\n", symbol);
    } else {
        printf("ERROR: Stock with symbol %s not found.\n", symbol);
    }
}

void print_stocks() {
    printf("Stocks:\n");
    printf("%-10s%-10s%-10s\n", "Symbol", "Price", "Volume");
    for (int i = 0; i < num_of_stocks; i++) {
        printf("%-10s%-10.2f%-10d\n", stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }
}

void update_prices() {
    printf("Updating prices...\n");
    for (int i = 0; i < num_of_stocks; i++) {
        stocks[i].price = (float)rand()/(float)(RAND_MAX/50.0);
    }
    printf("Prices updated successfully.\n");
}

int main() {
    while (1) {
        printf("Menu:\n");
        printf("1. Add stock\n");
        printf("2. Remove stock\n");
        printf("3. Print stocks\n");
        printf("4. Update prices\n");
        printf("5. Quit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_stock();
                break;
            case 2:
                remove_stock();
                break;
            case 3:
                print_stocks();
                break;
            case 4:
                update_prices();
                break;
            case 5:
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

        sleep(1);
        printf("\n");
    }

    return 0;
}