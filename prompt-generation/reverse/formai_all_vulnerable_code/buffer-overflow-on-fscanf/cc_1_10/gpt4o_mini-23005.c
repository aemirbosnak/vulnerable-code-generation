//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANY 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Stock;

void addStock(Stock stocks[], int *stockCount) {
    if (*stockCount >= MAX_COMPANY) {
        printf("Cannot add more stocks. Stock limit reached.\n");
        return;
    }
    
    Stock newStock;
    printf("Enter company name: ");
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    printf("Enter stock quantity: ");
    scanf("%d", &newStock.quantity);

    stocks[*stockCount] = newStock;
    (*stockCount)++;
    printf("Stock added successfully!\n");
}

void displayStocks(Stock stocks[], int stockCount) {
    printf("\n--- Current Stock Portfolio ---\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Company: %s | Price: %.2f | Quantity: %d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
}

void updateStockPrice(Stock stocks[], int stockCount) {
    char companyName[NAME_LENGTH];
    float newPrice;
    
    printf("Enter the company name to update price: ");
    scanf("%s", companyName);
    
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, companyName) == 0) {
            printf("Current price of %s: %.2f\n", companyName, stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &newPrice);
            stocks[i].price = newPrice;
            printf("Price updated successfully!\n");
            return;
        }
    }
    
    printf("Company not found in the portfolio.\n");
}

void saveToFile(Stock stocks[], int stockCount) {
    FILE *file = fopen("stocks.txt", "w");
    if (file == NULL) {
        printf("Error opening file to save stocks.\n");
        return;
    }
    
    for (int i = 0; i < stockCount; i++) {
        fprintf(file, "%s %.2f %d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
    
    fclose(file);
    printf("Stocks saved to file successfully!\n");
}

void loadFromFile(Stock stocks[], int *stockCount) {
    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("No saved stocks found.\n");
        return;
    }

    while (fscanf(file, "%s %f %d", stocks[*stockCount].name, &stocks[*stockCount].price, &stocks[*stockCount].quantity) != EOF) {
        (*stockCount)++;
    }

    fclose(file);
    printf("Stocks loaded from file successfully!\n");
}

int main() {
    Stock stocks[MAX_COMPANY];
    int stockCount = 0;
    int choice;

    loadFromFile(stocks, &stockCount);

    while (1) {
        printf("\n--- Stock Market Tracker ---\n");
        printf("1. Add Stock\n");
        printf("2. Display Stocks\n");
        printf("3. Update Stock Price\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                displayStocks(stocks, stockCount);
                break;
            case 3:
                updateStockPrice(stocks, stockCount);
                break;
            case 4:
                saveToFile(stocks, stockCount);
                break;
            case 5:
                loadFromFile(stocks, &stockCount);
                break;
            case 6:
                printf("Exiting the Stock Market Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}