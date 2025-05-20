//FormAI DATASET v1.0 Category: Stock market tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Amazing Stock Market Tracker!\n\n");
    printf("Please enter the number of stocks you want to track: ");
    int num_stock;
    scanf("%d", &num_stock);

    char **stock_names = malloc(num_stock * sizeof(char *));
    for (int i = 0; i < num_stock; i++) {
        stock_names[i] = malloc(20 * sizeof(char));
        printf("\nEnter the name of stock %d: ", i + 1);
        scanf("%s", stock_names[i]);
    }

    int *prices = malloc(num_stock * sizeof(int));
    for (int i = 0; i < num_stock; i++) {
        prices[i] = rand() % 500;
    }

    printf("\n=============================\n");
    printf("CURRENT PRICES\n");
    printf("=============================\n");

    for (int i = 0; i < num_stock; i++) {
        printf("%s: $%d\n", stock_names[i], prices[i]);
    }

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Check stock prices\n");
        printf("2. Update stock prices\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n=============================\n");
                printf("CURRENT PRICES\n");
                printf("=============================\n");
                for (int i = 0; i < num_stock; i++) {
                    printf("%s: $%d\n", stock_names[i], prices[i]);
                }
                break;
            case 2:
                printf("\nEnter the name of the stock you want to update: ");
                char update_name[20];
                scanf("%s", update_name);
                for (int i = 0; i < num_stock; i++) {
                    if (strcmp(stock_names[i], update_name) == 0) {
                        printf("\nEnter the new price for %s: ", update_name);
                        scanf("%d", &prices[i]);
                        printf("\nPrice for %s has been updated to $%d\n", stock_names[i], prices[i]);
                    }
                }
                break;
            case 3:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 3);

    for (int i = 0; i < num_stock; i++) {
        free(stock_names[i]);
    }
    free(stock_names);
    free(prices);

    return 0;
}