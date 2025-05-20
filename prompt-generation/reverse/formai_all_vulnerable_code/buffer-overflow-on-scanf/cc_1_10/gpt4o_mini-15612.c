//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Stock;

Stock market[MAX_STOCKS];
int stockCount = 0;

void addStock();
void updateStock();
void displayStocks();
void menu();

int main() {
    printf("Welcome to the Energetic Stock Market Tracker!\n");
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n********** Main Menu **********\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. Display Stocks\n");
        printf("4. Exit\n");
        printf("********************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                updateStock();
                break;
            case 3:
                displayStocks();
                break;
            case 4:
                printf("Exiting... Happy Trading!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}

void addStock() {
    if (stockCount >= MAX_STOCKS) {
        printf("Market is full! Can't add more stocks.\n");
        return;
    }
    
    Stock s;
    printf("Enter the stock name: ");
    scanf("%s", s.name);
    printf("Enter the stock price: ");
    scanf("%f", &s.price);
    printf("Enter the quantity: ");
    scanf("%d", &s.quantity);

    market[stockCount] = s;
    stockCount++;

    printf("Stock %s added successfully!\n", s.name);
}

void updateStock() {
    char name[NAME_LENGTH];
    printf("Enter the stock name to update: ");
    scanf("%s", name);

    for (int i = 0; i < stockCount; i++) {
        if (strcmp(market[i].name, name) == 0) {
            printf("Current price of %s: $%.2f\n", market[i].name, market[i].price);
            printf("Enter new stock price: ");
            scanf("%f", &market[i].price);
            printf("Stock %s updated successfully!\n", market[i].name);
            return;
        }
    }

    printf("Stock %s not found in the market!\n", name);
}

void displayStocks() {
    if (stockCount == 0) {
        printf("No stocks to display! Please add some stocks.\n");
        return;
    }

    printf("\n--- Current Stock Market Status ---\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Stock Name: %s | Price: $%.2f | Quantity: %d\n", 
                market[i].name, market[i].price, market[i].quantity);
    }
    printf("-----------------------------------\n");
}