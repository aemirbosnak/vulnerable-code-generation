//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float change; // Change in percentage
} Stock;

void addStock(Stock stocks[], int *stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Stock limit reached. Cannot add more stocks.\n");
        return;
    }

    Stock newStock;
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    newStock.change = 0.0; // Initial change is 0
    stocks[*stockCount] = newStock;
    (*stockCount)++;
    printf("Stock added successfully.\n");
}

void updateStock(Stock stocks[], int stockCount) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the stock name to update: ");
    scanf("%s", name);

    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            float newPrice;
            printf("Enter new price for %s: ", stocks[i].name);
            scanf("%f", &newPrice);
            stocks[i].change = ((newPrice - stocks[i].price) / stocks[i].price) * 100;
            stocks[i].price = newPrice;
            printf("Stock updated successfully.\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void displayStocks(const Stock stocks[], int stockCount) {
    printf("\nStock Tracker\n");
    printf("-----------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Stock Name", "Price", "Change (%)");
    printf("-----------------------------\n");
    for (int i = 0; i < stockCount; i++) {
        printf("| %-20s | $%-9.2f | %+6.2f%% |\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    printf("-----------------------------\n");
}

void displayMenu() {
    printf("\nStock Market Tracker Menu\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock\n");
    printf("3. Display Stocks\n");
    printf("4. Exit\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                updateStock(stocks, stockCount);
                break;
            case 3:
                displayStocks(stocks, stockCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}