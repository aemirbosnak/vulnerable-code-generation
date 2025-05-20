//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: introspective
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

Stock stockMarket[MAX_STOCKS];
int stockCount = 0;

void displayMenu() {
    printf("\n--- Stock Market Tracker ---\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. Display Stocks\n");
    printf("4. Calculate Portfolio Value\n");
    printf("5. Exit\n");
    printf("Select an option (1-5): ");
}

void addStock() {
    if (stockCount >= MAX_STOCKS) {
        printf("Unable to add stock. Stock market is full!\n");
        return;
    }
    
    Stock newStock;
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    printf("Enter quantity: ");
    scanf("%d", &newStock.quantity);
    
    stockMarket[stockCount++] = newStock;
    printf("Stock '%s' added successfully!\n", newStock.name);
}

void updateStockPrice() {
    char name[MAX_NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stockMarket[i].name, name) == 0) {
            printf("Current price of '%s': %.2f\n", stockMarket[i].name, stockMarket[i].price);
            printf("Enter new stock price: ");
            scanf("%f", &stockMarket[i].price);
            printf("Stock '%s' updated successfully!\n", stockMarket[i].name);
            return;
        }
    }
    printf("Stock '%s' not found!\n", name);
}

void displayStocks() {
    if (stockCount == 0) {
        printf("No stocks available in the market!\n");
        return;
    }
    
    printf("\n--- Stocks in Market ---\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Name: %s | Price: %.2f | Quantity: %d\n",
               stockMarket[i].name, stockMarket[i].price, stockMarket[i].quantity);
    }
}

void calculatePortfolioValue() {
    float totalValue = 0.0;
    
    for (int i = 0; i < stockCount; i++) {
        totalValue += stockMarket[i].price * stockMarket[i].quantity;
    }
    
    printf("Total portfolio value: %.2f\n", totalValue);
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addStock(); break;
            case 2: updateStockPrice(); break;
            case 3: displayStocks(); break;
            case 4: calculatePortfolioValue(); break;
            case 5: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice, please try again.\n"); break;
        }
    } while (choice != 5);

    return 0;
}