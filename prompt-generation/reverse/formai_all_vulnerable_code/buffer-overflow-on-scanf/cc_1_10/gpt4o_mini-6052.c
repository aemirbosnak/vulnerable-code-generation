//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float priceHistory[10];
    int historyCount;
} Stock;

Stock stockList[MAX_STOCKS];
int stockCount = 0;

// Function declarations
void addStock(const char *name, float price);
void updateStockPrice(const char *name, float newPrice);
void displayStocks();
void displayStockHistory(const char *name);
void clearBuffer();

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    float price;

    while (1) {
        printf("\nStock Market Tracker\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. Display All Stocks\n");
        printf("4. Display Stock Price History\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter stock price: ");
                scanf("%f", &price);
                addStock(name, price);
                break;

            case 2:
                printf("Enter stock name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter new stock price: ");
                scanf("%f", &price);
                updateStockPrice(name, price);
                break;

            case 3:
                displayStocks();
                break;

            case 4:
                printf("Enter stock name to view history: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                displayStockHistory(name);
                break;
                
            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void addStock(const char *name, float price) {
    if (stockCount < MAX_STOCKS) {
        strcpy(stockList[stockCount].name, name);
        stockList[stockCount].price = price;
        stockList[stockCount].historyCount = 0;
        stockList[stockCount].priceHistory[stockList[stockCount].historyCount++] = price;
        stockCount++;
        printf("Stock %s added with current price $%.2f\n", name, price);
    } else {
        printf("Error: Stock limit reached!\n");
    }
}

void updateStockPrice(const char *name, float newPrice) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stockList[i].name, name) == 0) {
            if (stockList[i].historyCount < 10) {
                stockList[i].priceHistory[stockList[i].historyCount++] = stockList[i].price;
            } else {
                // Shift history
                for (int j = 1; j < 10; j++) {
                    stockList[i].priceHistory[j - 1] = stockList[i].priceHistory[j];
                }
                stockList[i].priceHistory[9] = stockList[i].price;
            }
            stockList[i].price = newPrice;
            printf("Updated stock %s to new price $%.2f\n", name, newPrice);
            return;
        }
    }
    printf("Error: Stock %s not found!\n", name);
}

void displayStocks() {
    printf("\nList of Stocks:\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Stock: %s, Current Price: $%.2f\n", stockList[i].name, stockList[i].price);
    }
}

void displayStockHistory(const char *name) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stockList[i].name, name) == 0) {
            printf("\nPrice History for %s:\n", name);
            for (int j = 0; j < stockList[i].historyCount; j++) {
                printf("$%.2f ", stockList[i].priceHistory[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("Error: Stock %s not found!\n", name);
}

void clearBuffer() {
    while (getchar() != '\n');  // Clear stdin buffer
}