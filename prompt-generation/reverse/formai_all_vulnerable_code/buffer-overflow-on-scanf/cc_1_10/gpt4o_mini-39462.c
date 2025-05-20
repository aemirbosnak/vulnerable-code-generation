//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define STOCK_NAME_LEN 30

typedef struct {
    char name[STOCK_NAME_LEN];
    float price;
    int shares;
} Stock;

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock limit reached! Cannot add more stocks.\n");
        return;
    }

    Stock newStock;
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    printf("Enter number of shares: ");
    scanf("%d", &newStock.shares);

    stocks[*count] = newStock;
    (*count)++;
    printf("Stock added successfully!\n");
}

void removeStock(Stock stocks[], int *count) {
    char name[STOCK_NAME_LEN];
    printf("Enter stock name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            (*count)--;
            printf("Stock removed successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void updateStock(Stock stocks[], int count) {
    char name[STOCK_NAME_LEN];
    printf("Enter stock name to update: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Current Price: %.2f\n", stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Successfully updated stock price!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void displayStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available!\n");
        return;
    }
    printf("\nList of Stocks:\n");
    printf("-----------------------\n");
    printf("%-20s %-10s %-10s\n", "Stock Name", "Price", "Shares");
    printf("-----------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-20s %-10.2f %-10d\n", stocks[i].name, stocks[i].price, stocks[i].shares);
    }
    printf("-----------------------\n");
}

void displayMenu() {
    printf("\nStock Market Tracker Menu:\n");
    printf("1. Add Stock\n");
    printf("2. Remove Stock\n");
    printf("3. Update Stock Price\n");
    printf("4. Display All Stocks\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
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
                removeStock(stocks, &count);
                break;
            case 3:
                updateStock(stocks, count);
                break;
            case 4:
                displayStocks(stocks, count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}