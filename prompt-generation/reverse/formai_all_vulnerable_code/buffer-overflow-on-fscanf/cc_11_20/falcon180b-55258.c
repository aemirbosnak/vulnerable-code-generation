//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
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
    int quantity;
} Stock;

int main() {
    int numStocks = 0;
    Stock stocks[MAX_STOCKS];

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %lf %d\n", stocks[numStocks].name, stocks[numStocks].symbol, &stocks[numStocks].price, &stocks[numStocks].quantity)!= EOF) {
        numStocks++;
        if (numStocks >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            exit(1);
        }
    }

    fclose(fp);

    int choice;
    do {
        printf("\nStock Market Tracker\n");
        printf("1. View Stock Prices\n");
        printf("2. Buy Stock\n");
        printf("3. Sell Stock\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < numStocks; i++) {
                    printf("%s (%s) - $%.2f - Quantity: %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
                }
                break;
            case 2:
                printf("Enter the symbol of the stock you want to buy: ");
                char symbol[MAX_SYMBOL_LEN];
                scanf("%s", symbol);

                for (int i = 0; i < numStocks; i++) {
                    if (strcmp(stocks[i].symbol, symbol) == 0) {
                        printf("Enter the quantity of %s you want to buy: ", stocks[i].name);
                        int quantity;
                        scanf("%d", &quantity);

                        if (quantity > stocks[i].quantity) {
                            printf("Error: Not enough stock available.\n");
                        } else {
                            stocks[i].quantity -= quantity;
                            printf("%d shares of %s bought.\n", quantity, stocks[i].name);
                        }

                        break;
                    }
                }

                break;
            case 3:
                printf("Enter the symbol of the stock you want to sell: ");
                char symbol2[MAX_SYMBOL_LEN];
                scanf("%s", symbol2);

                for (int i = 0; i < numStocks; i++) {
                    if (strcmp(stocks[i].symbol, symbol2) == 0) {
                        printf("Enter the quantity of %s you want to sell: ", stocks[i].name);
                        int quantity;
                        scanf("%d", &quantity);

                        if (quantity > stocks[i].quantity) {
                            printf("Error: Not enough stock available.\n");
                        } else {
                            stocks[i].quantity -= quantity;
                            printf("%d shares of %s sold.\n", quantity, stocks[i].name);
                        }

                        break;
                    }
                }

                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= 4);

    return 0;
}