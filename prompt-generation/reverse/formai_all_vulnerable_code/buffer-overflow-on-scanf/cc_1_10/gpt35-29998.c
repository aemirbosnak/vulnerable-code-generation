//FormAI DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOL 10 // Maximum length of Stock Symbol
#define MAX_STOCKS 100 // Maximum number of different stocks that can be tracked
#define MAX_NAME 50 // Maximum length of Stock name
#define MAX_DATE 20 // Maximum length of Date

typedef struct Stock {
    char symbol[MAX_SYMBOL];
    char name[MAX_NAME];
    float price;
    char date[MAX_DATE];
} Stock;

int numStocks = 0;
Stock stocks[MAX_STOCKS];

void addStock()
{
    if (numStocks >= MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }

    Stock newStock;
    printf("Enter the Stock Symbol: ");
    scanf("%s", newStock.symbol);
    
    // Check if the stock already exists
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].symbol, newStock.symbol) == 0) {
            printf("The stock already exists.\n");
            return;
        }
    }

    printf("Enter the Stock Name: ");
    scanf("%s", newStock.name);

    printf("Enter the current Stock Price: ");
    scanf("%f", &newStock.price);

    printf("Enter the Date of the Stock Price (mm/dd/yyyy): ");
    scanf("%s", newStock.date);

    stocks[numStocks++] = newStock;

    printf("Stock added successfully!\n");
}

int findStock(char symbol[])
{
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            return i;
        }
    }

    return -1;
}

void viewAllStocks()
{
    printf("Stock Symbol\tStock Name\tCurrent Price\tDate\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%s\t\t%s\t\t%.2f\t\t%s\n", stocks[i].symbol, stocks[i].name, stocks[i].price, stocks[i].date);
    }
}

void viewStock(char symbol[])
{
    int index = findStock(symbol);
    if (index == -1) {
        printf("The stock does not exist.\n");
        return;
    }

    printf("Stock Name: %s\n", stocks[index].name);
    printf("Current Price: %.2f\n", stocks[index].price);
    printf("Date of Stock Price: %s\n", stocks[index].date);
}

void updateStock(char symbol[])
{
    int index = findStock(symbol);
    if (index == -1) {
        printf("The stock does not exist.\n");
        return;
    }

    printf("Enter the new Stock Name (press enter to leave unchanged): ");
    char newName[MAX_NAME];
    getchar(); // Removing newline character from input buffer
    fgets(newName, MAX_NAME, stdin);
    if (strlen(newName) > 1) {
        strncpy(stocks[index].name, newName, strlen(newName)-1);
    }

    printf("Enter the new Stock Price (press enter to leave unchanged): ");
    char newPrice[10];
    fgets(newPrice, 10, stdin);
    if (strlen(newPrice) > 1) {
        stocks[index].price = atof(newPrice);
    }

    printf("Enter the new Date of the Stock Price (mm/dd/yyyy) (press enter to leave unchanged): ");
    char newDate[MAX_DATE];
    fgets(newDate, MAX_DATE, stdin);
    if (strlen(newDate) > 1) {
        strncpy(stocks[index].date, newDate, strlen(newDate)-1);
    }

    printf("Stock updated successfully!\n");
}

void deleteStock(char symbol[]) {
    int index = findStock(symbol);
    if (index == -1) {
        printf("The stock does not exist.\n");
        return;
    }

    for (int i = index; i < numStocks-1; i++) {
        stocks[i] = stocks[i+1];
    }
    numStocks--;

    printf("Stock deleted successfully!\n");
}

int main()
{
    char choice;
    char symbol[MAX_SYMBOL];
    
    while (1) {
        printf("\n");
        printf("Stock Market Tracker\n");
        printf("=========================\n");
        printf("A: Add a new stock\n");
        printf("V: View all stocks\n");
        printf("S: View a specific stock\n");
        printf("U: Update a stock\n");
        printf("D: Delete a stock\n");
        printf("Q: Quit the program\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice); // Extra space before %c to consume newline character

        switch (choice) {
            case 'A':
            case 'a':
                addStock();
                break;
            case 'V':
            case 'v':
                viewAllStocks();
                break;
            case 'S':
            case 's':
                printf("Enter the stock symbol: ");
                scanf("%s", symbol);
                viewStock(symbol);
                break;
            case 'U':
            case 'u':
                printf("Enter the stock symbol: ");
                scanf("%s", symbol);
                updateStock(symbol);
                break;
            case 'D':
            case 'd':
                printf("Enter the stock symbol: ");
                scanf("%s", symbol);
                deleteStock(symbol);
                break;
            case 'Q':
            case 'q':
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please enter a valid option.\n");
                break;
        }
    }

    return 0;
}