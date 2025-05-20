//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
} Stock;

void displayMenu() {
    printf("\n=============================\n");
    printf("    Stock Market Tracker     \n");
    printf("=============================\n");
    printf("1. Add a new stock\n");
    printf("2. Update stock price\n");
    printf("3. Display all stocks\n");
    printf("4. Exit\n");
    printf("=============================\n");
    printf("Choose an option: ");
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Cannot add more than %d stocks.\n", MAX_STOCKS);
        return;
    }

    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*count].price);
    (*count)++;
    printf("Stock added successfully!\n");
}

void updateStockPrice(Stock stocks[], int count) {
    char stockName[NAME_LENGTH];
    float newPrice;
    int found = 0;

    printf("Enter stock name to update: ");
    scanf("%s", stockName);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Current price of %s: %.2f\n", stocks[i].name, stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &newPrice);
            stocks[i].price = newPrice;
            found = 1;
            printf("Stock price updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Stock not found!\n");
    }
}

void displayStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks to display.\n");
        return;
    }

    printf("\n%-30s | %-10s\n", "Stock Name", "Current Price");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-30s | %.2f\n", stocks[i].name, stocks[i].price);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addStock(stocks, &count);
                break;
            case 2:
                updateStockPrice(stocks, count);
                break;
            case 3:
                displayStocks(stocks, count);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}