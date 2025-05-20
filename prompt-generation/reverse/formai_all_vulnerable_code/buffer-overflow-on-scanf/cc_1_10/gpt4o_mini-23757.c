//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define NAME_SIZE 30

typedef struct {
    char name[NAME_SIZE];
    float price;
    float change;
} Stock;

void displayMenu() {
    printf("\n====================\n");
    printf("    Stock Tracker    \n");
    printf("====================\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. Display Stocks\n");
    printf("4. Exit\n");
    printf("====================\n");
    printf("Select an option: ");
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Maximum stock limit reached!\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*count].price);
    stocks[*count].change = 0.0;
    (*count)++;
    printf("Stock '%s' added successfully!\n", stocks[*count - 1].name);
}

void updateStockPrice(Stock stocks[], int count) {
    char name[NAME_SIZE];
    printf("Enter stock name to update: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            float oldPrice = stocks[i].price;
            printf("Enter new stock price: ");
            scanf("%f", &stocks[i].price);
            stocks[i].change = stocks[i].price - oldPrice;
            printf("Stock '%s' updated successfully!\n", stocks[i].name);
            return;
        }
    }
    printf("Stock '%s' not found!\n", name);
}

void displayStocks(Stock stocks[], int count) {
    printf("\n====================\n");
    printf("      Stock List     \n");
    printf("====================\n");
    for (int i = 0; i < count; i++) {
        printf("Stock Name: %s\n", stocks[i].name);
        printf("Current Price: %.2f\n", stocks[i].price);
        printf("Price Change: %.2f\n", stocks[i].change);
        printf("--------------------\n");
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                updateStockPrice(stocks, stockCount);
                break;
            case 3:
                displayStocks(stocks, stockCount);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please select again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}