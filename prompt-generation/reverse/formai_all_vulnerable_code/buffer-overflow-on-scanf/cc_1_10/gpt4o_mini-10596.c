//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
} Stock;

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock list is full!\n");
        return;
    }
    printf("Enter the stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter the stock price: ");
    scanf("%f", &stocks[*count].price);
    (*count)++;
}

void viewStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available!\n");
        return;
    }
    printf("\nList of Stocks:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, stocks[i].name, stocks[i].price);
    }
    printf("\n");
}

void updateStockPrice(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks to update!\n");
        return;
    }
    char name[NAME_LENGTH];
    printf("Enter the stock name to update: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Enter the new price for %s: ", stocks[i].name);
            scanf("%f", &stocks[i].price);
            printf("Price updated!\n");
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void deleteStock(Stock stocks[], int *count) {
    if (*count == 0) {
        printf("No stocks to delete!\n");
        return;
    }
    char name[NAME_LENGTH];
    printf("Enter the stock name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i] = stocks[*count - 1];
            (*count)--;
            printf("Stock %s deleted!\n", name);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void menu() {
    printf("Welcome to the Stock Market Tracker!\n");
    printf("1. Add Stock\n");
    printf("2. View Stocks\n");
    printf("3. Update Stock Price\n");
    printf("4. Delete Stock\n");
    printf("5. Exit\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                addStock(stocks, &count);
                break;
            case 2: 
                viewStocks(stocks, count);
                break;
            case 3: 
                updateStockPrice(stocks, count);
                break;
            case 4: 
                deleteStock(stocks, &count);
                break;
            case 5: 
                printf("Exiting...\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}