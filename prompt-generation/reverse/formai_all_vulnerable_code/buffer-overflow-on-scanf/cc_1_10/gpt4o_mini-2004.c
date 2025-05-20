//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int shares;
    float price;
} Stock;

typedef struct {
    Stock stocks[MAX_STOCKS];
    int count;
} Portfolio;

void initializePortfolio(Portfolio* portfolio) {
    portfolio->count = 0;
}

void addStock(Portfolio* portfolio, const char* name, int shares, float price) {
    if (portfolio->count >= MAX_STOCKS) {
        printf("Portfolio is full! Cannot add more stocks.\n");
        return;
    }
    strncpy(portfolio->stocks[portfolio->count].name, name, MAX_NAME_LENGTH);
    portfolio->stocks[portfolio->count].shares = shares;
    portfolio->stocks[portfolio->count].price = price;
    portfolio->count++;
    printf("Added %s: %d shares at $%.2f each.\n", name, shares, price);
}

void displayPortfolio(Portfolio* portfolio) {
    printf("\nYour Stock Portfolio:\n");
    for (int i = 0; i < portfolio->count; i++) {
        printf("%s: %d shares at $%.2f each\n",
               portfolio->stocks[i].name,
               portfolio->stocks[i].shares,
               portfolio->stocks[i].price);
    }
}

float calculateTotalValue(Portfolio* portfolio) {
    float totalValue = 0.0;
    for (int i = 0; i < portfolio->count; i++) {
        totalValue += portfolio->stocks[i].shares * portfolio->stocks[i].price;
    }
    return totalValue;
}

void updateStockPrice(Portfolio* portfolio, const char* name, float newPrice) {
    for (int i = 0; i < portfolio->count; i++) {
        if (strcmp(portfolio->stocks[i].name, name) == 0) {
            portfolio->stocks[i].price = newPrice;
            printf("Updated price for %s to $%.2f\n", name, newPrice);
            return;
        }
    }
    printf("Stock %s not found in portfolio.\n", name);
}

void displayTotalValue(Portfolio* portfolio) {
    float totalValue = calculateTotalValue(portfolio);
    printf("Total value of portfolio: $%.2f\n", totalValue);
}

int main() {
    Portfolio myPortfolio;
    initializePortfolio(&myPortfolio);

    int choice;
    char stockName[MAX_NAME_LENGTH];
    int shares;
    float price;

    do {
        printf("\n--- Stock Market Tracker ---\n");
        printf("1. Add Stock\n");
        printf("2. Display Portfolio\n");
        printf("3. Update Stock Price\n");
        printf("4. Show Total Value\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", stockName);
                printf("Enter number of shares: ");
                scanf("%d", &shares);
                printf("Enter price per share: ");
                scanf("%f", &price);
                addStock(&myPortfolio, stockName, shares, price);
                break;
            case 2:
                displayPortfolio(&myPortfolio);
                break;
            case 3:
                printf("Enter stock name to update: ");
                scanf("%s", stockName);
                printf("Enter new price: ");
                scanf("%f", &price);
                updateStockPrice(&myPortfolio, stockName, price);
                break;
            case 4:
                displayTotalValue(&myPortfolio);
                break;
            case 5:
                printf("Exiting the Stock Market Tracker. Happy trading!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}