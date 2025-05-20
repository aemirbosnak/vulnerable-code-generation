//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define TICKER_LENGTH 10
#define NAME_LENGTH 30

struct Stock {
    char ticker[TICKER_LENGTH];
    char name[NAME_LENGTH];
    float price;
    int shares;
};

void addStock(struct Stock portfolio[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Portfolio is full. Cannot add more stocks.\n");
        return;
    }
    
    printf("Enter ticker (max %d characters): ", TICKER_LENGTH - 1);
    scanf("%s", portfolio[*count].ticker);
    
    printf("Enter stock name (max %d characters): ", NAME_LENGTH - 1);
    scanf(" %[^\n]s", portfolio[*count].name);
    
    printf("Enter stock price: ");
    scanf("%f", &portfolio[*count].price);
    
    printf("Enter number of shares: ");
    scanf("%d", &portfolio[*count].shares);
    
    (*count)++;
    printf("Stock added successfully!\n");
}

void viewPortfolio(struct Stock portfolio[], int count) {
    if (count == 0) {
        printf("No stocks in portfolio.\n");
        return;
    }
    
    printf("\nYour Stock Portfolio:\n");
    printf("%-10s %-30s %-10s %-10s\n", "Ticker", "Name", "Price", "Shares");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-30s %-10.2f %-10d\n", 
               portfolio[i].ticker, 
               portfolio[i].name, 
               portfolio[i].price, 
               portfolio[i].shares);
    }
}

void calculateTotalValue(struct Stock portfolio[], int count) {
    float totalValue = 0;
    
    for (int i = 0; i < count; i++) {
        totalValue += portfolio[i].price * portfolio[i].shares;
    }
    
    printf("Total Portfolio Value: $%.2f\n", totalValue);
}

void savePortfolioToFile(struct Stock portfolio[], int count) {
    FILE *file = fopen("portfolio.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%.2f,%d\n", 
                portfolio[i].ticker, 
                portfolio[i].name, 
                portfolio[i].price, 
                portfolio[i].shares);
    }
    
    fclose(file);
    printf("Portfolio saved to 'portfolio.txt'\n");
}

void loadPortfolioFromFile(struct Stock portfolio[], int *count) {
    FILE *file = fopen("portfolio.txt", "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    
    while (fscanf(file, "%[^,],%[^,],%f,%d\n", 
                  portfolio[*count].ticker, 
                  portfolio[*count].name, 
                  &portfolio[*count].price, 
                  &portfolio[*count].shares) != EOF) {
        (*count)++;
        if (*count >= MAX_STOCKS) break;
    }
    
    fclose(file);
    printf("Portfolio loaded successfully!\n");
}

int main() {
    struct Stock portfolio[MAX_STOCKS];
    int count = 0;
    int choice;
    
    loadPortfolioFromFile(portfolio, &count);
    
    while (1) {
        printf("\nStock Market Tracker\n");
        printf("1. Add Stock\n");
        printf("2. View Portfolio\n");
        printf("3. Calculate Total Value\n");
        printf("4. Save Portfolio\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStock(portfolio, &count);
                break;
            case 2:
                viewPortfolio(portfolio, count);
                break;
            case 3:
                calculateTotalValue(portfolio, count);
                break;
            case 4:
                savePortfolioToFile(portfolio, count);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}