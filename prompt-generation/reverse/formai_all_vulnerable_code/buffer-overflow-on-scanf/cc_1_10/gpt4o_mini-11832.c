//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int shares;
} Stock;

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Maximum stock limit reached.\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*count].price);
    printf("Enter number of shares: ");
    scanf("%d", &stocks[*count].shares);
    (*count)++;
    printf("Stock added successfully.\n");
}

void displayStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks to display.\n");
        return;
    }
    printf("\nStocks in your portfolio:\n");
    printf("%-30s %-10s %-10s\n", "Stock Name", "Price", "Shares");
    for (int i = 0; i < count; i++) {
        printf("%-30s %-10.2f %-10d\n", stocks[i].name, stocks[i].price, stocks[i].shares);
    }
}

void updatePrice(Stock stocks[], int count) {
    char stockName[MAX_NAME_LENGTH];
    printf("Enter the stock name to update its price: ");
    scanf("%s", stockName);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Enter new price for %s: ", stocks[i].name);
            scanf("%f", &stocks[i].price);
            printf("Price updated successfully.\n");
            return;
        }
    }
    printf("Stock not found.\n");
}

void removeStock(Stock stocks[], int *count) {
    char stockName[MAX_NAME_LENGTH];
    printf("Enter the stock name to remove: ");
    scanf("%s", stockName);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            // Shift stocks down
            for (int j = i; j < *count - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            (*count)--;
            printf("Stock removed successfully.\n");
            return;
        }
    }
    printf("Stock not found.\n");
}

float calculateTotalValue(Stock stocks[], int count) {
    float totalValue = 0;
    for (int i = 0; i < count; i++) {
        totalValue += stocks[i].price * stocks[i].shares;
    }
    return totalValue;
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nStock Market Tracker Menu:\n");
        printf("1. Add Stock\n");
        printf("2. Display Stocks\n");
        printf("3. Update Stock Price\n");
        printf("4. Remove Stock\n");
        printf("5. Calculate Total Portfolio Value\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &count);
                break;
            case 2:
                displayStocks(stocks, count);
                break;
            case 3:
                updatePrice(stocks, count);
                break;
            case 4:
                removeStock(stocks, &count);
                break;
            case 5: {
                float totalValue = calculateTotalValue(stocks, count);
                printf("Total Portfolio Value: %.2f\n", totalValue);
                break;
            }
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}