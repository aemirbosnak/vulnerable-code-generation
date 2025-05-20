//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: Alan Turing
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
void updateStock(Stock stocks[], int count);
void displayStocks(Stock stocks[], int count);
void sortStocks(Stock stocks[], int count);
void generateRandomStockData(Stock *stock);
void clearBuffer();

int main() {
    Stock stocks[MAX_STOCKS];
    int choice;
    int stockCount = 0;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                updateStock(stocks, stockCount);
                break;
            case 3:
                displayStocks(stocks, stockCount);
                break;
            case 4:
                sortStocks(stocks, stockCount);
                printf("Stocks sorted by price.\n");
                break;
            case 5:
                printf("Exiting the stock market tracker.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n=== Stock Market Tracker ===\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Prices\n");
    printf("3. Display All Stocks\n");
    printf("4. Sort Stocks by Price\n");
    printf("5. Exit\n");
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock list is full! Cannot add more stocks.\n");
        return;
    }
    Stock newStock;
    printf("Enter stock name: ");
    fgets(newStock.name, MAX_NAME_LENGTH, stdin);
    strtok(newStock.name, "\n"); // Remove trailing newline

    generateRandomStockData(&newStock);
    stocks[*count] = newStock;
    (*count)++;
    printf("Stock added: %s, Price: %.2f, Change: %.2f%%\n", newStock.name, newStock.price, newStock.change);
}

void generateRandomStockData(Stock *stock) {
    stock->price = (rand() % 10000) / 100.0; // price between [0.00, 100.00]
    stock->change = ((rand() % 2000) / 100.0) - 10.0; // change between [-10.00, 10.00]
}

void updateStock(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks to update.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        stocks[i].price += ((rand() % 2000) / 100.0) - 10.0; // Random fluctuation
        stocks[i].change = ((stocks[i].price - stocks[i].price + ((rand() % 2000) / 100.0) - 10.0) / stocks[i].price) * 100; // Change percentage
    }
    printf("All stocks updated with new prices.\n");
}

void displayStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks to display.\n");
        return;
    }

    printf("\n=== Current Stock Prices ===\n");
    for (int i = 0; i < count; i++) {
        printf("%s: $%.2f (%+.2f%%)\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

void sortStocks(Stock stocks[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (stocks[j].price > stocks[j + 1].price) {
                Stock temp = stocks[j];
                stocks[j] = stocks[j + 1];
                stocks[j + 1] = temp;
            }
        }
    }
}

void clearBuffer() {
    while (getchar() != '\n');
}