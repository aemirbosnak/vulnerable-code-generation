//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold stock information
typedef struct {
    char name[50];
    char ticker[10];
    double price;
    double change;
} Stock;

// Function prototypes
void displayMenu();
void addStock(Stock *stocks, int *count);
void updateStockPrice(Stock *stocks, int count);
void displayStocks(Stock *stocks, int count);
void sortStocks(Stock *stocks, int count);
void generateRandomPrice(Stock *stock);

// Main function
int main() {
    Stock stocks[100];
    int stockCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                updateStockPrice(stocks, stockCount);
                break;
            case 3:
                sortStocks(stocks, stockCount);
                displayStocks(stocks, stockCount);
                break;
            case 4:
                displayStocks(stocks, stockCount);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nStock Market Tracker Menu:\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. Sort Stocks by Price\n");
    printf("4. Display Stocks\n");
    printf("5. Exit\n");
}

// Function to add a new stock
void addStock(Stock *stocks, int *count) {
    if (*count >= 100) {
        printf("Stock list is full!\n");
        return;
    }
    
    Stock newStock;
    printf("Enter stock name: ");
    getchar(); // Clear the newline character from the buffer
    fgets(newStock.name, sizeof(newStock.name), stdin);
    strtok(newStock.name, "\n"); // Remove the newline character from the string

    printf("Enter stock ticker: ");
    fgets(newStock.ticker, sizeof(newStock.ticker), stdin);
    strtok(newStock.ticker, "\n");

    newStock.price = rand() % 100 + 1; // Random price between 1 and 100
    newStock.change = ((rand() % 11) - 5) / 10.0; // Random change percentage

    stocks[*count] = newStock;
    (*count)++;
    printf("Stock %s (%s) added successfully!\n", newStock.name, newStock.ticker);
}

// Function to update stock prices
void updateStockPrice(Stock *stocks, int count) {
    if (count == 0) {
        printf("No stocks available to update.\n");
        return;
    }

    char ticker[10];
    printf("Enter stock ticker to update: ");
    getchar(); // Clear the newline character from the buffer
    fgets(ticker, sizeof(ticker), stdin);
    strtok(ticker, "\n");
    
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            generateRandomPrice(&stocks[i]);
            printf("Stock %s has been updated to $%.2f (Change: %.2f%%)\n", stocks[i].ticker, stocks[i].price, stocks[i].change);
            return;
        }
    }
    printf("Stock with ticker %s not found.\n", ticker);
}

// Function to generate a random price and change for a stock
void generateRandomPrice(Stock *stock) {
    stock->price += (rand() % 10 - 5); // Random price change between -5 and 5
    stock->change = ((rand() % 11) - 5) / 10.0; // Random change percentage
}

// Function to display all stocks
void displayStocks(Stock *stocks, int count) {
    if (count == 0) {
        printf("No stocks to display.\n");
        return;
    }

    printf("\nCurrent Stocks:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Ticker: %s, Price: $%.2f, Change: %.2f%%\n", stocks[i].name, stocks[i].ticker, stocks[i].price, stocks[i].change);
    }
}

// Function to sort stocks by price
void sortStocks(Stock *stocks, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (stocks[i].price > stocks[j].price) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
    printf("Stocks sorted by price.\n");
}