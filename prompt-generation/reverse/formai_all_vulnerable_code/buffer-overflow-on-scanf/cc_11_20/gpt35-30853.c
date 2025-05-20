//FormAI DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 100

typedef struct Stock {
    char name[20];
    float value;
} Stock;

int main() {
    Stock stockList[MAX_STOCK];
    int numStocks = 0;

    printf("Welcome to the Stock Tracker!\n\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1) Add Stock\n");
        printf("2) View Stocks\n");
        printf("3) Update Stock\n");
        printf("4) Delete Stock\n");
        printf("5) Quit\n");

        int option;
        printf("\nEnter option number: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                printf("\nAdd Stock\n");

                // Check if maximum stocks are already added
                if (numStocks == MAX_STOCK) {
                    printf("Cannot add more stocks. Max limit reached.\n");
                    break;
                }

                // Get details for new stock and add to list
                Stock newStock;
                printf("Enter stock name: ");
                scanf("%s", newStock.name);
                printf("Enter stock value: ");
                scanf("%f", &newStock.value);
                printf("\n");

                stockList[numStocks++] = newStock;

                printf("Stock added successfully!\n\n");
                break;
            }
            case 2: {
                printf("\nView Stocks\n");

                if (numStocks == 0) {
                    printf("No stocks added yet.\n\n");
                    break;
                }

                // Print all stocks in list
                printf("Name \t\t Value\n");
                for (int i = 0; i < numStocks; i++) {
                    printf("%-15s $%.2f\n", stockList[i].name, stockList[i].value);
                }
                printf("\n");

                break;
            }
            case 3: {
                printf("\nUpdate Stock\n");

                if (numStocks == 0) {
                    printf("No stocks added yet.\n\n");
                    break;
                }

                // Get stock name to update and new value
                char stockName[20];
                printf("Enter stock name to update: ");
                scanf("%s", stockName);
                printf("Enter new value: ");
                float newValue;
                scanf("%f", &newValue);

                // Find stock in list and update value
                int found = 0;
                for (int i = 0; i < numStocks; i++) {
                    if (strcmp(stockList[i].name, stockName) == 0) {
                        stockList[i].value = newValue;
                        found = 1;
                    }
                }

                if (found)
                    printf("Stock updated successfully!\n\n");
                else
                    printf("Stock not found.\n\n");

                break;
            }
            case 4: {
                printf("\nDelete Stock\n");

                if (numStocks == 0) {
                    printf("No stocks added yet.\n\n");
                    break;
                }

                // Get stock name to delete
                char stockName[20];
                printf("Enter stock name to delete: ");
                scanf("%s", stockName);

                // Find stock in list and delete
                int found = 0;
                for (int i = 0; i < numStocks; i++) {
                    if (strcmp(stockList[i].name, stockName) == 0) {
                        found = 1;
                        for (int j = i; j < numStocks-1; j++) {
                            stockList[j] = stockList[j+1];
                        }
                        numStocks--;
                    }
                }

                if (found)
                    printf("Stock deleted successfully!\n\n");
                else
                    printf("Stock not found.\n\n");

                break;
            }
            case 5: {
                printf("\nThank you for using Stock Tracker!\n");
                exit(0);
            }
            default:
                printf("\nInvalid option. Please try again.\n\n");
        }
    }

    return 0;
}