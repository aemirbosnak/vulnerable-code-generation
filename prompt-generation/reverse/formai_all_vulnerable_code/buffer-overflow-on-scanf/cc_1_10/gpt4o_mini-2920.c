//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
} Stock;

void displayMenu() {
    printf("\n*** Stock Market Tracker ***\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. View Portfolio\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Portfolio is full! Can't add more stocks.\n");
        return;
    }

    Stock newStock;
    printf("Enter the name of the stock: ");
    scanf("%s", newStock.name);
    printf("Enter the price of the stock: ");
    scanf("%f", &newStock.price);
    printf("Enter the quantity of stocks: ");
    scanf("%d", &newStock.quantity);

    stocks[*count] = newStock;
    (*count)++;
    printf("Added %s to your portfolio!\n", newStock.name);
}

void updateStockPrice(Stock stocks[], int count) {
    char stockName[MAX_NAME_LEN];
    float newPrice;

    printf("Enter the name of the stock to update: ");
    scanf("%s", stockName);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Enter the new price for %s: ", stockName);
            scanf("%f", &newPrice);
            stocks[i].price = newPrice;
            printf("Updated %s price to %.2f!\n", stockName, newPrice);
            return;
        }
    }
    printf("Stock %s not found in the portfolio!\n", stockName);
}

void viewPortfolio(const Stock stocks[], int count) {
    printf("\nYour Portfolio:\n");
    if (count == 0) {
        printf("The portfolio is empty!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        printf("Stock: %s | Price: %.2f | Quantity: %d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
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
                updateStockPrice(stocks, stockCount);
                break;
            case 3:
                viewPortfolio(stocks, stockCount);
                break;
            case 4:
                printf("Exiting the Stock Market Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    }

    return 0;
}