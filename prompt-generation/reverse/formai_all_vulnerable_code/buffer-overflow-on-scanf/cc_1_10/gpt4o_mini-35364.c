//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define TICKER_LEN 6
#define NAME_LEN 30

typedef struct {
    char ticker[TICKER_LEN];
    char name[NAME_LEN];
    float price;
    float change;
} Stock;

Stock stockMarket[MAX_STOCKS];
int stockCount = 0;

void displayMenu() {
    printf("\n--- Retro Stock Market Tracker ---\n");
    printf("1. Add New Stock\n");
    printf("2. View All Stocks\n");
    printf("3. Update Stock Price\n");
    printf("4. Delete Stock\n");
    printf("5. Exit\n");
    printf("----------------------------------\n");
    printf("Select an option: ");
}

void addStock() {
    if(stockCount >= MAX_STOCKS) {
        printf("Market is full! Cannot add more stocks.\n");
        return;
    }
    Stock newStock;
    printf("Enter stock ticker: ");
    scanf("%s", newStock.ticker);
    printf("Enter company name: ");
    getchar(); // consume newline
    fgets(newStock.name, NAME_LEN, stdin);
    strtok(newStock.name, "\n"); // remove newline
    printf("Enter current price: ");
    scanf("%f", &newStock.price);
    newStock.change = 0.0; // No change initially

    stockMarket[stockCount] = newStock;
    stockCount++;
    printf("Stock added successfully!\n");
}

void viewStocks() {
    printf("\n--- Current Stocks in Market ---\n");
    for(int i = 0; i < stockCount; i++) {
        printf("%s (%s) - Price: %.2f, Change: %.2f%%\n", 
            stockMarket[i].name, stockMarket[i].ticker, 
            stockMarket[i].price, stockMarket[i].change);
    }
    printf("----------------------------------\n");
}

void updateStockPrice() {
    char ticker[TICKER_LEN];
    printf("Enter stock ticker to update: ");
    scanf("%s", ticker);
    
    for(int i = 0; i < stockCount; i++) {
        if(strcmp(stockMarket[i].ticker, ticker) == 0) {
            float newPrice;
            printf("Enter new price: ");
            scanf("%f", &newPrice);
            stockMarket[i].change = ((newPrice - stockMarket[i].price) / stockMarket[i].price) * 100;
            stockMarket[i].price = newPrice;
            printf("Stock price updated successfully!\n");
            return;
        }
    }
    printf("Stock with ticker %s not found!\n", ticker);
}

void deleteStock() {
    char ticker[TICKER_LEN];
    printf("Enter stock ticker to delete: ");
    scanf("%s", ticker);
    
    for(int i = 0; i < stockCount; i++) {
        if(strcmp(stockMarket[i].ticker, ticker) == 0) {
            for(int j = i; j < stockCount - 1; j++) {
                stockMarket[j] = stockMarket[j + 1]; // Shift left
            }
            stockCount--;
            printf("Stock deleted successfully!\n");
            return;
        }
    }
    printf("Stock with ticker %s not found!\n", ticker);
}

int main() {
    int choice;
    while(1) {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStock();
                break;
            case 2:
                viewStocks();
                break;
            case 3:
                updateStockPrice();
                break;
            case 4:
                deleteStock();
                break;
            case 5:
                printf("Exiting... Thank you for using Retro Stock Market Tracker!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}