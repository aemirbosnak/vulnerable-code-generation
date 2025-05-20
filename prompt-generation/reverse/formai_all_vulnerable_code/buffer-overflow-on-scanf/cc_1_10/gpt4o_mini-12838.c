//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float price;
    float change;
} Stock;

void addStock(Stock *stocks, int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock list is full!\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*count].price);
    stocks[*count].change = 0.0f; // Initialize change to 0
    (*count)++;
    printf("Stock added successfully!\n");
}

void updateStock(Stock *stocks, int count) {
    char name[NAME_LENGTH];
    printf("Enter the stock name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Enter new stock price: ");
            float newPrice;
            scanf("%f", &newPrice);
            stocks[i].change = newPrice - stocks[i].price;
            stocks[i].price = newPrice;
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void displayStocks(Stock *stocks, int count) {
    printf("\n--- Stock List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Price: %.2f", stocks[i].name, stocks[i].price);
        if (stocks[i].change > 0) {
            printf(", Change: +%.2f\n", stocks[i].change);
        } else if (stocks[i].change < 0) {
            printf(", Change: %.2f\n", stocks[i].change);
        } else {
            printf(", Change: 0.00\n");
        }
    }
    printf("-------------------\n");
}

float calculateTotalInvestment(Stock *stocks, int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += stocks[i].price;
    }
    return total;
}

void sortStocksByPrice(Stock *stocks, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (stocks[j].price > stocks[j + 1].price) {
                Stock temp = stocks[j];
                stocks[j] = stocks[j + 1];
                stocks[j + 1] = temp;
            }
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    do {
        printf("\n=== Stock Market Tracker ===\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock\n");
        printf("3. Display Stocks\n");
        printf("4. Calculate Total Investment\n");
        printf("5. Sort Stocks by Price\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &count);
                break;
            case 2:
                updateStock(stocks, count);
                break;
            case 3:
                displayStocks(stocks, count);
                break;
            case 4:
                {
                    float total = calculateTotalInvestment(stocks, count);
                    printf("Total Investment: %.2f\n", total);
                }
                break;
            case 5:
                sortStocksByPrice(stocks, count);
                printf("Stocks sorted by price!\n");
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}