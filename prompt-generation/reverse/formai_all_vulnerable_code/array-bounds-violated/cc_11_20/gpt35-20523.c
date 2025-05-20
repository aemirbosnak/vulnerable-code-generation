//FormAI DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_STOCKS = 10;

typedef struct stock {
    char name[20];
    float price;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;
    char input[20];

    printf("Welcome to the stock market tracker!\n");

    while (1) {
        printf("\nPlease select an option:\n1. Add a stock\n2. Remove a stock\n3. View all stocks\n4. Exit\n");

        fgets(input, sizeof(input), stdin);

        int choice = atoi(input);

        switch (choice) {
            case 1: {
                if (numStocks >= MAX_STOCKS) {
                    printf("Sorry, you have reached the maximum number of stocks.\n");
                    break;
                }

                Stock newStock;

                printf("Enter the stock name: ");
                fgets(newStock.name, sizeof(newStock.name), stdin);

                // remove newline character from input
                size_t len = strlen(newStock.name);
                if (newStock.name[len - 1] == '\n') {
                    newStock.name[len - 1] = '\0';
                }

                printf("Enter the stock price: ");
                fgets(input, sizeof(input), stdin);
                newStock.price = atof(input);

                stocks[numStocks] = newStock;
                numStocks++;

                printf("Successfully added the stock!\n");
                break;
            }
            case 2: {
                printf("Enter the stock name to remove: ");
                fgets(input, sizeof(input), stdin);

                size_t len = strlen(input);
                if (input[len - 1] == '\n') {
                    input[len - 1] = '\0';
                }

                int indexToRemove = -1;

                for (int i = 0; i < numStocks; i++) {
                    if (strcmp(stocks[i].name, input) == 0) {
                        indexToRemove = i;
                        break;
                    }
                }

                if (indexToRemove != -1) {
                    for (int i = indexToRemove; i < numStocks - 1; i++) {
                        stocks[i] = stocks[i + 1];
                    }

                    numStocks--;

                    printf("Successfully removed the stock!\n");
                } else {
                    printf("Sorry, that stock does not exist.\n");
                }

                break;
            }
            case 3: {
                if (numStocks == 0) {
                    printf("No stocks to display.\n");
                } else {
                    printf("Stocks:\n");

                    for (int i = 0; i < numStocks; i++) {
                        printf("%d. %s - $%.2f\n", i + 1, stocks[i].name, stocks[i].price);
                    }
                }

                break;
            }
            case 4: {
                printf("Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Sorry, that is not a valid option.\n");
                break;
            }
        }
    }

    return 0;
}