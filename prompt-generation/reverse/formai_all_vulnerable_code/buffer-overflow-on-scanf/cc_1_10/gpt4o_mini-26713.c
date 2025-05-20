//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define STOCK_NAME_LENGTH 30

typedef struct {
    char name[STOCK_NAME_LENGTH];
    float price;
} Stock;

Stock stocks[MAX_STOCKS];
int stockCount = 0;

void addStock(char* name, float price) {
    if (stockCount < MAX_STOCKS) {
        strncpy(stocks[stockCount].name, name, STOCK_NAME_LENGTH);
        stocks[stockCount].price = price;
        stockCount++;
    } else {
        printf("Stock limit reached!\n");
    }
}

void displayStocks() {
    printf("Available Stocks:\n");
    printf("------------------\n");
    for (int i = 0; i < stockCount; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
    printf("------------------\n");
}

void updateStockPrice(char* name, float newPrice) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].price = newPrice;
            printf("Updated %s to $%.2f\n", name, newPrice);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void deleteStock(char* name) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            for (int j = i; j < stockCount - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            stockCount--;
            printf("Deleted stock %s\n", name);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void simulatePriceChange() {
    srand(time(NULL));
    for (int i = 0; i < stockCount; i++) {
        float change = ((rand() % 200 - 100) / 100.0); // Change by -1.00 to +1.00
        stocks[i].price += change;
        if (stocks[i].price < 0) stocks[i].price = 0; // Ensure price doesn't fall below 0
    }
}

int main() {
    int choice;
    char name[STOCK_NAME_LENGTH];
    float price;

    while (1) {
        printf("\nStock Market Tracker\n");
        printf("1. Add Stock\n");
        printf("2. Display Stocks\n");
        printf("3. Update Stock Price\n");
        printf("4. Delete Stock\n");
        printf("5. Simulate Price Change\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                if (scanf("%f", &price) != 1 || price < 0) {
                    printf("Invalid price entered. Please try again.\n");
                    while(getchar() != '\n'); // Clear input buffer
                    continue;
                }
                addStock(name, price);
                break;
            case 2:
                displayStocks();
                break;
            case 3:
                printf("Enter stock name to update: ");
                scanf("%s", name);
                printf("Enter new price: ");
                if (scanf("%f", &price) != 1 || price < 0) {
                    printf("Invalid price entered. Please try again.\n");
                    while(getchar() != '\n'); // Clear input buffer
                    continue;
                }
                updateStockPrice(name, price);
                break;
            case 4:
                printf("Enter stock name to delete: ");
                scanf("%s", name);
                deleteStock(name);
                break;
            case 5:
                simulatePriceChange();
                printf("Stock prices have been updated based on simulation.\n");
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}