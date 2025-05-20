//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LEN 50
#define TICKER_LEN 10

typedef struct {
    char name[NAME_LEN];
    char ticker[TICKER_LEN];
    float price;
    int quantity;
} Stock;

Stock stocks[MAX_STOCKS];
int stock_count = 0;

void loadStocks() {
    FILE *file = fopen("stocks.txt", "r");
    if (file) {
        while (fscanf(file, "%49s %9s %f %d", stocks[stock_count].name, stocks[stock_count].ticker, 
                      &stocks[stock_count].price, &stocks[stock_count].quantity) != EOF) {
            stock_count++;
        }
        fclose(file);
    }
}

void saveStocks() {
    FILE *file = fopen("stocks.txt", "w");
    for (int i = 0; i < stock_count; i++) {
        fprintf(file, "%s %s %.2f %d\n", stocks[i].name, stocks[i].ticker, 
                stocks[i].price, stocks[i].quantity);
    }
    fclose(file);
}

void displayStocks() {
    printf("\nStock List:\n");
    printf("------------------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Ticker", "Price", "Quantity");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < stock_count; i++) {
        printf("%-20s %-10s $%-9.2f %-10d\n", stocks[i].name, stocks[i].ticker, 
               stocks[i].price, stocks[i].quantity);
    }
}

void addStock() {
    if (stock_count >= MAX_STOCKS) {
        printf("Stock limit reached. Unable to add more stocks.\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stocks[stock_count].name);
    printf("Enter stock ticker: ");
    scanf("%s", stocks[stock_count].ticker);
    printf("Enter stock price: ");
    scanf("%f", &stocks[stock_count].price);
    printf("Enter stock quantity: ");
    scanf("%d", &stocks[stock_count].quantity);
    stock_count++;
    printf("Stock added successfully!\n");
}

void updateStock() {
    char ticker[TICKER_LEN];
    printf("Enter the ticker of the stock to update: ");
    scanf("%s", ticker);
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            printf("Updating stock: %s\n", stocks[i].name);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &stocks[i].quantity);
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Stock with ticker %s not found.\n", ticker);
}

void removeStock() {
    char ticker[TICKER_LEN];
    printf("Enter the ticker of the stock to remove: ");
    scanf("%s", ticker);
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            for (int j = i; j < stock_count - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            stock_count--;
            printf("Stock removed successfully!\n");
            return;
        }
    }
    printf("Stock with ticker %s not found.\n", ticker);
}

void menu() {
    int choice;
    while (1) {
        printf("\nStock Market Tracker Menu:\n");
        printf("1. Display Stocks\n");
        printf("2. Add Stock\n");
        printf("3. Update Stock\n");
        printf("4. Remove Stock\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStocks();
                break;
            case 2:
                addStock();
                saveStocks();
                break;
            case 3:
                updateStock();
                saveStocks();
                break;
            case 4:
                removeStock();
                saveStocks();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    loadStocks();
    menu();
    return 0;
}