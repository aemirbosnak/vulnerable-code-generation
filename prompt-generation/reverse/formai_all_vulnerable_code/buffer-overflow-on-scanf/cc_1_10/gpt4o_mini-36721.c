//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float price;
} Stock;

typedef struct {
    Stock stocks[MAX_STOCKS];
    int count;
} Portfolio;

void initializePortfolio(Portfolio *portfolio) {
    portfolio->count = 0;
}

void addStock(Portfolio *portfolio) {
    if (portfolio->count < MAX_STOCKS) {
        Stock newStock;
        printf("Enter stock name: ");
        scanf("%s", newStock.name);
        printf("Enter stock price: ");
        scanf("%f", &newStock.price);
        
        portfolio->stocks[portfolio->count++] = newStock;
        printf("Stock added successfully!\n");
    } else {
        printf("Portfolio is full! Cannot add more stocks.\n");
    }
}

void updateStock(Portfolio *portfolio) {
    char name[NAME_LENGTH];
    printf("Enter the stock name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < portfolio->count; i++) {
        if (strcmp(portfolio->stocks[i].name, name) == 0) {
            printf("Current price: %.2f\n", portfolio->stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &portfolio->stocks[i].price);
            printf("Stock updated successfully!\n");
            return;
        }
    }
    
    printf("Stock not found in the portfolio.\n");
}

void displayPortfolio(const Portfolio *portfolio) {
    if (portfolio->count == 0) {
        printf("No stocks in the portfolio.\n");
        return;
    }
    
    printf("\nYour Portfolio:\n");
    for (int i = 0; i < portfolio->count; i++) {
        printf("Stock: %s, Price: %.2f\n", portfolio->stocks[i].name, portfolio->stocks[i].price);
    }
}

void displayMenu() {
    printf("\nStock Market Tracker\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock\n");
    printf("3. Display Portfolio\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Portfolio myPortfolio;
    initializePortfolio(&myPortfolio);

    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(&myPortfolio);
                break;
            case 2:
                updateStock(&myPortfolio);
                break;
            case 3:
                displayPortfolio(&myPortfolio);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}