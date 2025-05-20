//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
    double change_percentage;
} Stock;

void displayStock(Stock stock) {
    printf("Stock Name: %s\n", stock.name);
    printf("Current Price: $%.2f\n", stock.price);
    printf("Change Percentage: %.2f%%\n", stock.change_percentage);
    printf("---------------------------------\n");
}

void displayAllStocks(Stock stocks[], int count) {
    printf("Stock Market Tracker\n");
    printf("=====================\n");
    for (int i = 0; i < count; i++) {
        displayStock(stocks[i]);
    }
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock limit reached!\n");
        return;
    }
    
    Stock new_stock;

    printf("Enter stock name: ");
    scanf("%s", new_stock.name);

    printf("Enter current price: ");
    scanf("%lf", &new_stock.price);

    printf("Enter change percentage: ");
    scanf("%lf", &new_stock.change_percentage);

    stocks[*count] = new_stock;
    (*count)++;
    printf("Stock added successfully!\n");
}

void updateStock(Stock stocks[], int count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Updating stock: %s\n", name);

            printf("Enter new current price: ");
            scanf("%lf", &stocks[i].price);

            printf("Enter new change percentage: ");
            scanf("%lf", &stocks[i].change_percentage);

            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void deleteStock(Stock stocks[], int *count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter stock name to delete: ");
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

    do {
        printf("1. Add Stock\n");
        printf("2. Update Stock\n");
        printf("3. Delete Stock\n");
        printf("4. Display All Stocks\n");
        printf("5. Exit\n");
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
                deleteStock(stocks, &count);
                break;
            case 4:
                displayAllStocks(stocks, count);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}