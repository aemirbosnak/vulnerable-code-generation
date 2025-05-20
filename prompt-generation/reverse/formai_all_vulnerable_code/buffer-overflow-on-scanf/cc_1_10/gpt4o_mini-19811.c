//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define STOCK_NAME_LENGTH 20
#define HISTORY_LENGTH 100

typedef struct {
    char name[STOCK_NAME_LENGTH];
    float currentPrice;
    float priceHistory[HISTORY_LENGTH];
    int historyCount;
} Stock;

Stock stockList[MAX_STOCKS];
int stockCount = 0;

// Function prototypes
void addStock();
void updatePrice();
void displayStocks();
void showHistory();
void loadStocks();
void saveStocks();

int main() {
    int choice;
    loadStocks();

    do {
        printf("\nStock Market Tracker\n");
        printf("1. Add New Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. Display All Stocks\n");
        printf("4. Show Price History\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                updatePrice();
                break;
            case 3:
                displayStocks();
                break;
            case 4:
                showHistory();
                break;
            case 5:
                saveStocks();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addStock() {
    if (stockCount >= MAX_STOCKS) {
        printf("Stock limit reached. Cannot add more stocks.\n");
        return;
    }

    Stock newStock;
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter current price: ");
    scanf("%f", &newStock.currentPrice);
    newStock.historyCount = 0;
    newStock.priceHistory[newStock.historyCount++] = newStock.currentPrice;

    stockList[stockCount++] = newStock;
    printf("Stock %s added successfully.\n", newStock.name);
}

void updatePrice() {
    char name[STOCK_NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);

    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stockList[i].name, name) == 0) {
            float newPrice;
            printf("Enter new price for %s: ", stockList[i].name);
            scanf("%f", &newPrice);
            stockList[i].currentPrice = newPrice;
            stockList[i].priceHistory[stockList[i].historyCount++] = newPrice;
            printf("Price updated successfully for %s.\n", stockList[i].name);
            return;
        }
    }

    printf("Stock %s not found.\n", name);
}

void displayStocks() {
    printf("\nAll Stocks:\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Stock Name: %s, Current Price: %.2f\n", stockList[i].name, stockList[i].currentPrice);
    }
}

void showHistory() {
    char name[STOCK_NAME_LENGTH];
    printf("Enter stock name to view history: ");
    scanf("%s", name);

    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stockList[i].name, name) == 0) {
            printf("Price history for %s:\n", stockList[i].name);
            for (int j = 0; j < stockList[i].historyCount; j++) {
                printf("%.2f\n", stockList[i].priceHistory[j]);
            }
            return;
        }
    }

    printf("Stock %s not found.\n", name);
}

void loadStocks() {
    FILE *file = fopen("stocks.dat", "rb");
    if (!file) {
        return; // No file to load, continue with an empty list.
    }
    fread(&stockCount, sizeof(int), 1, file);
    fread(stockList, sizeof(Stock), stockCount, file);
    fclose(file);
}

void saveStocks() {
    FILE *file = fopen("stocks.dat", "wb");
    if (!file) {
        printf("Error saving stocks!\n");
        return;
    }
    fwrite(&stockCount, sizeof(int), 1, file);
    fwrite(stockList, sizeof(Stock), stockCount, file);
    fclose(file);
}