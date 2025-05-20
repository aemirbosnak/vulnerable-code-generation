//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Stock;

void displayPortfolio(Stock portfolio[], int count);
void addStock(Stock portfolio[], int *count);
void updateStock(Stock portfolio[], int count);
void randomizePrices(Stock portfolio[], int count);
void sortStocks(Stock portfolio[], int count);
void displayMenu(void);

int main() {
    Stock portfolio[MAX_STOCKS];
    int count = 0;
    int choice;
    
    srand(time(NULL)); // Initialize random seed
    
    while(1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if(count < MAX_STOCKS) {
                    addStock(portfolio, &count);
                } else {
                    printf("Portfolio is full! Unable to add more stocks.\n");
                }
                break;
            case 2:
                updateStock(portfolio, count);
                break;
            case 3:
                randomizePrices(portfolio, count);
                break;
            case 4:
                sortStocks(portfolio, count);
                displayPortfolio(portfolio, count);
                break;
            case 5:
                displayPortfolio(portfolio, count);
                break;
            case 6:
                printf("Exiting the stock market tracker. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu(void) {
    printf("\n--- Stock Market Tracker Menu ---\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock\n");
    printf("3. Randomize Prices\n");
    printf("4. Sort Stocks\n");
    printf("5. Display Portfolio\n");
    printf("6. Exit\n");
}

void addStock(Stock portfolio[], int *count) {
    Stock newStock;
    
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    
    printf("Enter quantity: ");
    scanf("%d", &newStock.quantity);
    
    portfolio[*count] = newStock;
    (*count)++;
    printf("Stock added successfully!\n");
}

void updateStock(Stock portfolio[], int count) {
    char name[NAME_LENGTH];
    float newPrice;
    
    printf("Enter stock name to update: ");
    scanf("%s", name);
    
    for(int i = 0; i < count; i++) {
        if(strcmp(portfolio[i].name, name) == 0) {
            printf("Enter new price for %s: ", portfolio[i].name);
            scanf("%f", &newPrice);
            portfolio[i].price = newPrice;
            printf("Price updated successfully!\n");
            return;
        }
    }
    printf("Stock not found in the portfolio!\n");
}

void randomizePrices(Stock portfolio[], int count) {
    for(int i = 0; i < count; i++) {
        // Randomizing price between 10 and 500
        portfolio[i].price = 10 + (rand() % 491) + (rand() / (float)RAND_MAX);
    }
    printf("Prices randomized successfully!\n");
}

void sortStocks(Stock portfolio[], int count) {
    for(int i = 0; i < count - 1; i++) {
        for(int j = i + 1; j < count; j++) {
            if(portfolio[i].price > portfolio[j].price) {
                Stock temp = portfolio[i];
                portfolio[i] = portfolio[j];
                portfolio[j] = temp;
            }
        }
    }
    printf("Stocks sorted by price successfully!\n");
}

void displayPortfolio(Stock portfolio[], int count) {
    if (count == 0) {
        printf("Your portfolio is empty!\n");
        return;
    }
    
    printf("\n--- Your Stock Portfolio ---\n");
    for(int i = 0; i < count; i++) {
        printf("Stock: %s | Price: %.2f | Quantity: %d\n", 
                portfolio[i].name, 
                portfolio[i].price, 
                portfolio[i].quantity);
    }
}