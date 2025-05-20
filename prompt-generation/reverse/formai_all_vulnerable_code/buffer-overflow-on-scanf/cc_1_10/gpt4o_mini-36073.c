//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Stock;

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock list is full!\n");
        return;
    }
    
    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*count].price);
    
    printf("Stock added: %s - $%.2f\n", stocks[*count].name, stocks[*count].price);
    (*count)++;
}

void updateStock(Stock stocks[], int count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Enter new price for %s: ", stocks[i].name);
            scanf("%f", &stocks[i].price);
            printf("Updated %s to $%.2f\n", stocks[i].name, stocks[i].price);
            return;
        }
    }
    
    printf("Stock %s not found!\n", name);
}

void displayStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks to display.\n");
        return;
    }
    
    printf("Current Stocks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - $%.2f\n", stocks[i].name, stocks[i].price);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nStock Market Tracker Menu:\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. Display Stocks\n");
        printf("4. Exit\n");
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
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}