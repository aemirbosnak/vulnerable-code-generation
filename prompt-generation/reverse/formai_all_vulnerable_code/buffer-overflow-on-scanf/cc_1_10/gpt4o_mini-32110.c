//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Stock;

void displayMenu() {
    printf("\n--- Stock Market Tracker ---\n");
    printf("1. Add Stock\n");
    printf("2. Display Stocks\n");
    printf("3. Buy Stock\n");
    printf("4. Sell Stock\n");
    printf("5. Update Stock Price\n");
    printf("6. Exit\n");
    printf("----------------------------\n");
    printf("Choose an option: ");
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Max stock limit reached!\n");
        return;
    }

    Stock newStock;
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    newStock.quantity = 0;  // Initial quantity is 0

    stocks[*count] = newStock;
    (*count)++;
    printf("Stock added successfully!\n");
}

void displayStocks(Stock stocks[], int count) {
    printf("\n--- Available Stocks ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Price: $%.2f | Quantity: %d\n", i + 1, stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
}

void buyStock(Stock stocks[], int count) {
    int index, quantity;
    printf("Enter stock index to buy (1 to %d): ", count);
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("Invalid stock index!\n");
        return;
    }

    printf("Enter quantity to buy: ");
    scanf("%d", &quantity);
    stocks[index - 1].quantity += quantity;

    printf("Successfully bought %d shares of %s!\n", quantity, stocks[index - 1].name);
}

void sellStock(Stock stocks[], int count) {
    int index, quantity;
    printf("Enter stock index to sell (1 to %d): ", count);
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("Invalid stock index!\n");
        return;
    }

    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    if (quantity > stocks[index - 1].quantity) {
        printf("You don't have enough shares to sell!\n");
        return;
    }

    stocks[index - 1].quantity -= quantity;
    printf("Successfully sold %d shares of %s!\n", quantity, stocks[index - 1].name);
}

void updateStockPrice(Stock stocks[], int count) {
    int index;
    float newPrice;
    printf("Enter stock index to update price (1 to %d): ", count);
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("Invalid stock index!\n");
        return;
    }

    printf("Enter new price for %s: ", stocks[index - 1].name);
    scanf("%f", &newPrice);
    stocks[index - 1].price = newPrice;

    printf("Price for %s updated to $%.2f!\n", stocks[index - 1].name, newPrice);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &count);
                break;
            case 2:
                displayStocks(stocks, count);
                break;
            case 3:
                buyStock(stocks, count);
                break;
            case 4:
                sellStock(stocks, count);
                break;
            case 5:
                updateStockPrice(stocks, count);
                break;
            case 6:
                printf("Exiting the Stock Market Tracker. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}