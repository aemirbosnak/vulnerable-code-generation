//FormAI DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>

#define MAX_STOCKS 10

struct stock {
    char name[20];
    double price;
    int quantity;
};

int main() {
    printf("Welcome to the Stock Market Tracker!\n\n");

    // Initializing stocks
    struct stock stocks[MAX_STOCKS] = {
        {"AAPL", 128.25, 10},
        {"GOOGL", 2457.30, 5},
        {"TSLA", 700.00, 15},
        {"AMZN", 3227.75, 8},
        {"MSFT", 232.51, 12},
        {"FB", 341.37, 7},
        {"NVDA", 556.37, 9},
        {"V", 194.87, 11},
        {"JPM", 156.01, 13},
        {"BABA", 238.06, 6}
    };

    // Displaying current stocks
    printf("Current stocks:\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("| %-6s | %-15s | %-15s | %-15s |\n", "Index", "Stock Name", "Stock Price", "Stock Quantity");
    printf("-----------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("| %-6d | %-15s | %-15.2f | %-15d |\n", i+1, stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
    printf("-----------------------------------------------------------------------------------------------------\n\n");

    // Taking user input
    int option, index;
    printf("Enter 1 to buy stocks or 2 to sell stocks: ");
    scanf("%d", &option);
    if (option == 1) {
        printf("Enter the index of the stock you want to buy: ");
        scanf("%d", &index);
        printf("Enter the quantity of stocks you want to buy: ");
        int quantity;
        scanf("%d", &quantity);
        if (stocks[index-1].quantity >= quantity) {
            stocks[index-1].quantity -= quantity;
            printf("Successfully bought %d stocks of %s!\n", quantity, stocks[index-1].name);
        } else {
            printf("Error: Insufficient stock quantity.\n");
        }
    } else if (option == 2) {
        printf("Enter the index of the stock you want to sell: ");
        scanf("%d", &index);
        printf("Enter the quantity of stocks you want to sell: ");
        int quantity;
        scanf("%d", &quantity);
        stocks[index-1].quantity += quantity;
        printf("Successfully sold %d stocks of %s!\n", quantity, stocks[index-1].name);
    } else {
        printf("Error: Invalid option.\n");
    }

    // Displaying updated stocks
    printf("Updated stocks:\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("| %-6s | %-15s | %-15s | %-15s |\n", "Index", "Stock Name", "Stock Price", "Stock Quantity");
    printf("-----------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("| %-6d | %-15s | %-15.2f | %-15d |\n", i+1, stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
    printf("-----------------------------------------------------------------------------------------------------\n");

    return 0;
}