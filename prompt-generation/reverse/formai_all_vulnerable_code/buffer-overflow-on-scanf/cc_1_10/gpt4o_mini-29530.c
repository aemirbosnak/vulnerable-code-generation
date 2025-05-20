//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float change;
} Stock;

typedef struct {
    Stock stocks[MAX_STOCKS];
    int count;
} StockPortfolio;

void addStock(StockPortfolio *portfolio, const char *name, float price, float change) {
    if (portfolio->count < MAX_STOCKS) {
        strncpy(portfolio->stocks[portfolio->count].name, name, MAX_NAME_LENGTH);
        portfolio->stocks[portfolio->count].price = price;
        portfolio->stocks[portfolio->count].change = change;
        portfolio->count++;
    } else {
        printf("Cannot add more stocks, portfolio is full.\n");
    }
}

void displayStocks(const StockPortfolio *portfolio) {
    printf("\nStock Portfolio:\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < portfolio->count; i++) {
        printf("%-20s | Price: $%.2f | Change: %.2f%%\n", 
               portfolio->stocks[i].name, 
               portfolio->stocks[i].price, 
               portfolio->stocks[i].change);
    }
    printf("-----------------------------------------\n");
}

void updateStockPrice(StockPortfolio *portfolio, const char *name, float newPrice) {
    for (int i = 0; i < portfolio->count; i++) {
        if (strcmp(portfolio->stocks[i].name, name) == 0) {
            float oldPrice = portfolio->stocks[i].price;
            portfolio->stocks[i].price = newPrice;
            portfolio->stocks[i].change = ((newPrice - oldPrice) / oldPrice) * 100;
            printf("Updated %s: New Price: $%.2f, Change: %.2f%%\n", 
                   name, newPrice, portfolio->stocks[i].change);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void savePortfolioToFile(const StockPortfolio *portfolio, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < portfolio->count; i++) {
        fprintf(file, "%s,%f,%f\n", 
                portfolio->stocks[i].name, 
                portfolio->stocks[i].price, 
                portfolio->stocks[i].change);
    }
    fclose(file);
    printf("Portfolio saved to %s\n", filename);
}

void loadPortfolioFromFile(StockPortfolio *portfolio, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    
    char line[100];
    while (fgets(line, sizeof(line), file) && portfolio->count < MAX_STOCKS) {
        char name[MAX_NAME_LENGTH];
        float price, change;
        sscanf(line, "%[^,],%f,%f", name, &price, &change);
        addStock(portfolio, name, price, change);
    }
    fclose(file);
    printf("Portfolio loaded from %s\n", filename);
}

void displayMenu() {
    printf("\nStock Market Tracker Menu:\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. Display All Stocks\n");
    printf("4. Save Portfolio\n");
    printf("5. Load Portfolio\n");
    printf("0. Exit\n");
}

int main() {
    StockPortfolio myPortfolio = { .count = 0 };
    int choice;
    
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                float price, change;
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                scanf("%f", &price);
                printf("Enter stock change (%%): ");
                scanf("%f", &change);
                addStock(&myPortfolio, name, price, change);
                break;
            }
            case 2: {
                char name[MAX_NAME_LENGTH];
                float newPrice;
                printf("Enter stock name to update: ");
                scanf("%s", name);
                printf("Enter new price: ");
                scanf("%f", &newPrice);
                updateStockPrice(&myPortfolio, name, newPrice);
                break;
            }
            case 3:
                displayStocks(&myPortfolio);
                break;
            case 4:
                savePortfolioToFile(&myPortfolio, "portfolio.txt");
                break;
            case 5:
                loadPortfolioFromFile(&myPortfolio, "portfolio.txt");
                break;
            case 0:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    return 0;
}