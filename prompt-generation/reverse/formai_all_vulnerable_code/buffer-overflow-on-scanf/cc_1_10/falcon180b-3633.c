//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME 20
#define MAX_SYMBOL 10

typedef struct {
    char name[MAX_NAME];
    char symbol[MAX_SYMBOL];
    double price;
    int quantity;
} Stock;

void print_menu() {
    printf("\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. Update Stock Quantity\n");
    printf("4. View Portfolio\n");
    printf("5. Exit\n");
    printf("\n");
}

int main() {
    Stock portfolio[MAX_STOCKS];
    int num_stocks = 0;
    char choice;

    printf("Welcome to the Stock Market Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", portfolio[num_stocks].name);
    strcpy(portfolio[num_stocks].symbol, "N/A");
    portfolio[num_stocks].price = 0;
    portfolio[num_stocks].quantity = 0;
    num_stocks++;

    while (1) {
        print_menu();
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_stocks >= MAX_STOCKS) {
                    printf("Portfolio is full. Please remove a stock first.\n");
                } else {
                    printf("Enter stock name: ");
                    scanf("%s", portfolio[num_stocks].name);
                    strcpy(portfolio[num_stocks].symbol, "N/A");
                    portfolio[num_stocks].price = 0;
                    portfolio[num_stocks].quantity = 0;
                    num_stocks++;
                }
                break;
            case '2':
                printf("Enter stock symbol: ");
                scanf("%s", portfolio[num_stocks - 1].symbol);
                printf("Enter new price: ");
                scanf("%lf", &portfolio[num_stocks - 1].price);
                break;
            case '3':
                printf("Enter stock symbol: ");
                scanf("%s", portfolio[num_stocks - 1].symbol);
                printf("Enter new quantity: ");
                scanf("%d", &portfolio[num_stocks - 1].quantity);
                break;
            case '4':
                printf("\nPortfolio:\n");
                for (int i = 0; i < num_stocks; i++) {
                    printf("%s - %s - $%.2lf - %d shares\n", portfolio[i].name, portfolio[i].symbol, portfolio[i].price, portfolio[i].quantity);
                }
                break;
            case '5':
                printf("Thank you for using the Stock Market Tracker. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}