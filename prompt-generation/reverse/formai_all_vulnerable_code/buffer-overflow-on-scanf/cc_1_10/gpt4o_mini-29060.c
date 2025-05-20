//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int shares;
} Stock;

void displayMenu() {
    printf("======== Stock Market Tracker ========\n");
    printf("1. Add Stock\n");
    printf("2. Display Stocks\n");
    printf("3. Update Stock Price\n");
    printf("4. Delete Stock\n");
    printf("5. Exit\n");
    printf("======================================\n");
}

void addStock(Stock stocks[], int* count) {
    if (*count >= MAX_STOCKS) {
        printf("Cannot add more stocks, limit reached!\n");
        return;
    }
    printf("Enter Stock Name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter Stock Price: ");
    scanf("%f", &stocks[*count].price);
    printf("Enter Number of Shares: ");
    scanf("%d", &stocks[*count].shares);
    (*count)++;
    printf("Stock added successfully!\n");
}

void displayStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks to display!\n");
        return;
    }
    printf("\n======== Stocks in Portfolio ========\n");
    for (int i = 0; i < count; i++) {
        printf("Stock %d: %s | Price: $%.2f | Shares: %d\n",
                i + 1, stocks[i].name, stocks[i].price, stocks[i].shares);
    }
    printf("======================================\n");
}

void updateStockPrice(Stock stocks[], int count) {
    char name[MAX_NAME_LEN];
    float newPrice;
    printf("Enter Stock Name to Update: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Enter New Price: ");
            scanf("%f", &newPrice);
            stocks[i].price = newPrice;
            printf("Stock price updated successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void deleteStock(Stock stocks[], int* count) {
    char name[MAX_NAME_LEN];
    printf("Enter Stock Name to Delete: ");
    scanf("%s", name);
    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            (*count)--;
            printf("Stock deleted successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
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
                updateStockPrice(stocks, count);
                break;
            case 4:
                deleteStock(stocks, &count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        sleep(1);
    }

    return 0;
}