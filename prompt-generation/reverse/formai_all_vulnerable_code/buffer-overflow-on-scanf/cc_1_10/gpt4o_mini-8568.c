//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Stock;

void addStock(Stock stocks[], int *count);
void updateStock(Stock stocks[], int count);
void displayStocks(Stock stocks[], int count);
void displayMenu();

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStock(stocks, &count);
                break;
            case 2:
                updateStock(stocks, count);
                break;
            case 3:
                displayStocks(stocks, count);
                break;
            case 4:
                printf("Exiting the program. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n--- Stock Market Tracker ---\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. Display Stocks\n");
    printf("4. Exit\n");
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Error: Stock limit reached. Cannot add more stocks.\n");
        return;
    }

    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*count].price);
    (*count)++;
    printf("Stock added successfully!\n");
}

void updateStock(Stock stocks[], int count) {
    char name[MAX_NAME_LENGTH];
    float newPrice;
    int found = 0;

    printf("Enter the stock name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            found = 1;
            printf("Current price of %s is $%.2f. Enter new price: ", stocks[i].name, stocks[i].price);
            scanf("%f", &newPrice);
            stocks[i].price = newPrice;
            printf("Price updated to $%.2f for %s.\n", newPrice, stocks[i].name);
            break;
        }
    }
    
    if (!found) {
        printf("Error: Stock not found.\n");
    }
}

void displayStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available to display.\n");
        return;
    }

    printf("\n--- Stock List ---\n");
    printf("%-30s %s\n", "Stock Name", "Price ($)");
    printf("------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-30s %.2f\n", stocks[i].name, stocks[i].price);
    }
}