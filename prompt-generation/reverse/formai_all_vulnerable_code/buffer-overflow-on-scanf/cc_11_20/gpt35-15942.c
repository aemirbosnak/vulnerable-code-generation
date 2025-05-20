//FormAI DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 5    // Maximum number of stocks to track
#define MAX_NAME_LEN 20 // Maximum length of stock name

typedef struct stock_s {
  char name[MAX_NAME_LEN];
  double price;
  double change;
} stock;

int main(void) {
  stock stocks[MAX_STOCKS];
  int num_stocks = 0;

  while (1) {
    // Print menu options
    printf("\n\nStock Market Tracker - Main Menu\n");
    printf("---------------------------------\n");
    printf("1. Add a Stock\n");
    printf("2. Remove a Stock\n");
    printf("3. Update the Prices\n");
    printf("4. View Stocks\n");
    printf("5. Exit Program\n");
    printf("Enter an option: ");

    // Get user input
    int choice;
    scanf("%d", &choice);

    // Process user choice
    switch (choice) {
      case 1:
        // Add a stock
        if (num_stocks == MAX_STOCKS) {
          printf("\nYou have already added the maximum number of stocks.\n");
          break;
        }
        printf("\nEnter the name of the stock: ");
        scanf("%s", stocks[num_stocks].name);
        printf("Enter the current price of the stock: ");
        scanf("%lf", &stocks[num_stocks].price);
        printf("Enter the change of the stock: ");
        scanf("%lf", &stocks[num_stocks].change);
        num_stocks++;
        printf("\nThe stock has been added successfully.\n");
        break;
      case 2:
        // Remove a stock
        if (num_stocks == 0) {
          printf("\nYou haven't added any stocks yet.\n");
          break;
        }
        printf("\nEnter the name of the stock you want to remove: ");
        char stock_name[MAX_NAME_LEN];
        scanf("%s", stock_name);
        int i, stock_found = 0;
        for (i = 0; i < num_stocks; i++) {
          if (strcmp(stocks[i].name, stock_name) == 0) {
            stock_found = 1;
            break;
          }
        }
        if (stock_found) {
          memmove(stocks + i, stocks + i + 1, (num_stocks - i - 1) * sizeof(stock));
          num_stocks--;
          printf("\nThe stock has been removed successfully.\n");
        } else {
          printf("\nSorry, the stock '%s' is not found.\n", stock_name);
        }
        break;
      case 3:
        // Update prices
        if (num_stocks == 0) {
          printf("\nYou haven't added any stocks yet.\n");
          break;
        }
        printf("\nEnter the percentage change for each stock:\n");
        for (int i = 0; i < num_stocks; i++) {
          printf("%s: ", stocks[i].name);
          double percentage_change;
          scanf("%lf", &percentage_change);
          stocks[i].price = stocks[i].price * (1 + percentage_change / 100);
          stocks[i].change = percentage_change;
        }
        printf("\nThe prices have been updated successfully.\n");
        break;
      case 4:
        // View stocks
        if (num_stocks == 0) {
          printf("\nYou haven't added any stocks yet.\n");
          break;
        }
        printf("\n%-20s %-20s %-20s\n", "Name", "Current Price", "% Change");
        printf("-------------------------------------------------------\n");
        for (int i = 0; i < num_stocks; i++) {
          printf("%-20s %-20.2lf %-20.2lf\n", stocks[i].name, stocks[i].price, stocks[i].change);
        }
        break;
      case 5:
        // Exit program
        printf("\nThank you for using Stock Market Tracker!\n");
        exit(0);
      default:
        printf("\nInvalid option. Please choose again.\n");
        break;
    }
  }

  return 0;
}