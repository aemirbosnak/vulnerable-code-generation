//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
/* The Adventure of the Stock Market Tracker */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 5
#define MAX_NAME_LENGTH 20

struct Stock {
    char name[MAX_NAME_LENGTH];
    float price;
};

struct StockPortfolio {
    struct Stock stocks[MAX_STOCKS];
    int numStocks;
};

// Helper function to convert string to lowercase
void toLowercase(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

// Print instructions for the program
void printInstructions() {
    printf("Welcome to the Stock Market Tracker!\n");
    printf("You can track a maximum of %d stocks.\n", MAX_STOCKS);
    printf("Commands:\n");
    printf("add stock\n");
    printf("remove stock\n");
    printf("display stocks\n");
    printf("update prices\n");
    printf("quit\n");
}

// Add a stock to the portfolio
void addStock(struct StockPortfolio* portfolio) {
    if (portfolio->numStocks == MAX_STOCKS) {
        printf("You have reached the maximum number of stocks.\n");
        return;
    }
    struct Stock* newStock = &portfolio->stocks[portfolio->numStocks];
    printf("Enter the name of the stock: ");
    scanf("%s", newStock->name);
    toLowercase(newStock->name);
    printf("Enter the price of the stock: ");
    scanf("%f", &newStock->price);
    printf("Added %s to your portfolio.\n", newStock->name);
    portfolio->numStocks++;
}

// Remove a stock from the portfolio
void removeStock(struct StockPortfolio* portfolio) {
    if (portfolio->numStocks == 0) {
        printf("You don't have any stocks to remove.\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the stock to remove: ");
    scanf("%s", name);
    toLowercase(name);
    for (int i = 0; i < portfolio->numStocks; i++) {
        if (strcmp(portfolio->stocks[i].name, name) == 0) {
            printf("Removed %s from your portfolio.\n", portfolio->stocks[i].name);
            portfolio->numStocks--;
            for (int j = i; j < portfolio->numStocks; j++) {
                portfolio->stocks[j] = portfolio->stocks[j+1];
            }
            return;
        }
    }
    printf("You don't have %s in your portfolio.\n", name);
}

// Display all stocks in the portfolio
void displayStocks(struct StockPortfolio* portfolio) {
    if (portfolio->numStocks == 0) {
        printf("You don't have any stocks to display.\n");
        return;
    }
    printf("Stocks in your portfolio:\n");
    for (int i = 0; i < portfolio->numStocks; i++) {
        printf("%s\t%f\n", portfolio->stocks[i].name, portfolio->stocks[i].price);
    }
}

// Update the prices of all stocks in the portfolio
void updatePrices(struct StockPortfolio* portfolio) {
    printf("Updating prices...\n");
    for (int i = 0; i < portfolio->numStocks; i++) {
        portfolio->stocks[i].price += (float)(rand() % 100 + 1) / 100;
    }
}

// Main function
int main() {
    struct StockPortfolio portfolio = {};
    char input[MAX_NAME_LENGTH];
    
    printInstructions();
    
    while (1) {
        printf("> ");
        scanf("%s", input);
        toLowercase(input);
        
        if (strcmp(input, "add") == 0) {
            addStock(&portfolio);
        }
        else if (strcmp(input, "remove") == 0) {
            removeStock(&portfolio);
        }
        else if (strcmp(input, "display") == 0) {
            displayStocks(&portfolio);
        }
        else if (strcmp(input, "update") == 0) {
            updatePrices(&portfolio);
        }
        else if (strcmp(input, "quit") == 0) {
            printf("Thanks for using the Stock Market Tracker!\n");
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }
    
    return 0;
}