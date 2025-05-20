//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define TICKER_SIZE 10
#define NAME_SIZE 50

typedef struct {
    char ticker[TICKER_SIZE];
    char name[NAME_SIZE];
    float price;
    float change;
    int volume;
} Stock;

void display_menu() {
    printf("Stock Market Tracker\n");
    printf("1. Add Stock\n");
    printf("2. View Stocks\n");
    printf("3. Update Stock Price\n");
    printf("4. View Stock Details\n");
    printf("5. Delete Stock\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

void add_stock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Cannot add more stocks. Maximum limit reached.\n");
        return;
    }
    
    Stock new_stock;
    printf("Enter Ticker Symbol: ");
    scanf("%s", new_stock.ticker);
    printf("Enter Company Name: ");
    scanf(" %[^\n]", new_stock.name);
    printf("Enter Current Price: ");
    scanf("%f", &new_stock.price);
    printf("Enter Price Change: ");
    scanf("%f", &new_stock.change);
    printf("Enter Trading Volume: ");
    scanf("%d", &new_stock.volume);
    
    stocks[*count] = new_stock;
    (*count)++;
    printf("Stock added successfully!\n");
}

void view_stocks(Stock stocks[], int count) {
    printf("\nList of Stocks:\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (%s) - $%.2f (Change: %.2f%%)\n",
                i + 1, stocks[i].name, stocks[i].ticker, stocks[i].price, stocks[i].change);
    }
    printf("--------------------------------------------------------\n");
}

void update_stock_price(Stock stocks[], int count) {
    char ticker[TICKER_SIZE];
    float new_price;
    
    printf("Enter Ticker Symbol to update: ");
    scanf("%s", ticker);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            printf("Current Price: $%.2f\n", stocks[i].price);
            printf("Enter New Price: ");
            scanf("%f", &new_price);
            stocks[i].price = new_price;
            printf("Stock price updated successfully!\n");
            return;
        }
    }
    printf("Stock with ticker '%s' not found.\n", ticker);
}

void view_stock_details(Stock stocks[], int count) {
    char ticker[TICKER_SIZE];
    
    printf("Enter Ticker Symbol to view details: ");
    scanf("%s", ticker);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            printf("\nStock Details:\n");
            printf("Ticker: %s\n", stocks[i].ticker);
            printf("Company Name: %s\n", stocks[i].name);
            printf("Current Price: $%.2f\n", stocks[i].price);
            printf("Price Change: %.2f%%\n", stocks[i].change);
            printf("Volume Traded: %d\n", stocks[i].volume);
            return;
        }
    }
    printf("Stock with ticker '%s' not found.\n", ticker);
}

void delete_stock(Stock stocks[], int *count) {
    char ticker[TICKER_SIZE];
    
    printf("Enter Ticker Symbol to delete: ");
    scanf("%s", ticker);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            for (int j = i; j < *count - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            (*count)--;
            printf("Stock deleted successfully!\n");
            return;
        }
    }
    printf("Stock with ticker '%s' not found.\n", ticker);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int option;
    
    while (1) {
        display_menu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_stock(stocks, &count);
                break;
            case 2:
                view_stocks(stocks, count);
                break;
            case 3:
                update_stock_price(stocks, count);
                break;
            case 4:
                view_stock_details(stocks, count);
                break;
            case 5:
                delete_stock(stocks, &count);
                break;
            case 6:
                printf("Exiting the Stock Market Tracker.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}