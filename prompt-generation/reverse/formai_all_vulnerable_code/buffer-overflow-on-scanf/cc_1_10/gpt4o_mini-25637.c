//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Stock;

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Cannot add more stocks. Stock limit reached.\n");
        return;
    }

    Stock newStock;

    printf("Enter the stock name: ");
    scanf("%s", newStock.name);
    printf("Enter the stock price: ");
    scanf("%f", &newStock.price);
    printf("Enter the stock quantity: ");
    scanf("%d", &newStock.quantity);

    stocks[*count] = newStock;
    (*count)++;
    printf("Stock added successfully.\n");
}

void viewStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks to display.\n");
        return;
    }

    printf("Current stocks:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s | Price: %.2f | Quantity: %d\n", i + 1, stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
}

void updateStock(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available to update.\n");
        return;
    }

    int index;
    printf("Enter the index of the stock to update (1 to %d): ", count);
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("Invalid index.\n");
        return;
    }

    int actualIndex = index - 1;
    printf("Updating stock: %s\n", stocks[actualIndex].name);
    printf("Enter new price (current: %.2f): ", stocks[actualIndex].price);
    scanf("%f", &stocks[actualIndex].price);
    printf("Enter new quantity (current: %d): ", stocks[actualIndex].quantity);
    scanf("%d", &stocks[actualIndex].quantity);
    printf("Stock updated successfully.\n");
}

void displayMenu() {
    printf("\n--- Stock Market Tracker ---\n");
    printf("1. Add Stock\n");
    printf("2. View Stocks\n");
    printf("3. Update Stock\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
    printf("Choose an option: ");
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
                updateStock(stocks, stockCount);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}