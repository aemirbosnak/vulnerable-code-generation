//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define STOCK_NAME_LEN 30
#define DATA_FILE "stocks.txt"

typedef struct {
    char name[STOCK_NAME_LEN];
    float price;
} Stock;

int stockCount = 0;
Stock stocks[MAX_STOCKS];

// Function prototypes
void loadStocks();
void saveStocks();
void addStock(const char* name, float price);
void removeStock(const char* name);
void displayStocks();
void displayMenu();

int main() {
    loadStocks();
    
    int choice;
    char name[STOCK_NAME_LEN];
    float price;

    do {
        displayMenu();
        printf("Select an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                scanf("%f", &price);
                addStock(name, price);
                break;
            case 2:
                printf("Enter stock name to remove: ");
                scanf("%s", name);
                removeStock(name);
                break;
            case 3:
                displayStocks();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    saveStocks();
    return 0;
}

void displayMenu() {
    printf("\n=== Stock Market Tracker ===\n");
    printf("1. Add Stock\n");
    printf("2. Remove Stock\n");
    printf("3. Display Stocks\n");
    printf("4. Exit\n");
}

void loadStocks() {
    FILE *file = fopen(DATA_FILE, "r");
    if (file) {
        while (fscanf(file, "%s %f\n", stocks[stockCount].name, &stocks[stockCount].price) != EOF) {
            stockCount++;
        }
        fclose(file);
    }
}

void saveStocks() {
    FILE *file = fopen(DATA_FILE, "w");
    if (file) {
        for (int i = 0; i < stockCount; i++) {
            fprintf(file, "%s %.2f\n", stocks[i].name, stocks[i].price);
        }
        fclose(file);
    } else {
        printf("Error saving stocks!\n");
    }
}

void addStock(const char* name, float price) {
    if (stockCount < MAX_STOCKS) {
        strncpy(stocks[stockCount].name, name, STOCK_NAME_LEN);
        stocks[stockCount].price = price;
        stockCount++;
        printf("Stock added successfully!\n");
    } else {
        printf("Cannot add more stocks, limit reached.\n");
    }
}

void removeStock(const char* name) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            for (int j = i; j < stockCount - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            stockCount--;
            printf("Stock removed successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void displayStocks() {
    if (stockCount == 0) {
        printf("No stocks available.\n");
        return;
    }

    printf("\nStocks available:\n");
    printf("%-20s %s\n", "Stock Name", "Price");
    printf("-------------------------------\n");

    for (int i = 0; i < stockCount; i++) {
        printf("%-20s $%.2f\n", stocks[i].name, stocks[i].price);
    }
}