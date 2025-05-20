//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

// Structure to hold stock information
typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Stock;

// Function prototypes
void displayMenu();
void addStock(Stock stocks[], int *count);
void updateStockPrice(Stock stocks[], int count);
void displayStocks(Stock stocks[], int count);
void simulateMarket(Stock stocks[], int count);

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                updateStockPrice(stocks, stockCount);
                break;
            case 3:
                displayStocks(stocks, stockCount);
                break;
            case 4:
                simulateMarket(stocks, stockCount);
                break;
            case 5:
                printf("Exiting the stock market tracker. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n***** Stock Market Tracker *****\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. Display All Stocks\n");
    printf("4. Simulate Market Activity\n");
    printf("5. Exit\n");
    printf("*********************************\n");
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Maximum stock limit reached! Cannot add more stocks.\n");
        return;
    }

    printf("Enter the stock name: ");
    scanf("%s", stocks[*count].name); // Safe usage since name length is limited
    printf("Enter the stock price: ");
    scanf("%f", &stocks[*count].price);

    (*count)++;
    printf("Stock %s added with price %.2f!\n", stocks[*count - 1].name, stocks[*count - 1].price);
}

void updateStockPrice(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available to update!\n");
        return;
    }

    char stockName[MAX_NAME_LENGTH];
    printf("Enter the stock name to update: ");
    scanf("%s", stockName);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Current price of %s: %.2f\n", stocks[i].name, stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Stock %s updated to price %.2f!\n", stocks[i].name, stocks[i].price);
            return;
        }
    }
    printf("Stock %s not found!\n", stockName);
}

void displayStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available to display!\n");
        return;
    }

    printf("\nCurrent stocks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", stocks[i].name, stocks[i].price);
    }
}

void simulateMarket(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available for simulation!\n");
        return;
    }

    srand(time(NULL));

    printf("Simulating market activity...\n");
    for (int i = 0; i < count; i++) {
        float percentChange = (rand() % 21 - 10) / 100.0; // -10% to +10%
        stocks[i].price += stocks[i].price * percentChange;
        printf("%s price updated to %.2f (change: %.2f%%)\n", stocks[i].name, 
               stocks[i].price, percentChange * 100);
    }
}