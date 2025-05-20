//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float change;
} Stock;

void displayMenu() {
    printf("\nWelcome to the Magical Stock Market Tracker!\n");
    printf("1. Add Stock\n");
    printf("2. View Stocks\n");
    printf("3. Update Stock Price\n");
    printf("4. Remove Stock\n");
    printf("5. Quit\n");
    printf("Choose an option: ");
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock list is full! Cannot add more stocks.\n");
        return;
    }

    Stock newStock;
    printf("Enter stock name (max %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    newStock.change = 0.0; // No change when added
    stocks[*count] = newStock;
    (*count)++;
    printf("Stock '%s' added successfully!\n", newStock.name);
}

void viewStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available. Please add stocks.\n");
        return;
    }

    printf("\nCurrent Stocks:\n");
    printf("%-20s%-15s%-15s\n", "Stock Name", "Price", "Change (%)");
    for (int i = 0; i < count; i++) {
        printf("%-20s%-15.2f%-15.2f\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

void updateStockPrice(Stock stocks[], int count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the stock to update: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            float newPrice;
            printf("Enter new price for %s: ", stocks[i].name);
            scanf("%f", &newPrice);
            stocks[i].change = ((newPrice - stocks[i].price) / stocks[i].price) * 100; // Calculate change
            stocks[i].price = newPrice; // Update price
            printf("Price of '%s' updated successfully!\n", stocks[i].name);
            return;
        }
    }
    printf("Stock '%s' not found in the list.\n", name);
}

void removeStock(Stock stocks[], int *count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the stock to remove: ");
    scanf("%s", name);

    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            // Shift remaining stocks to the left
            for (int j = i; j < *count - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            (*count)--;
            printf("Stock '%s' removed successfully!\n", name);
            return;
        }
    }
    printf("Stock '%s' not found in the list.\n", name);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                viewStocks(stocks, stockCount);
                break;
            case 3:
                updateStockPrice(stocks, stockCount);
                break;
            case 4:
                removeStock(stocks, &stockCount);
                break;
            case 5:
                printf("Thank you for using the Magical Stock Market Tracker! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }

        sleep(1); // Sleep for 1 second before repeating (optional)
    }

    return 0;
}