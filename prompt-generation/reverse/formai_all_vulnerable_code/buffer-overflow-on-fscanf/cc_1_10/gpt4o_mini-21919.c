//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define TICKER_LENGTH 10
#define MAX_NAME_LENGTH 50
#define MAX_HISTORY 100

typedef struct {
    char ticker[TICKER_LENGTH];
    char name[MAX_NAME_LENGTH];
    float currentPrice;
    float priceHistory[MAX_HISTORY];
    int historyCount;
} Stock;

void addStock(Stock *stocks, int *stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Stock limit reached!\n");
        return;
    }

    Stock newStock;
    printf("Enter Ticker Symbol: ");
    scanf("%s", newStock.ticker);
    printf("Enter Company Name: ");
    scanf(" %[^\n]", newStock.name);
    printf("Enter Current Price: ");
    scanf("%f", &newStock.currentPrice);
    
    newStock.historyCount = 0; // Initialize history count
    newStock.priceHistory[newStock.historyCount++] = newStock.currentPrice; // Record initial price
    
    stocks[(*stockCount)++] = newStock; // Add new stock to the list
    printf("Stock %s added successfully!\n", newStock.ticker);
}

void updateStockPrice(Stock *stocks, int stockCount) {
    char ticker[TICKER_LENGTH];
    printf("Enter Ticker Symbol to update: ");
    scanf("%s", ticker);

    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            float newPrice;
            printf("Enter new price for %s: ", stocks[i].name);
            scanf("%f", &newPrice);
            stocks[i].currentPrice = newPrice;
            
            // Store price history
            if (stocks[i].historyCount < MAX_HISTORY) {
                stocks[i].priceHistory[stocks[i].historyCount++] = newPrice;
            }
            printf("Price for %s updated to %.2f\n", stocks[i].name, newPrice);
            return;
        }
    }
    printf("Stock %s not found!\n", ticker);
}

void displayStocks(Stock *stocks, int stockCount) {
    printf("\nStock Market Tracker\n");
    printf("---------------------\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Ticker: %s, Name: %s, Current Price: %.2f\n", stocks[i].ticker, stocks[i].name, stocks[i].currentPrice);
        printf("Price History: ");
        for (int j = 0; j < stocks[i].historyCount; j++) {
            printf("%.2f ", stocks[i].priceHistory[j]);
        }
        printf("\n---------------------\n");
    }
}

void saveToFile(Stock *stocks, int stockCount) {
    FILE *file = fopen("stocks.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < stockCount; i++) {
        fprintf(file, "%s %s %.2f\n", stocks[i].ticker, stocks[i].name, stocks[i].currentPrice);
        for (int j = 0; j < stocks[i].historyCount; j++) {
            fprintf(file, "%.2f ", stocks[i].priceHistory[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Stocks saved to stocks.txt\n");
}

void loadFromFile(Stock *stocks, int *stockCount) {
    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("No saved stocks found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%s %s %f", stocks[*stockCount].ticker, stocks[*stockCount].name, &stocks[*stockCount].currentPrice) != EOF) {
        stocks[*stockCount].historyCount = 0; // Reset history count
        float price;
        while (fscanf(file, "%f", &price) == 1) {
            if (stocks[*stockCount].historyCount < MAX_HISTORY) {
                stocks[*stockCount].priceHistory[stocks[*stockCount].historyCount++] = price;
            }
        }
        (*stockCount)++;
    }
    fclose(file);
    printf("Stocks loaded successfully. Total stocks: %d\n", *stockCount);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;

    loadFromFile(stocks, &stockCount);

    int choice;
    do {
        printf("\nStock Market Tracker Menu:\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. Display All Stocks\n");
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
                saveToFile(stocks, stockCount);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}