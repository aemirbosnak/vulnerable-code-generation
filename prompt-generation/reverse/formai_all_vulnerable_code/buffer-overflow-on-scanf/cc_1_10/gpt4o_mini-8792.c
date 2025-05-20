//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float change_percent;
    float volume;
} Stock;

void displayStocks(Stock stocks[], int count);
void addStock(Stock stocks[], int *count);
void updateStock(Stock stocks[], int count);
void removeStock(Stock stocks[], int *count);
void runStockTracker();

int main() {
    runStockTracker();
    return 0;
}

void runStockTracker() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Stock Market Tracker ===\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock\n");
        printf("3. Remove Stock\n");
        printf("4. Display Stocks\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &count);
                break;
            case 2:
                updateStock(stocks, count);
                break;
            case 3:
                removeStock(stocks, &count);
                break;
            case 4:
                displayStocks(stocks, count);
                break;
            case 0:
                printf("Exiting Stock Market Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock limit reached. Cannot add more stocks.\n");
        return;
    }

    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*count].price);
    printf("Enter price change percentage: ");
    scanf("%f", &stocks[*count].change_percent);
    printf("Enter volume: ");
    scanf("%f", &stocks[*count].volume);
    
    (*count)++;
    printf("Stock added successfully!\n");
}

void updateStock(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available to update.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Updating stock %s...\n", name);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Enter new change percentage: ");
            scanf("%f", &stocks[i].change_percent);
            printf("Enter new volume: ");
            scanf("%f", &stocks[i].volume);
            printf("Stock updated successfully!\n");
            return;
        }
    }

    printf("Stock %s not found!\n", name);
}

void removeStock(Stock stocks[], int *count) {
    if (*count == 0) {
        printf("No stocks available to remove.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter stock name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Removing stock %s...\n", name);
            for (int j = i; j < *count - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            (*count)--;
            printf("Stock removed successfully!\n");
            return;
        }
    }

    printf("Stock %s not found!\n", name);
}

void displayStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available.\n");
        return;
    }

    printf("\n--- Stock List ---\n");
    printf("%-20s %-10s %-15s %-10s\n", "Stock Name", "Price", "Change (%)", "Volume");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10.2f %-15.2f %-10.0f\n", stocks[i].name, stocks[i].price, stocks[i].change_percent, stocks[i].volume);
    }
}