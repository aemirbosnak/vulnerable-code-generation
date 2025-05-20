//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float change;
} Stock;

void displayWelcomeMessage() {
    printf("**************************************************************\n");
    printf("*                 Welcome to the Artistic Stock Tracker!     *\n");
    printf("**************************************************************\n");
}

void printStock(Stock stock) {
    printf("Stock Name: %s\n", stock.name);
    printf("Current Price: $%.2f\n", stock.price);
    printf("Price Change: %.2f%%\n", stock.change);
    printf("---------------------------------------------------------\n");
}

void addStock(Stock *stocks, int *stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Unable to add more stocks, limit reached!\n");
        return;
    }
    
    printf("Enter stock name: ");
    scanf("%s", stocks[*stockCount].name);
    printf("Enter current price: ");
    scanf("%f", &stocks[*stockCount].price);
    printf("Enter price change percentage: ");
    scanf("%f", &stocks[*stockCount].change);
    
    (*stockCount)++;
    printf("Stock added successfully!\n");
}

void updateStockPrice(Stock *stocks, int stockCount) {
    char name[MAX_NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Enter new price change percentage: ");
            scanf("%f", &stocks[i].change);
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void displayStocks(Stock *stocks, int stockCount) {
    if (stockCount == 0) {
        printf("No stocks to display!\n");
        return;
    }
    
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < stockCount; i++) {
        printStock(stocks[i]);
    }
    printf("---------------------------------------------------------\n");
}

void saveStocksToFile(Stock *stocks, int stockCount) {
    FILE *file = fopen("stocks.txt", "w");
    if (file == NULL) {
        printf("Error in opening file!\n");
        return;
    }
    
    for (int i = 0; i < stockCount; i++) {
        fprintf(file, "%s %.2f %.2f\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    
    fclose(file);
    printf("Stocks saved to file successfully!\n");
}

void loadStocksFromFile(Stock *stocks, int *stockCount) {
    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("No saved stocks found, starting fresh!\n");
        return;
    }
    
    while (fscanf(file, "%s %f %f", stocks[*stockCount].name, &stocks[*stockCount].price, &stocks[*stockCount].change) != EOF) {
        (*stockCount)++;
        if (*stockCount >= MAX_STOCKS) break;
    }
    
    fclose(file);
    printf("Stocks loaded from file successfully!\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;
    
    displayWelcomeMessage();
    loadStocksFromFile(stocks, &stockCount);
    
    do {
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. Display Stocks\n");
        printf("4. Save Stocks to File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
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
                saveStocksToFile(stocks, stockCount);
                break;
            case 5:
                printf("Exiting the tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again!\n");
        }
    } while (choice != 5);
    
    return 0;
}