//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    float price;
    float change;
    float volume;
} Stock;

void printMenu() {
    printf("\n---------------------\n");
    printf("    Stock Tracker    \n");
    printf("---------------------\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock\n");
    printf("3. View Stocks\n");
    printf("4. Exit\n");
    printf("---------------------\n");
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock limit reached! Cannot add more stocks.\n");
        return;
    }

    Stock newStock;
    printf("Enter stock name (max %d characters): ", NAME_LENGTH - 1);
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    printf("Enter price change: ");
    scanf("%f", &newStock.change);
    printf("Enter trading volume: ");
    scanf("%f", &newStock.volume);

    stocks[*count] = newStock;
    (*count)++;
    printf("Stock '%s' added successfully!\n", newStock.name);
}

void updateStock(Stock stocks[], int count) {
    char name[NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Updating stock '%s':\n", stocks[i].name);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Enter new price change: ");
            scanf("%f", &stocks[i].change);
            printf("Enter new trading volume: ");
            scanf("%f", &stocks[i].volume);
            printf("Stock '%s' updated successfully!\n", stocks[i].name);
            return;
        }
    }
    printf("Stock '%s' not found!\n", name);
}

void viewStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available to view. Please add some stocks!\n");
        return;
    }

    printf("\n%-20s %-10s %-10s %-10s\n", "Stock Name", "Price", "Change", "Volume");
    printf("--------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10.2f %-10.2f %-10.2f\n", stocks[i].name, stocks[i].price, stocks[i].change, stocks[i].volume);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    printf("Welcome to the Stock Market Tracker!\n");

    while (1) {
        printMenu();
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
                viewStocks(stocks, count);
                break;
            case 4:
                printf("Exiting the Stock Market Tracker. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}