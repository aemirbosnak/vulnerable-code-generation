//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float change;
} Stock;

void displayMenu();
void addStock(Stock stocks[], int *count);
void viewStocks(Stock stocks[], int count);
void updateStockPrice(Stock stocks[], int count);
void sortStocks(Stock stocks[], int count);
void generateRandomPrices(Stock stocks[], int count);

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
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
                sortStocks(stocks, stockCount);
                printf("Stocks sorted based on price.\n");
                break;
            case 5:
                generateRandomPrices(stocks, stockCount);
                printf("Random prices generated for the stocks.\n");
                break;
            case 0:
                printf("Exiting the stock market tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("=== Stock Market Tracker ===\n");
    printf("1. Add Stock\n");
    printf("2. View Stocks\n");
    printf("3. Update Stock Price\n");
    printf("4. Sort Stocks\n");
    printf("5. Generate Random Prices\n");
    printf("0. Exit\n");
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Cannot add more stocks. Limit reached.\n");
        return;
    }

    Stock newStock;
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    newStock.change = 0; // Assuming no initial change

    stocks[*count] = newStock;
    (*count)++;
    printf("Stock added successfully.\n");
}

void viewStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available.\n");
        return;
    }

    printf("=== List of Stocks ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Price: $%.2f, Change: %.2f%%\n", 
                i+1, stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

void updateStockPrice(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available to update.\n");
        return;
    }

    int index;
    printf("Enter stock number to update price (1 to %d): ", count);
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= count) {
        printf("Invalid stock number.\n");
        return;
    }

    float newPrice;
    printf("Enter new price for %s: ", stocks[index].name);
    scanf("%f", &newPrice);
    
    stocks[index].change = ((newPrice - stocks[index].price) / stocks[index].price) * 100;
    stocks[index].price = newPrice;
    printf("Price updated successfully for %s.\n", stocks[index].name);
}

void sortStocks(Stock stocks[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (stocks[j].price > stocks[j + 1].price) {
                Stock temp = stocks[j];
                stocks[j] = stocks[j + 1];
                stocks[j + 1] = temp;
            }
        }
    }
}

void generateRandomPrices(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available to generate prices.\n");
        return;
    }

    srand(time(0));
    for (int i = 0; i < count; i++) {
        stocks[i].price = (rand() % 10000) / 100.0; // Random price between 0.00 and 99.99
        stocks[i].change = ((float)(rand() % 2000 - 1000)) / 10.0; // Random change between -100.0% and +100.0%
    }
}