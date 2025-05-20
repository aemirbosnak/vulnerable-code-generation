//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
} stock;

int main() {
    int num_stocks = 0;
    stock stocks[MAX_STOCKS];
    char choice;
    double total_value = 0;

    printf("Welcome to the Stock Market Tracker!\n");
    printf("Please enter the number of stocks you would like to track (up to %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i+1);
        scanf("%s", stocks[i].name);
        printf("Enter the symbol of stock %d: ", i+1);
        scanf("%s", stocks[i].symbol);
        stocks[i].price = 0;
        total_value += 0;
    }

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. View current stock prices\n");
        printf("2. Update stock prices\n");
        printf("3. View total value of portfolio\n");
        printf("4. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                for (int i = 0; i < num_stocks; i++) {
                    printf("Stock %d: %s (%s) - $%.2f\n", i+1, stocks[i].name, stocks[i].symbol, stocks[i].price);
                }
                break;
            case '2':
                for (int i = 0; i < num_stocks; i++) {
                    printf("Enter the new price for stock %d: ", i+1);
                    scanf("%lf", &stocks[i].price);
                    total_value += stocks[i].price;
                }
                printf("\nTotal value of portfolio: $%.2f\n", total_value);
                break;
            case '3':
                printf("Total value of portfolio: $%.2f\n", total_value);
                break;
            case '4':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option selected.\n");
        }
    }

    return 0;
}