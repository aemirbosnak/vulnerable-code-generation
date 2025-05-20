//FormAI DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STOCKS 5
#define MAX_NAME_LEN 20

int main()
{
    srand(time(NULL)); // initialize random seed

    char stocks[STOCKS][MAX_NAME_LEN] = {"AAPL", "GOOG", "MSFT", "AMZN", "FB"};
    double prices[STOCKS] = {100, 500, 200, 1500, 250};
    int shares[STOCKS] = {10, 5, 25, 2, 8};

    printf("Welcome to the stock market tracker!\n");

    char choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. View prices\n");
        printf("2. Buy shares\n");
        printf("3. Sell shares\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': // View prices
                printf("\nCurrent prices:\n");
                for (int i = 0; i < STOCKS; i++) {
                    printf("%s: $%.2lf\n", stocks[i], prices[i]);
                }
                break;

            case '2': // Buy shares
                printf("\nEnter the name of the stock you want to buy: ");
                char stock_name[MAX_NAME_LEN];
                scanf("%s", stock_name);

                int stock_index = -1;
                for (int i = 0; i < STOCKS; i++) {
                    if (strcmp(stock_name, stocks[i]) == 0) {
                        stock_index = i;
                        break;
                    }
                }

                if (stock_index == -1) {
                    printf("Stock not found.\n");
                } else {
                    printf("Enter the number of shares you want to buy: ");
                    int num_shares;
                    scanf("%d", &num_shares);
                    double cost = num_shares * prices[stock_index];
                    printf("Cost of %.2f shares of %s: $%.2lf\n", num_shares, stocks[stock_index], cost);
                    printf("Confirm purchase? (y/n): ");
                    char confirm;
                    scanf(" %c", &confirm);
                    if (confirm == 'y' || confirm == 'Y') {
                        shares[stock_index] += num_shares;
                        printf("Purchase complete.\n");
                    } else {
                        printf("Purchase cancelled.\n");
                    }
                }
                break;

            case '3': // Sell shares
                printf("\nEnter the name of the stock you want to sell: ");
                char stock_name2[MAX_NAME_LEN];
                scanf("%s", stock_name2);

                int stock_index2 = -1;
                for (int i = 0; i < STOCKS; i++) {
                    if (strcmp(stock_name2, stocks[i]) == 0) {
                        stock_index2 = i;
                        break;
                    }
                }

                if (stock_index2 == -1) {
                    printf("Stock not found.\n");
                } else {
                    printf("Enter the number of shares you want to sell: ");
                    int num_shares2;
                    scanf("%d", &num_shares2);
                    if (num_shares2 > shares[stock_index2]) {
                        printf("You don't own enough shares to sell that many.\n");
                    } else {
                        double revenue = num_shares2 * prices[stock_index2];
                        printf("Revenue from selling %.2f shares of %s: $%.2lf\n", num_shares2, stocks[stock_index2], revenue);
                        printf("Confirm sale? (y/n): ");
                        char confirm2;
                        scanf(" %c", &confirm2);
                        if (confirm2 == 'y' || confirm2 == 'Y') {
                            shares[stock_index2] -= num_shares2;
                            printf("Sale complete.\n");
                        } else {
                            printf("Sale cancelled.\n");
                        }
                    }
                }
                break;

            case '4': // Quit
                printf("\nGoodbye.\n");
                break;

            default:
                printf("\nInvalid choice.\n");
                break;
        }

    } while (choice != '4');

    return 0;
}