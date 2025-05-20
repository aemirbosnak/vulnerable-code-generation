//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    float price;
    int quantity;
} Stock;

Stock stocks[MAX_STOCKS];
int stockCount = 0;

void addStock(const char* name, float price, int quantity) {
    if (stockCount >= MAX_STOCKS) {
        printf("Stock list is full. Cannot add more stocks.\n");
        return;
    }
    strcpy(stocks[stockCount].name, name);
    stocks[stockCount].price = price;
    stocks[stockCount].quantity = quantity;
    stockCount++;
    printf("Stock %s added successfully.\n", name);
}

void viewStocks() {
    if (stockCount == 0) {
        printf("No stocks in the tracker.\n");
        return;
    }
    printf("Current Stock Portfolio:\n");
    printf("%-20s %-10s %-10s\n", "Stock Name", "Price", "Quantity");
    for (int i = 0; i < stockCount; i++) {
        printf("%-20s $%-9.2f %-10d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
}

void saveStocks(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    fwrite(&stockCount, sizeof(int), 1, file);
    fwrite(stocks, sizeof(Stock), stockCount, file);
    fclose(file);
    printf("Stocks saved successfully to %s.\n", filename);
}

void loadStocks(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file for reading.\n");
        return;
    }
    fread(&stockCount, sizeof(int), 1, file);
    fread(stocks, sizeof(Stock), stockCount, file);
    fclose(file);
    printf("Stocks loaded successfully from %s.\n", filename);
}

void updateStockPrice(const char* name, float newPrice) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].price = newPrice;
            printf("Updated %s to new price: $%.2f\n", name, newPrice);
            return;
        }
    }
    printf("Stock %s not found.\n", name);
}

void deleteStock(const char* name) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            for (int j = i; j < stockCount - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            stockCount--;
            printf("Stock %s deleted successfully.\n", name);
            return;
        }
    }
    printf("Stock %s not found.\n", name);
}

void displayMenu() {
    printf("\nStock Market Tracker\n");
    printf("1. Add Stock\n");
    printf("2. View Stocks\n");
    printf("3. Save Stocks\n");
    printf("4. Load Stocks\n");
    printf("5. Update Stock Price\n");
    printf("6. Delete Stock\n");
    printf("7. Exit\n");
}

int main() {
    int choice;
    char name[NAME_LEN];
    float price;
    int quantity;
    char filename[100];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                scanf("%f", &price);
                printf("Enter stock quantity: ");
                scanf("%d", &quantity);
                addStock(name, price, quantity);
                break;

            case 2:
                viewStocks();
                break;

            case 3:
                printf("Enter filename to save: ");
                scanf("%s", filename);
                saveStocks(filename);
                break;

            case 4:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                loadStocks(filename);
                break;

            case 5:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter new stock price: ");
                scanf("%f", &price);
                updateStockPrice(name, price);
                break;

            case 6:
                printf("Enter stock name to delete: ");
                scanf("%s", name);
                deleteStock(name);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}