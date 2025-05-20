//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
} Stock;

void displayStocks(Stock stocks[], int count) {
    printf("\nCurrent Stock Prices:\n");
    printf("----------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
    printf("----------------------\n");
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Cannot add more stocks. Maximum limit reached.\n");
        return;
    }
    
    Stock newStock;
    printf("Enter name of the stock: ");
    scanf("%s", newStock.name);
    printf("Enter price of the stock: ");
    scanf("%f", &newStock.price);
    
    stocks[*count] = newStock;
    (*count)++;
    printf("Stock added successfully.\n");
}

void updateStock(Stock stocks[], int count) {
    char stockName[NAME_LENGTH];
    printf("Enter the name of the stock to update: ");
    scanf("%s", stockName);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Current price of %s: $%.2f\n", stocks[i].name, stocks[i].price);
            printf("Enter the new price: ");
            scanf("%f", &stocks[i].price);
            printf("Stock updated successfully to $%.2f.\n", stocks[i].price);
            return;
        }
    }
    
    printf("Stock not found.\n");
}

void peacefulExit() {
    printf("Thank you for using the Stock Market Tracker. Have a peaceful day ahead.\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    char choice;
    
    printf("Welcome to the Stock Market Tracker.\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. View Stocks\n");
        printf("2. Add a Stock\n");
        printf("3. Update a Stock\n");
        printf("4. Exit\n");
        printf("Please select an option (1-4): ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                displayStocks(stocks, count);
                break;
            case '2':
                addStock(stocks, &count);
                break;
            case '3':
                updateStock(stocks, count);
                break;
            case '4':
                peacefulExit();
                return 0;
            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    }
    
    return 0;
}