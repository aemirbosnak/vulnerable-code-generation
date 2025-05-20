//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float change;
} Stock;

typedef struct {
    Stock stocks[MAX_STOCKS];
    int count;
} StockMarket;

void initialize(StockMarket* market) {
    market->count = 0;
}

void addStock(StockMarket* market, const char* name, float price, float change) {
    if (market->count < MAX_STOCKS) {
        strcpy(market->stocks[market->count].name, name);
        market->stocks[market->count].price = price;
        market->stocks[market->count].change = change;
        market->count++;
    } else {
        printf("Cannot add more stocks, limit reached.\n");
    }
}

void displayStocks(const StockMarket* market) {
    if (market->count == 0) {
        printf("No stocks available.\n");
        return;
    }

    printf("\nStock Market Tracker:\n");
    printf("----------------------------------------------------\n");
    printf("| %-25s |   Price   |  Change   |\n", "Stock Name");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < market->count; i++) {
        printf("| %-25s | %8.2f | %8.2f |\n", market->stocks[i].name, market->stocks[i].price, market->stocks[i].change);
    }
    printf("----------------------------------------------------\n");
}

void updateStock(StockMarket* market, const char* name, float new_price, float new_change) {
    for (int i = 0; i < market->count; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            market->stocks[i].price = new_price;
            market->stocks[i].change = new_change;
            printf("Updated %s: New Price = %.2f, Change = %.2f\n", name, new_price, new_change);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void deleteStock(StockMarket* market, const char* name) {
    for (int i = 0; i < market->count; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            for (int j = i; j < market->count - 1; j++) {
                market->stocks[j] = market->stocks[j + 1];
            }
            market->count--;
            printf("Deleted stock %s successfully.\n", name);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void searchStock(const StockMarket* market, const char* name) {
    for (int i = 0; i < market->count; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            printf("Found stock %s: Price = %.2f, Change = %.2f\n", market->stocks[i].name, market->stocks[i].price, market->stocks[i].change);
            return;
        }
    }
    printf("Stock %s not found.\n", name);
}

void menu() {
    printf("\nStock Market Tracker Menu:\n");
    printf("1. Add Stock\n");
    printf("2. Display Stocks\n");
    printf("3. Update Stock\n");
    printf("4. Delete Stock\n");
    printf("5. Search Stock\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    StockMarket market;
    initialize(&market);

    int choice;
    char name[MAX_NAME_LENGTH];
    float price, change;

    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                scanf("%f", &price);
                printf("Enter stock change: ");
                scanf("%f", &change);
                addStock(&market, name, price, change);
                break;
            case 2:
                displayStocks(&market);
                break;
            case 3:
                printf("Enter stock name to update: ");
                scanf("%s", name);
                printf("Enter new price: ");
                scanf("%f", &price);
                printf("Enter new change: ");
                scanf("%f", &change);
                updateStock(&market, name, price, change);
                break;
            case 4:
                printf("Enter stock name to delete: ");
                scanf("%s", name);
                deleteStock(&market, name);
                break;
            case 5:
                printf("Enter stock name to search: ");
                scanf("%s", name);
                searchStock(&market, name);
                break;
            case 6:
                printf("Exiting the Stock Market Tracker.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}