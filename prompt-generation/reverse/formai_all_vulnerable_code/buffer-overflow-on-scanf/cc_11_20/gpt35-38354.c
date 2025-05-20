//FormAI DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} stock;

int main() {
    stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    char *input = malloc(MAX_NAME_LENGTH * sizeof(char));
    int i, j;
    float price;

    printf("Welcome to the stock market tracker!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a stock\n");
        printf("2. Remove a stock\n");
        printf("3. View all stocks\n");
        printf("4. View a stock's price\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (num_stocks == MAX_STOCKS) {
                    printf("\nSorry, the maximum number of stocks has been reached.\n");
                    break;
                }

                printf("\nEnter the stock name: ");
                scanf("%s", input);

                for (i = 0; i < num_stocks; i++) {
                    if (strcmp(stocks[i].name, input) == 0) {
                        printf("\nSorry, that stock already exists.\n");
                        goto end;
                    }
                }

                strcpy(stocks[num_stocks].name, input);
                printf("Enter the stock price: ");
                scanf("%f", &price);
                stocks[num_stocks].price = price;

                printf("\nThe stock has been successfully added!\n");
                num_stocks++;
                break;

            case 2:
                printf("\nEnter the stock name: ");
                scanf("%s", input);

                for (i = 0; i < num_stocks; i++) {
                    if (strcmp(stocks[i].name, input) == 0) {
                        printf("\nThe stock has been successfully removed!\n");
                        num_stocks--;
                        for (j = i; j < num_stocks; j++) {
                            strcpy(stocks[j].name, stocks[j+1].name);
                            stocks[j].price = stocks[j+1].price;
                        }
                        goto end;
                    }
                }

                printf("\nSorry, that stock does not exist.\n");
                break;

            case 3:
                printf("\nCurrent stock prices:\n");
                for (i = 0; i < num_stocks; i++) {
                    printf("%s: %.2f\n", stocks[i].name, stocks[i].price);
                }
                break;

            case 4:
                printf("\nEnter the stock name: ");
                scanf("%s", input);

                for (i = 0; i < num_stocks; i++) {
                    if (strcmp(stocks[i].name, input) == 0) {
                        printf("%s's current price is: %.2f\n", stocks[i].name, stocks[i].price);
                        goto end;
                    }
                }

                printf("\nSorry, that stock does not exist.\n");
                break;

            case 5:
                printf("\nGoodbye!\n");
                free(input);
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        end:
            continue;
    }
}