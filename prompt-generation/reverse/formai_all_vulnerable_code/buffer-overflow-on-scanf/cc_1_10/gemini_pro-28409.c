//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float percent_change;
} Stock;

Stock stocks[MAX_STOCKS];

void print_menu() {
    printf("Stock Market Tracker\n");
    printf("--------------------\n");
    printf("1. Add a stock\n");
    printf("2. Remove a stock\n");
    printf("3. Update a stock price\n");
    printf("4. Print all stocks\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    int num_stocks = 0;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_stocks >= MAX_STOCKS) {
                    printf("Error: Maximum number of stocks reached.\n");
                } else {
                    printf("Enter the stock name: ");
                    scanf("%s", stocks[num_stocks].name);
                    printf("Enter the stock price: ");
                    scanf("%f", &stocks[num_stocks].price);
                    stocks[num_stocks].percent_change = 0.0f;
                    num_stocks++;
                }
                break;
            case 2:
                if (num_stocks <= 0) {
                    printf("Error: No stocks to remove.\n");
                } else {
                    printf("Enter the stock name to remove: ");
                    char name[MAX_NAME_LENGTH];
                    scanf("%s", name);
                    int found = 0;
                    for (int i = 0; i < num_stocks; i++) {
                        if (strcmp(stocks[i].name, name) == 0) {
                            found = 1;
                            for (int j = i; j < num_stocks - 1; j++) {
                                stocks[j] = stocks[j + 1];
                            }
                            num_stocks--;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Error: Stock not found.\n");
                    }
                }
                break;
            case 3:
                if (num_stocks <= 0) {
                    printf("Error: No stocks to update.\n");
                } else {
                    printf("Enter the stock name to update: ");
                    char name[MAX_NAME_LENGTH];
                    scanf("%s", name);
                    int found = 0;
                    for (int i = 0; i < num_stocks; i++) {
                        if (strcmp(stocks[i].name, name) == 0) {
                            found = 1;
                            printf("Enter the new stock price: ");
                            scanf("%f", &stocks[i].price);
                            printf("Enter the percent change since last update: ");
                            scanf("%f", &stocks[i].percent_change);
                            break;
                        }
                    }
                    if (!found) {
                        printf("Error: Stock not found.\n");
                    }
                }
                break;
            case 4:
                if (num_stocks <= 0) {
                    printf("Error: No stocks to print.\n");
                } else {
                    printf("--------------------\n");
                    printf("%-20s%10s%10s\n", "Name", "Price", "% Change");
                    printf("--------------------\n");
                    for (int i = 0; i < num_stocks; i++) {
                        printf("%-20s$%.2f%10.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].percent_change);
                    }
                    printf("--------------------\n");
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}